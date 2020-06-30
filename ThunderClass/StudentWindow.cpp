#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "StudentWindow.h"
#include "ui_StudentWindow.h"
#include "QStrAndStr.h"
#include <QImage>
#include <QPixmap>
#include <QMessageBox>

StudentWindow::StudentWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
    m_pProc = new StudentProcess(this);
    //建立信号和槽的连接关系
    //一定要在m_pProc构造后才能建立
    //connect是建立联系，而非调用槽函数
    connect(m_pProc, SIGNAL(ClassEntered()), this, SLOT(ClassEntered()));
    connect(m_pProc, SIGNAL(ClassExited()), this, SLOT(ClassExited()));
    connect(m_pProc, SIGNAL(RecvChat(QString)), this, SLOT(RecvChat(QString)));
    connect(m_pProc, SIGNAL(RecvScreen(QImage)), this, SLOT(RecvScreen(QImage)));
	connect(m_pProc, SIGNAL(RecvQuestion(QString)), this, SLOT(StartAnswer(QString)));
	connect(m_pProc, SIGNAL(RecvStopAnswer()), this, SLOT(HideQuestion()));
	connect(m_pProc, SIGNAL(RecvOpenAudio()), this, SLOT(ShareVoice()));
	connect(m_pProc, SIGNAL(RecvCloseAudio()), this, SLOT(StopVoiceShare()));
	connect(m_pProc, SIGNAL(ConnectionFail()), this, SLOT(FailToConnect()));
	connect(ui->btnSendAns, SIGNAL(clicked()), this, SLOT(SendAnswer()));
    m_pTimer = new QTimer();
    m_pTimer->setInterval(200);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(TimerEvent()));
    m_pTimer->start();

	m_pAnswerTimer = new QTimer();
	m_pAnswerTimer->setInterval(200);//设置答题计时的计时器
	connect(m_pAnswerTimer, SIGNAL(timeout()), this, SLOT(ShowAnswerTime()));
	m_pAnswerTimer->setSingleShot(false);//非单次触发

	//计时器的设置
	ui->TimeDisplay->setDigitCount(8);//设置信号显示
	ui->TimeDisplay->setMode(QLCDNumber::Dec);
	ui->TimeDisplay->setSegmentStyle(QLCDNumber::Flat);
	ui->TimeDisplay->display(QString::number(0));//未发题就记0
	m_BeginTime = QTime::currentTime();

	//ui->lblSharedScreen->setScaledContents(true);//让Label自适应大小
    //只显示关闭窗口按钮，没有？按钮
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    //设定控件是否可用
    UpdateControlEnabled(false);
	
	QWidget::installEventFilter(this);//为此窗口安装过滤器
	HideQuestion();//隐藏答题区
	QRegExp TheExp("[A-D]+$");//限制输入A到D这四个字母
	ui->AnswerEdit->setValidator(new QRegExpValidator(TheExp, ui->AnswerEdit));

	QRegExp IpExp("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
	ui->edtIP->setValidator(new QRegExpValidator(IpExp, ui->edtIP));

	ui->HintLabel->hide();
}

StudentWindow::~StudentWindow()
{
    m_pTimer->stop();
    disconnect(m_pTimer, SIGNAL(timeout()), this, SLOT(TimerEvent()));
    delete m_pTimer;
    m_pTimer = nullptr;
    //先disconnected，再释放业务流程类
    disconnect(m_pProc, SIGNAL(ClassEntered()), this, SLOT(ClassEntered()));
    disconnect(m_pProc, SIGNAL(ClassExited()), this, SLOT(ClassExited()));
    disconnect(m_pProc, SIGNAL(RecvChat(QString)), this, SLOT(RecvChat(QString)));
    disconnect(m_pProc, SIGNAL(RecvScreen(QImage)), this, SLOT(RecvScreen(QImage)));
	disconnect(m_pProc, SIGNAL(RecvQuestion(QString)), this, SLOT(StartAnswer(QString)));
	disconnect(m_pProc, SIGNAL(RecvStopAnswer()), this, SLOT(HideQuestion()));
	disconnect(m_pProc, SIGNAL(RecvOpenAudio()), this, SLOT(ShareVoice()));
	disconnect(m_pProc, SIGNAL(RecvCloseAudio()), this, SLOT(StopVoiceShare()));
	disconnect(m_pProc, SIGNAL(ConnectionFail()), this, SLOT(FailToConnect()));
    delete m_pProc;
    m_pProc = nullptr;
    delete ui;
}

