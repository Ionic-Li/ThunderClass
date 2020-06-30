#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "AddUserWindow.h"
#include "ChangeUserWindow.h"
#include <QDialog>
#include "ui_AdminWindow.h"
#include "AdminProcess.h"
#include <QListWidgetItem>

class AdminWindow : public QDialog
{
	Q_OBJECT

public:
	AdminWindow(QWidget *parent = Q_NULLPTR);
	~AdminWindow();

private slots:
	void ChangeStuView(QModelIndex index);//定位选择的行，并在右边list中显示出来
	void RemoveStuFromStuModel();//从数据库删除记录
	void selectSlot();//搜索
	void exitSlot();//退出窗口
	void addNewSlot();
	void modifySLot();

private:
	AdminProcess m_CAdmin;//管理用户
	Ui::AdminWindow ui;
	AddUserWindow* m_CAdd;
	ChangeUserWindow* m_CChange;

	QListWidgetItem *item;
};

#endif