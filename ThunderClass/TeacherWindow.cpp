#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "TeacherWindow.h"
#include "ui_TeacherWindow.h"
#include <QGuiApplication>
#include <QScreen>
#include <QSize>
#include "StudentDataWindow.h"
#include "QuestionWindow.h"
#include <QMessageBox>

TeacherWindow::TeacherWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherWindow){
    ui->setupUi(this);
    m_pProc = new TeacherProcess(this);

	this->setFixedHeight(this->height());

    //建立信号和槽的连接关系
    //一定要在m_pProc构造后才能建立
    //connect是建立联系，而非调用槽函数
    connect(m_pProc, SIGNAL(ClassBegined()), this, SLOT(ClassBegined()));
    connect(m_pProc, SIGNAL(ClassEnded()), this, SLOT(ClassEnded()));
    connect(m_pProc, SIGNAL(RecvStudentLogin(QString)), this, SLOT(RecvStudentLogin(QString)));
    connect(m_pProc, SIGNAL(RecvStudentLogout(QString)), this, SLOT(RecvStudentLogout(QString)));
    connect(m_pProc, SIGNAL(RecvChat(QString)), this, SLOT(RecvChat(QString)));
	connect(m_pProc, SIGNAL(SelectedStudent(QString)), this, SLOT(ShowRandCallStudent(QString)));
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
	UpdateControlEnabled(false);
}

TeacherWindow::~TeacherWindow(){
    //先disconnected，再释放业务流程类
    disconnect(m_pProc, SIGNAL(ClassBegined()), this, SLOT(ClassBegined()));
    disconnect(m_pProc, SIGNAL(ClassEnded()), this, SLOT(ClassEnded()));
    disconnect(m_pProc, SIGNAL(RecvStudentLogin(QString)), this, SLOT(RecvStudentLogin(QString)));
    disconnect(m_pProc, SIGNAL(RecvStudentLogout(QString)), this, SLOT(RecvStudentLogout(QString)));
    disconnect(m_pProc, SIGNAL(RecvChat(QString)), this, SLOT(RecvChat(QString)));
	disconnect(m_pProc, SIGNAL(SelectedStudent(QString)), this, SLOT(ShowRandCallStudent(QString)));
    delete m_pProc;
    delete ui;
}

void TeacherWindow::UpdateControlEnabled(bool IsInClass){
    if (!IsInClass) {
        ui->cmbStudent->clear();
        ui->cmbChatList->clear();
        ui->edtChat->clear();
        ui->ckbScreenShare->setChecked(false);
        ui->ckbVoiceShare->setChecked(false);
    }
    ui->btnBeginClass->setEnabled(!IsInClass);
    ui->btnEndClass->setEnabled(IsInClass);
    ui->btnSend->setEnabled(IsInClass);
    ui->ckbVoiceShare->setEnabled(IsInClass);
    ui->ckbScreenShare->setEnabled(IsInClass);
	ui->btnSendQues->setEnabled(IsInClass);
	ui->btnRandCall->setEnabled(IsInClass);
    ui->edtChat->setEnabled(IsInClass);
}

void TeacherWindow::showEvent(QShowEvent* e) {
    int iWidth = QGuiApplication::screens()[0]->size().width();
    this->move((iWidth - this->width()) / 2, 0);
    e->accept();
}

void TeacherWindow::closeEvent (QCloseEvent* e) {
    if (m_pProc->IsInClass) {
        e->ignore();
    }
}

void TeacherWindow::on_btnBeginClass_clicked() {
    if (m_pProc->BeginClass()) {
        ui->cmbStudent->clear();
        ui->cmbChatList->clear();
    }
}

void TeacherWindow::on_ckbScreenShare_clicked()
{
    if (ui->ckbScreenShare->isChecked()) {
        ui->ckbScreenShare->setChecked(m_pProc->StartScreenShare());
    }
    else{
        ui->ckbScreenShare->setChecked(m_pProc->StopScreenShare());
    }
}

void TeacherWindow::on_ckbVoiceShare_clicked()
{
    if (ui->ckbVoiceShare->isChecked()) {
        ui->ckbVoiceShare->setChecked(m_pProc->StartVoiceShare());
    }
    else{
        ui->ckbVoiceShare->setChecked(m_pProc->StopVoiceShare());
    }
}

void TeacherWindow::on_btnEndClass_clicked(){
    m_pProc->EndClass();
}

void TeacherWindow::on_btnSend_clicked(){
    if (m_pProc->SendStrChat(ui->edtChat->text())) {
        ui->edtChat->clear();
    }
}

void TeacherWindow::on_btnSendQues_clicked()
{
	QuestionWindow* pQues = new QuestionWindow(m_pProc);
	pQues->exec();
	delete pQues;
}

void TeacherWindow::on_btnRandCall_clicked()
{
	if (ui->btnRandCall->text() == "随机提问")
	{
		if (m_pProc->RandCall())//开始随机提问
		{
			ui->btnRandCall->setText(tr("停止提问"));
			ui->btnEndClass->setEnabled(false);//提问时禁止退出
		}
	}
	else
	{
		if (m_pProc->StopRandCall())//结束随机提问
		{
			ui->btnRandCall->setText(tr("随机提问"));
			UpdateControlEnabled(m_pProc->IsInClass);
		}
	}
}

void TeacherWindow::ClassBegined(){
	ui->ckbVoiceShare->setChecked(m_pProc->StartVoiceShare());
    UpdateControlEnabled(true);
}

void TeacherWindow::ClassEnded() {
	StudentDataWindow* pDataWindow = new StudentDataWindow(m_pProc, this);
	pDataWindow->exec();
	delete pDataWindow;
    UpdateControlEnabled(false);
}

void TeacherWindow::RecvStudentLogin(QString Name){
    int idx = ui->cmbStudent->findText(Name);
    if (idx == -1) {
        ui->cmbStudent->insertItem(0, Name);
        idx  = 0;
    }
    ui->cmbStudent->setCurrentIndex(idx);
}

void TeacherWindow::RecvStudentLogout(QString Name) {
    int idx = ui->cmbStudent->findText(Name);
    if (idx != -1) {
        ui->cmbStudent->removeItem(idx);
    }
}

void TeacherWindow::RecvChat(QString Msg){
    ui->cmbChatList->insertItem(0, Msg);
    ui->cmbChatList->setCurrentIndex(0);
}

void TeacherWindow::ShowRandCallStudent(QString Name)
{
	QMessageBox::information(this, tr("信息"), "正在回答问题的学生是 : " + Name, QMessageBox::Yes);
}
