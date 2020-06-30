#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QDialog>
#include <QCloseEvent>
#include <QTimer>
#include <QButtonGroup>
#include <QTime>
#include <QComboBox>
#include "studentprocess.h"

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = nullptr);
    ~StudentWindow();
    void closeEvent (QCloseEvent* e) override;
    void UpdateControlEnabled(bool IsInClass);
private slots:
    void on_btnEnterClass_clicked();
    void on_btnExitClass_clicked();
    void on_btnSend_clicked();
    void TimerEvent();
    //进入课堂信号
    void ClassEntered();
	//连接Ip失败
	void FailToConnect();
    //退出课堂信号
    void ClassExited();
    //收到文字消息信号
    void RecvChat(QString Msg);
    //收到屏幕共享消息信号
    void RecvScreen(QImage Img);
	//时间过滤函数
	bool eventFilter(QObject* Target, QEvent* Ev);
	//隐藏答题区
	void HideQuestion();
	//开始答题
	void StartAnswer(QString Ques);
	//刷新答题计时
	void ShowAnswerTime();
	//发送答案
	void SendAnswer();
	//开始语音答题
	void ShareVoice();
	//结束语音答题
	void StopVoiceShare();
private:

    Ui::StudentWindow *ui;
    StudentProcess* m_pProc;
    QTimer* m_pTimer;
	QTimer* m_pAnswerTimer;
	QTime m_BeginTime;
};

#endif // STUDENTWINDOW_H
