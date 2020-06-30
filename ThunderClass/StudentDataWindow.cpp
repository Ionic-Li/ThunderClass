#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "StudentDataWindow.h"
#include "student.h"
#include "QStrAndStr.h"

StudentDataWindow::StudentDataWindow(const TeacherProcess* pProc, QWidget *parent)
	: m_pProc(pProc), QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("学生专注度信息"));
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
	m_pStuDat = new QStandardItemModel();
	m_pStuDat->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("用户名")));
	m_pStuDat->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("在线时长")));
	m_pStuDat->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("专注时长")));
	m_pStuDat->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("专注百分比")));
	ui.tableView->setModel(m_pStuDat);
	ui.tableView->setColumnWidth(0, 100);
	ui.tableView->setColumnWidth(1, 100);
	ui.tableView->setColumnWidth(2, 100);
	ui.tableView->setColumnWidth(3, 100);
	ui.tableView->verticalHeader()->hide();
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	vector<pair<string, const TimeCount> > StuData = m_pProc->GetTimeCount();
	for (int i = 0; i < StuData.size(); i++)
	{
		m_pStuDat->setItem(i, 0, new QStandardItem(StrToQStr(StuData[i].first)));
		m_pStuDat->setItem(i, 1, new QStandardItem(QString::number(StuData[i].second.GetHourInClass()) + ":"
			+ QString::number(StuData[i].second.GetMinInClass()) + ":"
			+ QString::number(StuData[i].second.GetSecInClass())));
		m_pStuDat->setItem(i, 2, new QStandardItem(QString::number(StuData[i].second.GetHourFocused()) + ":"
			+ QString::number(StuData[i].second.GetMinFocused()) + ":"
			+ QString::number(StuData[i].second.GetSecFocused())));
		m_pStuDat->setItem(i, 3, new QStandardItem(QString::number(StuData[i].second.GetFocusedRate()) + "%"));
	}
}

StudentDataWindow::~StudentDataWindow()
{
	delete m_pStuDat;
}
