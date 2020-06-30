#ifndef QUESTIONWINDOW_H
#define QUESTIONWINDOW_H

#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QCloseEvent>
#include "ui_QuestionWindow.h"
#include "teacherprocess.h"
#include "AnswerResWindow.h"

class QuestionWindow : public QDialog
{
	Q_OBJECT

public:
	QuestionWindow(TeacherProcess* pProc, QWidget *parent = Q_NULLPTR);
	~QuestionWindow();

private slots:
	void SendQues();
	void EndQues();
	void ShowTime();
	void closeEvent(QCloseEvent* Ev) override;

private:
	TeacherProcess* m_pProc;
	QTime m_BeginTime;
	QTimer* m_pTimer;
	bool m_bWaiting;
	Ui::QuestionWindow ui;
};

#endif