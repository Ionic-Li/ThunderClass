/*************************************************************************
【文件名】studentprocess.cpp
【功能模块和目的】学生业务流程类定义
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-12
【版权信息】开发者范静涛(fanjingtao@tsinghua.edu.cn)声明放弃任何版权诉求，任何使用者可做出任何修改、用于任何目的
【更改记录】
    2020-05-19 由范静涛修改为从QObject继承，用信号实现界面更新
    2020-05-19 由范静涛增加了日志输出QDebug
	2020/6/15 由李永健增加头文件<WinSock2.h>
	2020/6/17 由李永健增加时长统计
	2020/6/19 由李永健增加了避免中文乱码的机制
	2020/6/19 由李永健增加对随机提问的适配
	2020/6/21 由李永健增加在发送重要消息前清空待发队列的功能
*************************************************************************/
#include "studentprocess.h"
#include <WinSock2.h>
#include <Windows.h>
#include "QStrAndStr.h"
#include <QDebug>

/*************************************************************************
【函数名称】StudentProcess::StudentProcess
【函数功能】构造函数
【参数】入口参数，父对象指针，默认nullptr
【返回值】构造函数不可有返回值
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-12
【更改记录】
    2020-05-19 由范静涛删除界面空间指针参数，用信号实现界面更新
    2020-05-19 由范静涛修正了未初始化消息接收处理线程句柄为nullptr的错误逻辑
	2020/6/19 由李永健增加对随机提问的适配
*************************************************************************/
StudentProcess::StudentProcess(QObject* Parent)
	: QObject(Parent), IsInClass(m_bIsInClass), QuesType(m_eQuesType)
{
    //准备一个用于远程登录的消息，包含自己的用户名和密码
    //GetLoginedUser获取的是本地登录的账户指针
    m_RemoteLoginMsg = User::GetLoginedUser()->ToMessage();
    //用私有成员保存界面控件指针
    //初始化内部状态
    m_bIsInClass = false;
    //新建socket客户端
    m_pClient = new Client();
    //新建音频播放对象
    m_pVoice = new Audio();
    //初始化消息接收处理线程句柄为空
    m_hMsgReceiveThread = nullptr;
	//初始化上课时间专注时间为0
	m_lClassBgnTime = 0;
	m_lBgnFocusTime = 0;

	m_eQuesType = SING_CH;

	m_bIsVoiceSharing = false;

    qDebug("SP: Created");
}

/*************************************************************************
【函数名称】StudentProcess::~StudentProcess
【函数功能】析构函数
【参数】无
【返回值】析构函数不可有返回值
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-12
【更改记录】
*************************************************************************/
StudentProcess::~StudentProcess() {
    //退出课堂
    ExitClass();
    //释放socket客户端和音频对象
    delete m_pClient;
    m_pClient = nullptr;
    delete m_pVoice;
    m_pVoice = nullptr;
    qDebug("SP: Destroyed");
}

/*************************************************************************
【函数名称】StudentProcess::EnterClass
【函数功能】进入课堂
【参数】入口参数，教师端IP地址
【返回值】true表示当前连接状态（是否在课堂里）
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-12
【更改记录】
    2020-05-19 由范静涛修改未用信号实现界面更新
	2020/6/19 由李永健增加对随机提问的适配
*************************************************************************/
bool StudentProcess::EnterClass(const QString& IP) {
    //如果已经进入课堂，则不执行任何操作
    if (m_bIsInClass) {
        return m_bIsInClass;
    }

    //客户端连接到服务器
    string IpStr = IP.toStdString();
	try
	{
		m_pClient->ConnectTo(IpStr, 7908);
	}
	catch (const std::exception&)
	{
		emit ConnectionFail();
		return false;
	}

    //开始计时
    qDebug() << "SP: trying to connect to server @ " << QString::fromStdString(IpStr);

    DWORD BeginTime = GetTickCount();
    DWORD EndTime = BeginTime;
    do {
        //更新当前时间
        EndTime = GetTickCount();
    //30秒内未连接，则继续循环
    }while(EndTime - BeginTime <= 30000 && !m_pClient->IsConnected);

    //连接失败，返回
    if (!m_pClient->IsConnected) {
        qDebug() << "SP: connect fail after " << EndTime - BeginTime << " ms";
        //发出“退出课堂信号”
        emit ConnectionFail();
        return false;
    }
    //更新为以进入课堂状态
    m_bIsInClass = true;
    //发出“进入课堂信号”
    qDebug() << "SP: connected after " << EndTime - BeginTime << " ms";
    emit ClassEntered();
	m_lClassBgnTime = clock();//设置开始上课时间
    //创建消息接收和处理线程
    m_hMsgReceiveThread = CreateThread(nullptr, 0, MsgReceiveThread, (LPVOID)this, 0, nullptr);
    if (m_hMsgReceiveThread == nullptr) {
        qDebug() << "SP: failed to create a MessageRecv&Process thread!";
        throw(runtime_error("Failed to create a MessageRecv&Process thread!"));
    }
    //第一时间向教师端发送登录用的用户名密码消息
    qDebug() << "SP: send ID & Password";
    m_pClient->Send(m_RemoteLoginMsg);
    //开始播放声音(如果从教师端收到了)
    m_pVoice->StartPlay();

	m_bIsVoiceSharing = false;//未在随机语音提问

    return m_bIsInClass;
}

