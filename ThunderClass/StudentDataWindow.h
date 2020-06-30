#pragma once

#include <QDialog>
#include <QStandardItemModel>
#include "teacherprocess.h"
#include "ui_StudentDataWindow.h"

class StudentDataWindow : public QDialog
{
	Q_OBJECT

public:
	StudentDataWindow(const TeacherProcess* pProc, QWidget *parent = Q_NULLPTR);
	~StudentDataWindow();

private:
	QStandardItemModel* m_pStuDat;
	const TeacherProcess* m_pProc;
	Ui::StudentDataWindow ui;
};
