/*************************************************************************
【文件名】teacherprocess.h
【功能模块和目的】教师业务流程类声明
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-12
【版权信息】开发者范静涛(fanjingtao@tsinghua.edu.cn)声明放弃任何版权诉求，任何使用者可做出任何修改、用于任何目的
【更改记录】
    2020-05-19 由范静涛修改为从QObject继承，并添加了使用信号更新界面的机制
	2020/6/18 由李永健增加对于问题和答案类的适配
	2020/6/19 由李永健增加对于随机提问的适配
*************************************************************************/
#ifndef TEACHERPROCESS_H
#define TEACHERPROCESS_H

#include <QObject>
#include "Server.h"
#include "Message.h"
#include <mutex>
#include "audio.h"
#include <vector>
#include <utility>
#include <QComboBox>
#include <QLineEdit>

/*************************************************************************
TeacherProcess
【功能】学生上课业务流程类
【接口说明】
    构造函数TeacherProcess
    析构函数~TeacherProcess
    函数BeginClass上课
    函数EndClass下课
    函数StartScreenShare开始屏幕共享
    函数StopScreenShare停止屏幕共享
    函数StartVoiceShare开始语音直播
    函数StopVoiceShare停止语音直播
    函数SendStrChat群发文本信息
	函数SendQuestion(const QString& MyQuestion, const QString& OptionA,
		const QString& OptionB, const QString& OptionC, const QString& OptionD,
		QuestionType Type)发送题目
	函数GetAnswer()收题并获取答题信息
	函数GetTimeCount()获取学生专注信息
	函数RandCall()随机提问学生
	函数StopRandCall()停止随机提问
    函数bool& IsInClass;
    函数bool& IsScreenSharing;
    函数bool& IsVoiceSharing;
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-12
【更改记录】
    2020-05-19 由范静涛修改为从QObject继承，并添加了使用信号更新界面的机制
	2020/6/18 由李永健增加对于问题和答案类的适配
	2020/6/19 由李永健增加对于随机提问的适配
*************************************************************************/
class TeacherProcess : public QObject{
    Q_OBJECT
public:
    //构造函数
    explicit TeacherProcess(QObject* Parent = nullptr);

    //析构函数
    ~TeacherProcess();

    //禁用拷贝构造函数
    TeacherProcess(const TeacherProcess&) = delete;

    //禁用赋值运算符
    TeacherProcess& operator=(const TeacherProcess&) = delete;

    //上课
    bool BeginClass();

    //下课
    bool EndClass();

    //开始屏幕共享
    bool StartScreenShare();

    //停止屏幕共享
    bool StopScreenShare();

    //开始语音直播
    bool StartVoiceShare();

    //停止语音直播
    bool StopVoiceShare();

    //群发文字
    bool SendStrChat(const QString& ChatStr);

	//发送题目
	void SendQuestion(const QString& MyQuestion, const QString& OptionA,
		const QString& OptionB, const QString& OptionC, const QString& OptionD,
		QuestionType Type);

	//收题
	vector<pair<string, Answer> > GetAnswer();

	//获取学生专注信息
	vector<pair<string, const TimeCount> > GetTimeCount() const;

	//发送语音提问消息
	bool RandCall();

	//停止语音提问
	bool StopRandCall();

    //在不在上课
    const bool& IsInClass;

    //在不在共享屏幕
    const bool& IsScreenSharing;

    //在不在语音直播
    const bool& IsVoiceSharing;


signals:
    void ClassBegined();
    void ClassEnded();
    void RecvBeginClass();
    void RecvStudentLogin(QString Name);
    void RecvStudentLogout(QString Name);
    void RecvChat(QString Msg);
	//被选择的学生的姓名
	void SelectedStudent(QString Name);
private:

    //上线一个学生
    bool OnlineStudent(const pair<unsigned int, Message>& Pair);

    //下线一个学生
    void OffLineStudent(unsigned int Idx);

    //在不在上课
    bool m_bIsInClass;

    //服务端
    Server* m_pServer;

    //音频播放和录制对象
    Audio* m_pVoice;

    //屏幕共享线程函数
    static DWORD WINAPI ScreenShareThread(LPVOID lpParameter);

    //屏幕共享线程句柄
    HANDLE m_hScreenShareThread;

    //是否正在屏幕共享
    bool m_bIsScreenSharing;

    //语音直播线程函数
    static DWORD WINAPI VoiceShareThread(LPVOID lpParameter);

    //语音直播线程句柄
    HANDLE m_hVoiceShareThread;

    //是否正在语音直播
    bool m_bIsVoiceSharing;

    //对收到的消息进行执行的线程函数
    static DWORD WINAPI MsgReceiveThread(LPVOID lpParameter);

    //对收到的消息进行执行的线程句柄
    HANDLE m_hMsgReceiveThread;

    //保存用户名的数组*
    vector<string> m_Names;

    //保存密码的数组*
    vector<string> m_Passwords;

    //保存连接号的数组*
    vector<unsigned int> m_ConnectionIdx;

	//保存学生的答案信息的数组*
	vector<Answer> m_Answers;
	
	//避免存取答案时发生访问冲突的锁
	mutex m_AnswerLock;

	//随机提问的连接号
	unsigned int m_uRandCallIdx;

	//是否在等待答案
	bool m_bRecAnswer;

    //*标注星号，表示同一个学生的用户名、密码、连接号在三个数组中下标一致
};

#endif // TEACHERPROCESS_H