/*************************************************************************
【函数名称】StudentProcess::ExitClass
【函数功能】退出课堂
【参数】无
【返回值】true表示当前连接状态（是否在课堂里）
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-12
【更改记录】
    2020-05-19 由范静涛修改未用信号实现界面更新
	2020/6/17 由李永健增加时长统计发送
	2020/6/19 由李永健增加对随机提问的适配
*************************************************************************/
bool StudentProcess::ExitClass() {
    //如果未在课堂中，检查是否消息接收处理线程自主退出了
    if (!m_bIsInClass) {
        if(m_hMsgReceiveThread != nullptr) {
            qDebug() << "SP: clean MsgRecv&Process thread handle";
            CloseHandle(m_hMsgReceiveThread);
            m_hMsgReceiveThread = nullptr;
        }
        return m_bIsInClass;
    }
	//存储专注时长
	m_CTimeCount.SetTimeInClass(clock() - m_lClassBgnTime);
	SetTimeFocused(false);//不再专注，记录最后一次专注时长
	//断开前发送专注时长消息
	m_pClient->Clear();
	m_pClient->Send(Message::FromTimeCount(m_CTimeCount));
	m_CTimeCount = TimeCount();//清空
    //断开与服务器连接
    m_pClient->DisConnect();
    //停止播放音频
    m_pVoice->StopPlay();
	//停止语音提问
	StopVoiceShare();
    //清空待播放音频队列
    m_pVoice->Clear();
    //更新为未上课状态
    m_bIsInClass = false;
    //等待消息接收和处理线程结束
    qDebug() << "SP: wait MsgRecv&Process thread end";
    WaitForSingleObject(m_hMsgReceiveThread, 2000);
    //清理线程句柄
    qDebug() << "SP: clean MsgRecv&Process thread handle";
    CloseHandle(m_hMsgReceiveThread);
    m_hMsgReceiveThread = nullptr;
    //发出“退出课堂信号”
    emit ClassExited();
    //返回当前是否在课堂中
    return m_bIsInClass;
}

/*************************************************************************
【函数名称】StudentProcess::Send
【函数功能】向教师端发送文字消息
【参数】入口参数，QString字符串
【返回值】true表示当前连接状态（是否在课堂里）
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-12
【更改记录】2020/6/19 由李永健增加了避免中文乱码的机制
*************************************************************************/
bool StudentProcess::Send(const QString& Msg) {
    //不在课堂
    if (!m_bIsInClass) {
        return m_bIsInClass;
    }
    //未连接教师端
    if (!m_pClient->IsConnected) {
        return m_pClient->IsConnected;
    }
    //装换格式并发送
    qDebug() << "SP: send Message: " << Msg;
    string MsgStr = QStrToStr(Msg);
    return m_pClient->Send(Message::FromString(MsgStr));
}

/*************************************************************************
【函数名称】       SetTimeFocused
【函数功能】       设置在课堂专注时间
【参数】           是否在专注状态
【返回值】         无
【开发者及日期】   李永健 2020/6/17
【更改记录】       无
*************************************************************************/
void StudentProcess::SetTimeFocused(bool bActive)
{
	if (bActive)//如果窗口在焦点上
	{
		if (m_lBgnFocusTime == 0)//如果没有开始专注时间，就记当前时间为开始时间
		{
			m_lBgnFocusTime = clock();
		}
	}
	else//如果窗口不在焦点上
	{
		if (m_lBgnFocusTime != 0)//如果没有记录上一次的专注时间，就记录
		{
			m_CTimeCount = m_CTimeCount
				+ TimeCount(0, clock() - m_lBgnFocusTime);
			m_lBgnFocusTime = 0;//将开始专注时间置零
		}
	}
}

