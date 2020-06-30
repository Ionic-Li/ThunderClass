#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "LoginWindow.h"
#include <QtWidgets/QMessageBox>
#include "QStrAndStr.h"

LoginWindow::LoginWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setFixedSize(577, 432);
	setWindowTitle(tr("雷课堂登录"));
	ui.PassWordLineEdit->setEchoMode(QLineEdit::Password);//将密码变为点
	connect(ui.LoginButton, SIGNAL(clicked()), this, SLOT(OnClicked()));//将确定按钮的点击操作和Oncliced函数连接
	connect(ui.ExitButton, SIGNAL(clicked()), this, SLOT(ExitClicked()));//将取消按钮的点击操作和close函数连接
}

LoginWindow::~LoginWindow()
{

}

void LoginWindow::ExitClicked()
{
	close();
	exit(0);
}

void LoginWindow::OnClicked()
{
	TeacherWindow* pTeacherWindow;
	StudentWindow* pStudentWindow;
	AdminWindow* pAdminWindow;
	UserType eLoginRe = m_CProcess.Result(ui.UserNameLineEdit->text(), 
		ui.PassWordLineEdit->text());//判断输入的用户名密码是否匹配
	switch (eLoginRe)
	{
	case NONE :
		if (m_CProcess.WrongTime < 3)//如果输入错误次数小于3就发出警告
		{
			string sMessage("用户名或密码错误,还有");
			sMessage += to_string(3 - m_CProcess.WrongTime) + "次机会";
			QMessageBox::warning(this, tr("警告!"), tr(sMessage.c_str()), QMessageBox::Yes);
			break;
		}
		else//如果输错三次就退出
		{
			exit(0);
		}
	case ADMIN :
		this->setWindowOpacity(0.0);
		pAdminWindow = new AdminWindow(this);
		pAdminWindow->exec();
		pAdminWindow->setWindowModality(Qt::ApplicationModal);
		this->setWindowOpacity(1.0);
		delete pAdminWindow;
		pAdminWindow = nullptr;
		break;
	case TEACHER :
		this->setWindowOpacity(0.0);
		pTeacherWindow = new TeacherWindow(this);
		pTeacherWindow->setWindowTitle("教师 " + StrToQStr(User::GetLoginedUser()->GetName()));
		pTeacherWindow->exec();
		this->setWindowOpacity(1.0);
		delete  pTeacherWindow;
		pTeacherWindow = nullptr;
		break;
	default:
		this->setWindowOpacity(0.0);
		pStudentWindow = new StudentWindow(this);
		pStudentWindow->exec();
		this->setWindowOpacity(1.0);
		delete pStudentWindow;
		pStudentWindow = nullptr;
		break;
	}
}