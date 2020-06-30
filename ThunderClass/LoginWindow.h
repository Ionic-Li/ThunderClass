#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QtWidgets/QDialog>
#include "LoginProcess.h"
#include "ui_LoginWindow.h"
#include "TeacherWindow.h"
#include "StudentWindow.h"
#include "AdminWindow.h"

class LoginWindow : public QDialog
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = 0);
	~LoginWindow();

private slots:
	void OnClicked();//用于完成输入判断的函数
	void ExitClicked();//退出程序

private:
	Ui::LoginWindow ui;
	LoginProcess m_CProcess;//登录函数
};

#endif // LoginWindow_H