/*************************************************************************
【函数名称】       SendAnswer
【函数功能】       发送答案
【参数】           答案和时间
【返回值】         无
【开发者及日期】   李永健 2020/6/19
【更改记录】       2020/6/21 由李永健增加在发送重要消息前清空待发队列的功能
*************************************************************************/
bool StudentProcess::SendAnswer(const QString& AnswerText, int Time)
{
	if (!m_pClient->IsConnected) {
		return m_pClient->IsConnected;
	}
	//未连接教师端
	if (!m_pClient->IsConnected) {
		return m_pClient->IsConnected;
	}
	QString MyAnswer;
	for (int i = 0; i < 4; i++)
	{
		if (AnswerText.indexOf('A' + i) != -1)//如果选择了对应的选项
		{
			MyAnswer += 'A' + i;
		}
	}
	m_pClient->ClearToSend();//将消息队列清空，避免答案发送延迟
	return m_pClient->Send(Message::FromAnswer(Answer(MyAnswer.toStdString(), Time)));
}

/*************************************************************************
【函数名称】       StartAnswer
【函数功能】       开始答题
【参数】           题目
【返回值】         无
【开发者及日期】   李永健 2020/6/19
【更改记录】       无
*************************************************************************/
void StudentProcess::StartAnswer(Question Ques)
{
	QString TheQues = StrToQStr(Ques.sQuestion) + '\n';
	for (int i = 0; i < 4; i++)
	{
		TheQues += ('A' + i);
		TheQues += " : ";
		TheQues += StrToQStr(Ques.sOptions[i]);
		TheQues += '\n';
	}
	m_eQuesType = Ques.Type;
	emit RecvQuestion(TheQues);//发送题目到界面
}

/*************************************************************************
【函数名称】       StartVoiceShare
【函数功能】	   开始随机答题
【参数】		   无
【返回值】		   无
【开发者及日期】   2020/6/19 李永健（更改自process的同名函数）
【更改记录】
*************************************************************************/
void StudentProcess::StartVoiceShare() 
{
	if (!m_bIsInClass)//如果不在课堂
	{
		return;
	}
	if (m_bIsVoiceSharing)//如果已经在随机提问
	{
		return;
	}
	m_hVoiceShareThread = CreateThread(nullptr, 0, VoiceShareThread, (LPVOID)this, 0, nullptr);
	if (m_hVoiceShareThread == nullptr) {
		qDebug() << "TP: failed to create a new voice share thread";
		throw(runtime_error("Failed to create a new voice share thread!"));
	}
	m_pVoice->StartRec();
	m_bIsVoiceSharing = true;//开始随机答题
	qDebug() << "TP: start voice share";
	emit RecvOpenAudio();//发送开始答题信号
}

/*************************************************************************
【函数名称】       StopVoiceShare
【函数功能】	   停止语音直播
【参数】		   无
【返回值】		   无
【开发者及日期】   2020/6/19 李永健（更改自process的同名函数）
【更改记录】
*************************************************************************/
void StudentProcess::StopVoiceShare() {
	if (!m_bIsVoiceSharing) 
	{
		return ;
	}
	m_pVoice->StopRec();
	m_bIsVoiceSharing = false;
	qDebug() << "TP: wait for voice share thread exit";
	WaitForSingleObject(m_hVoiceShareThread, 2000);

	CloseHandle(m_hVoiceShareThread);
	m_hVoiceShareThread = nullptr;
	qDebug() << "TP: clean voice share thread handel";
	AudioFrame TempFrame;
	while (m_pVoice->RecordFramesCount() > 0) {
		m_pVoice->GetAndRemoveFirstRecorded(TempFrame);
	}
	emit RecvCloseAudio();//发出停止提问信号
	qDebug() << "TP: clean voice share queue";
	qDebug() << "TP: stop voice share";
}

