#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "QuestionWindow.h"

QuestionWindow::QuestionWindow(TeacherProcess* pProc, QWidget *parent)
	: m_pProc(pProc), QDialog(parent)
{
	ui.setupUi(this);
	setFixedSize(this->width(), this->height());    // 禁止拖动窗口大小
	setWindowTitle(tr("发送题目"));
	ui.QuestionEdit->setText(tr("请在此编辑题目"));
	ui.ALineEdit->setText(tr("请在此编辑A选项"));
	ui.BLineEdit->setText(tr("请在此编辑B选项"));
	ui.CLineEdit->setText(tr("请在此编辑C选项"));
	ui.DLineEdit->setText(tr("请在此编辑D选项"));
	ui.SingleButton->setChecked(true);//默认选中单选
	ui.MultipleButton->setChecked(false);
	ui.SendButton->setFocus();//设置发送按钮为默认
	ui.SendButton->setDefault(true);
	connect(ui.SendButton, SIGNAL(clicked()), this, SLOT(SendQues()));
	connect(ui.StopButton, SIGNAL(clicked()), this, SLOT(EndQues()));
	m_pTimer = new QTimer();
	connect(m_pTimer, SIGNAL(timeout()), this, SLOT(ShowTime()));
	m_pTimer->setSingleShot(false);
	m_pTimer->setInterval(200);

	ui.TimeDisplay->setDigitCount(8);//设置信号显示
	ui.TimeDisplay->setMode(QLCDNumber::Dec);
	ui.TimeDisplay->setSegmentStyle(QLCDNumber::Flat);
	ui.TimeDisplay->display(QString::number(0));//未发题就记0
	m_bWaiting = false;//未在等待收题
	ui.StopButton->setEnabled(false);//不允许收题
}

QuestionWindow::~QuestionWindow()
{
}

void QuestionWindow::SendQues()
{
	QuestionType Type;
	if (ui.SingleButton->isChecked())
	{
		Type = SING_CH;
	}
	else
	{
		Type = MULTI_CH;
	}
	m_pProc->SendQuestion(ui.QuestionEdit->toPlainText(),
		ui.ALineEdit->text(),
		ui.BLineEdit->text(),
		ui.CLineEdit->text(),
		ui.DLineEdit->text(),
		Type
	);
	m_BeginTime = QTime::currentTime();//设置开始时间
	m_pTimer->start();
	m_bWaiting = true;//开始等待，不可关闭题目
	ui.SendButton->setEnabled(false);//不可再次发题
	ui.QuestionEdit->setReadOnly(true);//不可改题
	ui.ALineEdit->setReadOnly(true);
	ui.BLineEdit->setReadOnly(true);
	ui.CLineEdit->setReadOnly(true);
	ui.DLineEdit->setReadOnly(true);
	ui.SingleButton->setEnabled(false);
	ui.MultipleButton->setEnabled(false);
	ui.StopButton->setEnabled(true);//允许收题
}

void QuestionWindow::EndQues()
{
	m_bWaiting = false;
	m_pTimer->stop();//不再计时
	vector<pair<string, Answer> > AnswerData = m_pProc->GetAnswer();//收题
	AnswerResWindow* pAnswerWin = new AnswerResWindow(AnswerData);//显示结果
	pAnswerWin->exec();
	delete pAnswerWin;
	delete m_pTimer;
	close();//关闭发题窗口
}

void QuestionWindow::ShowTime()
{
	QTime TimeCount(0, 0, 0);
	TimeCount = TimeCount.addMSecs(m_BeginTime.msecsTo(QTime::currentTime()));
	ui.TimeDisplay->display(TimeCount.toString("hh:mm:ss"));//显示时间
}

void QuestionWindow::closeEvent(QCloseEvent * Ev)
{
	if (m_bWaiting)
	{
		Ev->ignore();
	}
}