void StudentWindow::UpdateControlEnabled(bool IsInClass) {
    //非上课状态，清空共享屏幕显示、清空聊天记录、清空聊天输入文本框
    if (!IsInClass) {
        ui->lblSharedScreen->clear();
        ui->cmbChatList->clear();
        ui->edtChat->clear();
    }
    //IP输入文本框在非上课状态可用
    ui->edtIP->setEnabled(!IsInClass);
    //进入课堂按钮在非上课状态可用
    ui->btnEnterClass->setEnabled(!IsInClass);
    //退出课堂按钮在上课状态可用
    ui->btnExitClass->setEnabled(IsInClass);
    //聊天输入框在上课状态可用
    ui->edtChat->setEnabled(IsInClass);
    //发送按钮在上课状态可用
    ui->btnSend->setEnabled(IsInClass);
}

void StudentWindow::on_btnEnterClass_clicked() {
    //IP不为空在能进入课堂
    if (!ui->edtIP->text().isEmpty()) {
        //更新界面控件状态为非上课状态
        UpdateControlEnabled(false);
		ui->HintLabel->hide();
        //临时锁死IP输入框
        ui->edtIP->setEnabled(false);
        //临时锁死退出课堂按钮
        ui->btnExitClass->setEnabled(false);
        //尝试进入课堂
        m_pProc->EnterClass(ui->edtIP->text());
    }
}

void StudentWindow::on_btnExitClass_clicked(){
    m_pProc->ExitClass();
}

void StudentWindow::on_btnSend_clicked(){
    //聊天输入框有文字才能发送
    if (!ui->edtChat->text().isEmpty()) {
        //发送结束则清空聊天输入框
        if (m_pProc->Send(ui->edtChat->text())) {
            ui->edtChat->clear();
        }
    }
}

void StudentWindow::closeEvent (QCloseEvent* e) {
    //上课中禁止关闭窗口
    if (m_pProc->IsInClass) {
        e->ignore();
    }
}

void StudentWindow::TimerEvent() {
    //定时更新窗口标题
    if (m_pProc->IsInClass) {
        //上课中，窗口是激活状态
        if(this->isActiveWindow()) {
            this->setWindowTitle("学生 " + StrToQStr(User::GetLoginedUser()->GetName()) +  " 在线");
        }
        //上课中，窗口不是激活状态
        else {
            this->setWindowTitle("学生 " + StrToQStr(User::GetLoginedUser()->GetName()) +  " 离开");
        }
    }
    else {
        //非上课
        this->setWindowTitle("学生 " + StrToQStr(User::GetLoginedUser()->GetName()) +  " 未在课堂中");
    }
}

//进入课堂信号
void StudentWindow::ClassEntered(){
	if (this->isActiveWindow()) {
		m_pProc->SetTimeFocused(true);
	}
	//上课中，窗口不是激活状态
	else {
		m_pProc->SetTimeFocused(false);
	}
	ui->HintLabel->show();
	ui->HintLabel->setText(tr("录音设备已关闭"));
    UpdateControlEnabled(true);
}

void StudentWindow::FailToConnect()
{
	QMessageBox::information(this, tr("信息"), tr("无法连接到IP"), QMessageBox::Yes);
	ClassExited();
}

//退出课堂信号
void StudentWindow::ClassExited(){
	HideQuestion();//退出课堂不许再答题
    UpdateControlEnabled(false);
	ui->HintLabel->hide();
	ui->lblSharedScreen->clear();
}

//收到文字消息信号
void StudentWindow::RecvChat(QString Msg){
    ui->cmbChatList->insertItem(0, Msg);
    ui->cmbChatList->setCurrentIndex(0);
}

