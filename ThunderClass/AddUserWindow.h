#ifndef ADDUSERWINDOW_H
#define ADDUSERWINDOW_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QDialog>
#include "AdminProcess.h"
#include "ui_AddUserWindow.h"

class AddUserWindow : public QDialog
{
	Q_OBJECT

public:
	AddUserWindow(AdminProcess* AdminData, QWidget *parent = Q_NULLPTR);
	~AddUserWindow();

private slots:
	void NewUser();
	void ExitWindow();

private:
	Ui::AddUserWindow ui;
	AdminProcess* m_CAdminData;
};
#endif
