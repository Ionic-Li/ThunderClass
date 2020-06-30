#ifndef CHANGEUSERWINDOW_H
#define CHANGEUSERWINDOW_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QDialog>
#include "AdminProcess.h"
#include "ui_ChangeUserWindow.h"

class ChangeUserWindow : public QDialog
{
	Q_OBJECT

public:
	ChangeUserWindow(AdminProcess* AdminData, QWidget *parent = Q_NULLPTR);
	~ChangeUserWindow();
	void SetData(int iRow);

private slots:
	void ChangeData();
	void ExitWindow();

private:
	int m_iRow;//行号
	AdminProcess* m_CAdminData;
	Ui::ChangeUserWindow ui;
};

#endif