//收到屏幕共享消息信号
void StudentWindow::RecvScreen(QImage Img){
    ////收到的图像尺寸和滚动区尺寸不一致，则调整滚动区尺寸
    //if (ui->scrollAreaWidgetContents->minimumSize() != Img.size()) {
    //    ui->scrollAreaWidgetContents->setMinimumSize(Img.size());
    //}
    ////收到的图像尺寸和Label尺寸不一致，则调整Label尺寸
    //if (ui->lblSharedScreen->minimumSize() != Img.size()) {
    //    ui->lblSharedScreen->setMinimumSize(Img.size());
    //}
    //刷新Label显示

	QPixmap FitPixmap = QPixmap::fromImage(Img).scaled(ui->lblSharedScreen->size(),
		Qt::KeepAspectRatio);
    ui->lblSharedScreen->setPixmap(FitPixmap);
}

//记录专注时长的事件过滤器
bool StudentWindow::eventFilter(QObject* Target, QEvent* Ev)
{
	if (this == Target)
	{
		//窗口不在焦点上
		if (QEvent::WindowDeactivate == Ev->type())
		{
			if (m_pProc->IsInClass)//在上课状态
			{
				m_pProc->SetTimeFocused(false);
			}
			return true;
		}
		else if(QEvent::WindowActivate == Ev->type())//窗口在焦点上
		{
			if (m_pProc->IsInClass)//在上课状态
			{
				m_pProc->SetTimeFocused(true);
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//隐藏答题区域
void StudentWindow::HideQuestion()
{
	ui->AnswerEdit->hide();
	ui->AnswerEdit->setReadOnly(false);
	ui->Enterlabel->hide();
	ui->QuesText->hide();
	ui->TypeLabel->hide();
	ui->btnSendAns->hide();
	ui->TimeDisplay->display(0);
	ui->TimeDisplay->hide();
	m_pAnswerTimer->stop();
	UpdateControlEnabled(m_pProc->IsInClass);
}

void StudentWindow::StartAnswer(QString Ques)
{
	//初始化答题区
	ui->AnswerEdit->clear();
	ui->btnSendAns->setEnabled(true);
	ui->QuesText->setText(Ques);
	switch (m_pProc->QuesType)
	{
	case SING_CH :
		ui->TypeLabel->setText(tr("单选题"));
		ui->AnswerEdit->setMaxLength(1);//只允许输入一个字母
		break;
	case MULTI_CH :
		ui->TypeLabel->setText(tr("多选题"));
		ui->AnswerEdit->setMaxLength(4);//只允许输入四个字母
		break;
	}
	m_BeginTime = QTime::currentTime();
	m_pAnswerTimer->start();

	ui->AnswerEdit->show();
	ui->Enterlabel->show();
	ui->QuesText->show();
	ui->TypeLabel->show();
	ui->btnSendAns->show();
	ui->TimeDisplay->show();
	ui->btnExitClass->setEnabled(false);//答题时禁止退出课堂
}

void StudentWindow::ShowAnswerTime()
{
	QTime TimeCount(0, 0, 0);
	TimeCount = TimeCount.addMSecs(m_BeginTime.msecsTo(QTime::currentTime()));

	/*QByteArray ba = TimeCount.toString("hh:mm:ss").toLatin1();
	WCHAR test[435];
	memset(test, 0, sizeof(test));
	MultiByteToWideChar(CP_ACP, 0, ba.data(), strlen(ba.data()) + 1, test,
		sizeof(test) / sizeof(test[0]));
	OutputDebugString(test);*/
	ui->TimeDisplay->display(TimeCount.toString("hh:mm:ss"));//显示时间
}

void StudentWindow::SendAnswer()
{
	if (ui->AnswerEdit->text().isEmpty())
	{
		QMessageBox::warning(this, tr("警告!"), tr("没有选择选项"), QMessageBox::Yes);
		return;
	}
	m_pProc->SendAnswer(ui->AnswerEdit->text(), m_BeginTime.msecsTo(QTime::currentTime()));//发送答题信息
	ui->btnSendAns->setEnabled(false);
	ui->AnswerEdit->setReadOnly(true);
	m_pAnswerTimer->stop();
}

void StudentWindow::ShareVoice()
{
	ui->HintLabel->setText(tr("录音设备已打开"));
	ui->btnExitClass->setEnabled(false);//不许退出语音共享
}

void StudentWindow::StopVoiceShare()
{
	ui->HintLabel->setText(tr("录音设备已关闭"));
	UpdateControlEnabled(m_pProc->IsInClass);
}