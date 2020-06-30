#include "AddUserWindow.h"
#include <QMessageBox>

AddUserWindow::AddUserWindow(AdminProcess* AdminData, QWidget *parent)
	: QDialog(parent), m_CAdminData(AdminData)
{
	ui.setupUi(this);
	setWindowTitle(tr("添加用户"));
	setFixedSize(400, 402);
	ui.ConfirmButton->setFocus();    //设置默认焦点
	ui.ConfirmButton->setDefault(true);
	connect(ui.ConfirmButton, SIGNAL(clicked(bool)), this, SLOT(NewUser()));
	connect(ui.CancelButton, SIGNAL(clicked(bool)), this, SLOT(ExitWindow()));
}

AddUserWindow::~AddUserWindow()
{
}

void AddUserWindow::ExitWindow()
{
	ui.UserName->clear();
	ui.PassWord->clear();
	ui.UserType->clear();
	ui.ConfirmButton->setFocus();    //设置默认焦点
	ui.ConfirmButton->setDefault(true);
	close();
}

void AddUserWindow::NewUser()
{
	try
	{
		if (!m_CAdminData->AddUser(ui.UserName->text(), ui.PassWord->text(),
			ui.UserType->text()))//添加失败
		{
			QMessageBox::warning(this, tr("警告"), tr("用户名已存在"), QMessageBox::Yes);
		}
		else
		{
			ui.UserName->clear();
			ui.PassWord->clear();
			ui.UserType->clear();
			close();//添加成功
		}
	}
	catch (const std::invalid_argument&)
	{
		QMessageBox::warning(this, tr("警告"), tr("错误用户类型"), QMessageBox::Yes);
	}
	catch (const std::length_error&)
	{
		QMessageBox::warning(this, tr("警告"), tr("用户名或者密码请勿超过20位"), QMessageBox::Yes);
	}
}