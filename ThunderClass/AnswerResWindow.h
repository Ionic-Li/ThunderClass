#pragma once

#include <QDialog>
#include "teacherprocess.h"
#include "QStandardItemModel"
#include "ui_AnswerResWindow.h"

class AnswerResWindow : public QDialog
{
	Q_OBJECT

public:
	AnswerResWindow(const vector<pair<string, Answer> >& AnswerData, QWidget *parent = Q_NULLPTR);
	~AnswerResWindow();

private:
	QStandardItemModel* m_pStuResModel;
	QStandardItemModel* m_pAnsResModel;
	Ui::AnswerResWindow ui;
};
