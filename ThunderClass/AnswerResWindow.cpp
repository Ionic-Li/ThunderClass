#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "AnswerResWindow.h"
#include "QStrAndStr.h"

AnswerResWindow::AnswerResWindow(const vector<pair<string, Answer> >& AnswerData, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("答题情况"));
	int iCount[4] = { 0 };//答题情况
	m_pStuResModel = new QStandardItemModel();
	m_pAnsResModel = new QStandardItemModel();
	m_pStuResModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("用户名")));//设置第一个表格
	m_pStuResModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("选项")));
	m_pStuResModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("用时")));
	ui.StuResView->setModel(m_pStuResModel);
	ui.StuResView->setColumnWidth(0, 100);
	ui.StuResView->setColumnWidth(1, 100);
	ui.StuResView->setColumnWidth(2, 100);
	ui.StuResView->verticalHeader()->hide();
	ui.StuResView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	for (int i = 0; i < AnswerData.size(); i++)
	{
		m_pStuResModel->setItem(i, 0, new QStandardItem(StrToQStr(AnswerData[i].first)));
		m_pStuResModel->setItem(i, 1, new QStandardItem(
			QString::fromStdString(AnswerData[i].second.GetAnswer())));
		m_pStuResModel->setItem(i, 2, new QStandardItem(QString::number(AnswerData[i].second.GetHour()) + ':'
			+ QString::number(AnswerData[i].second.GetMin()) + ':'
			+ QString::number(AnswerData[i].second.GetSec())));
		for (int j = 0; j < 4; j++)//统计此学生选择的选项
		{
			if (AnswerData[i].second.Check('A' + j))
			{
				iCount[j]++;
			}
		}
	}
	m_pAnsResModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("A")));//设置第二个表格
	m_pAnsResModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("B")));
	m_pAnsResModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("C")));
	m_pAnsResModel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("D")));
	m_pAnsResModel->setVerticalHeaderItem(0, new QStandardItem(QObject::tr("选择人数")));
	ui.AnsResView->setModel(m_pAnsResModel);
	ui.AnsResView->setColumnWidth(0, 100);
	ui.AnsResView->setColumnWidth(1, 100);
	ui.AnsResView->setColumnWidth(2, 100);
	ui.AnsResView->setColumnWidth(3, 100);
	ui.AnsResView->setRowHeight(0, 30);
	ui.AnsResView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	for (int i = 0; i < 4; i++)
	{
		m_pAnsResModel->setItem(0, i, new QStandardItem(QString::number(iCount[i])));
	}
}

AnswerResWindow::~AnswerResWindow()
{
	delete m_pAnsResModel;
	delete m_pStuResModel;
}
