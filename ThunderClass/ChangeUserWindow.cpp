#include "ChangeUserWindow.h"
#include <QMessageBox>

ChangeUserWindow::ChangeUserWindow(AdminProcess* AdminData, QWidget *parent)
	: QDialog(parent), m_CAdminData(AdminData)
{
	ui.setupUi(this);
	setWindowTitle(tr("更改用户"));
	setFixedSize(415, 405);
	ui.ConfirmButton->setFocus();    //设置默认焦点
	ui.ConfirmButton->setDefault(1);
	connect(ui.ConfirmButton, SIGNAL(clicked(bool)), this, SLOT(ChangeData()));
	connect(ui.CancelButton, SIGNAL(clicked(bool)), this, SLOT(ExitWindow()));
}

ChangeUserWindow::~ChangeUserWindow()
{
}

void ChangeUserWindow::SetData(int iRow)
{
	ui.UserName->setText(m_CAdminData->Item(iRow, 1));
	ui.PassWord->setText(m_CAdminData->Item(iRow, 2));
	ui.UserType->setText(m_CAdminData->Item(iRow, 3));
	m_iRow = iRow;
}

void ChangeUserWindow::ExitWindow()
{
	ui.UserName->clear();
	ui.PassWord->clear();
	ui.UserType->clear();
	ui.ConfirmButton->setFocus();    //设置默认焦点
	ui.ConfirmButton->setDefault(true);
	close();
}

void ChangeUserWindow::ChangeData()
{
	try
	{
		if (!m_CAdminData->ChangeUser(m_iRow, ui.UserName->text(), ui.PassWord->text(),
			ui.UserType->text()))//添加失败
		{
			QMessageBox::warning(this, tr("警告"), tr("用户名已存在"), QMessageBox::Yes);
		}
		else
		{
			ui.UserName->clear();
			ui.PassWord->clear();
			ui.UserType->clear();
			ui.ConfirmButton->setFocus();    //设置默认焦点
			ui.ConfirmButton->setDefault(true);
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