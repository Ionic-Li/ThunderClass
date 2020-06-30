/*************************************************************************
【文件名】studentprocess.h
【功能模块和目的】学生业务流程类声明
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-12
【版权信息】开发者范静涛(fanjingtao@tsinghua.edu.cn)声明放弃任何版权诉求，任何使用者可做出任何修改、用于任何目的
【更改记录】
    2020-05-19 由范静涛修改为从QObject继承，用信号实现界面更新
	2020/6/17 由李永健增加时长统计
	2020/6/18 由李永健增加对于答题和随机提问的适配
	2020/6/20 由李永健增加注释
*************************************************************************/
#ifndef STUDENTPROCESS_H
#define STUDENTPROCESS_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QComboBox>
#include <QScrollArea>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <string>
#include <mutex>
#include <ctime>
#include "client.h"
#include "Message.h"
#include "audio.h"
#include "user.h"
#include "TimeCount.h"
using namespace std;

/*************************************************************************
【类名】StudentProcess
【功能】学生上课业务流程类
【接口说明】
    构造函数StudentProcess
    析构函数~StudentProcess
    函数EnterClass进入指定IP的课堂
    函数ExitClass退出课堂
    函数Send向教师发送文本消息
	函数SetTimeFocused(bool bActive)设置专注时长
	函数SendAnswer(const QString& AnswerText, int Time)发送答案
	函数StartAnswer(Question Ques)开始答题
	函数StartVoiceShare()开始语音回答问题
	函数StopVoiceShare()停止语音回答问题
    常引用数据成员IsInClass表示是否在上课
	常引用数据成员QuestionType显示问题类型
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-12
【更改记录】
    2020-05-19 由范静涛修改为从QObject继承，用信号实现界面更新
	2020/6/17 由李永健增加时长统计
	2020/6/18 由李永健增加对于答题和随机提问的适配
	2020/6/20 由李永健增加注释
*************************************************************************/
class StudentProcess : public QObject{
    Q_OBJECT
public:
    //构造函数
    explicit StudentProcess(QObject* Parent = nullptr);

    //析构函数
    ~StudentProcess();

    //禁用拷贝构造函数
    StudentProcess(const StudentProcess&) = delete;

    //禁用赋值运算符
    StudentProcess& operator=(const StudentProcess&) = delete;

    //进入课堂
    bool EnterClass(const QString& IP);

    //退出课堂
    bool ExitClass();

    //发送文本消息给教师
    bool Send(const QString& Msg);

	//设置专注时间
	void SetTimeFocused(bool bActive);

	//发送答案
	bool SendAnswer(const QString& AnswerText, int Time);

	//开始答题
	void StartAnswer(Question Ques);

	//开始答题
	void StartVoiceShare();

	//结束答题
	void StopVoiceShare();

    //是否在上课
    const bool& IsInClass;

	const QuestionType& QuesType;

signals:
    //进入课堂信号
    void ClassEntered();
	//连接Ip失败信号
	void ConnectionFail();
    //退出课堂信号
    void ClassExited();
    //收到文字消息信号
    void RecvChat(QString Msg);
    //收到屏幕共享消息信号
    void RecvScreen(QImage Img);
	//发送题目到界面
	void RecvQuestion(QString Ques);
	//收到停止答题的消息
	void RecvStopAnswer();
	//收到语音答题消息
	void RecvOpenAudio();
	//收到停止语音答题消息
	void RecvCloseAudio();
private:
    //是否在上课
    bool m_bIsInClass;

    //Socket客户端对象指针
    Client* m_pClient;

    //音频播放和录制对象指针
    Audio* m_pVoice;

	//时间统计对象
	TimeCount m_CTimeCount;
	//开始上课时间
	clock_t m_lClassBgnTime;
	//开始专注时间
	clock_t m_lBgnFocusTime;

	//问题类型
	QuestionType m_eQuesType;

    //接收消息并处理消息的线程函数
    static DWORD WINAPI MsgReceiveThread(LPVOID lpParameter);

	//语音答题线程函数
	static DWORD WINAPI VoiceShareThread(LPVOID lpParameter);

	//语音答题线程句柄
	HANDLE m_hVoiceShareThread;

	//是否开启了语音答题
	bool m_bIsVoiceSharing;

    //对收到的消息进行执行的线程句柄
    HANDLE m_hMsgReceiveThread;
    Message m_RemoteLoginMsg;
};

#endif // STUDENTPROCESS_H