/*************************************************************************
【函数名称】StudentProcess::MsgRecieveThread
【函数功能】接收并处理消息的线程函数
【参数】入口参数，表示线程所属的StudentProcess对象指针
【返回值】无意义
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-12
【更改记录】
    2020-05-19 由范静涛修改未用信号实现界面更新
    2020-05-19 由范静涛修正了jpg空间未释放的错误逻辑
	2020/6/19 由李永健增加了避免中文乱码的机制
	2020/6/19 由李永健增加对随机提问的适配
*************************************************************************/
DWORD WINAPI StudentProcess::MsgReceiveThread(LPVOID lpParameter) {
    //因为实参是StudentProcess*，所以可以强制类型装换
    StudentProcess* pProcess = (StudentProcess*)lpParameter;
    //用于接收的临时消息存储对象
    Message TempMessage;
    //接收到的消息的类型
    MessageType Type;
    //在课堂且通信中，始终执行循环
    while (pProcess->IsInClass && pProcess->m_pClient->IsConnected) {
        //有待处理消息，则放入TempMessage里
        if (pProcess->m_pClient->GetAndRemoveFirstRecvMsg(TempMessage)) {
            //获得消息类型
            Type = TempMessage.Type();
            //如果是文本信息消息，转换成为本对象，发出信号要求界面更新
            if (Type == MSG_STRING) {
                qDebug() << "SP: recieved chat message: " << StrToQStr(Message::ToString(TempMessage));
                emit pProcess->RecvChat(StrToQStr(Message::ToString(TempMessage)));
            }
            //如果是音频帧消息，放入待播放音频队列中
            else if (Type == MSG_AUDIO) {
                qDebug() << "SP: recieved audio frame message " << TempMessage.Size << " bytes";
                pProcess->m_pVoice->AppendFrameToPlay(Message::ToAudioFrame(TempMessage));
            }
            //如果是Jpg图像消息，界面后刷到界面上
            else if (Type == MSG_JPG) {
                char* pJpgData = nullptr;
                unsigned int JpgSize = 0;
                Message::ToJpgData(TempMessage, &pJpgData, &JpgSize);
                QImage qImg;
                qImg.loadFromData((unsigned char*)pJpgData, JpgSize, "jpg");
                qDebug() << "SP: recieved jpg message " << JpgSize << " bytes";
                //2020-05-19 修正了逻辑，之前没有释放开辟的空间
                delete [] pJpgData;
                //发出收到图像信号，要求界面更新
                emit pProcess->RecvScreen(qImg);
            }
			//如果是题目消息
			else if (Type == MSG_QUESTION)
			{
				pProcess->StartAnswer(Message::ToQuestion(TempMessage));//发送开始答题消息
			}
			//如果是结束答题消息
			else if (Type == MSG_ENDQUES)
			{
				emit pProcess->RecvStopAnswer();
			}
			//如果是开始语音答题的消息
			else if (Type == MSG_OPENAUDIO)
			{
				pProcess->StartVoiceShare();//开始语音答题
			}
			//如果是结束语音答题的消息
			else if (Type == MSG_CLOSAUDIO)
			{
				pProcess->StopVoiceShare();//停止语音答题
			}
			else if (Type == MSG_CLASSEND)
			{
				pProcess->ExitClass();
				break;
			}
            //如果是退出消息，跳出消息接收处理循环，相当退出课堂
            else if (Type == MSG_EXIT) {
                pProcess->m_bIsInClass = false;
                qDebug() << "SP: disconnected socket";
                //发出退出课堂信号
                emit pProcess->ClassExited();
                break;
            }
        }
    }
    return 0;
}

/*************************************************************************
【函数名称】       VoiceShareThread
【函数功能】	   语音线程函数
【参数】		   入口参数，TeacherProcess的指针
【返回值】		   无意义
【开发者及日期】   2020/6/19 李永健（更改自process的同名函数）
【更改记录】
*************************************************************************/
DWORD WINAPI StudentProcess::VoiceShareThread(LPVOID lpParameter) {
	StudentProcess* pProcess = (StudentProcess*)lpParameter;
	AudioFrame TempFrame;
	while (pProcess->m_bIsVoiceSharing && pProcess->m_bIsInClass) {
		//取出一个录制好的音频帧并发出
		if (pProcess->m_pVoice->GetAndRemoveFirstRecorded(TempFrame)) {
			qDebug() << "TP: remove an audio frame";
			//如果待发队列小于等于10，就发送一帧音频
			if (pProcess->m_pClient->GetToSendCount() <= 10)
			{
				pProcess->m_pClient->Send(Message::FromAudio(TempFrame));
			}
		}
	}
	return 0;
}