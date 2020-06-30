#include "AdminWindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QAbstractItemView>
#include <QLabel>
#include <QModelIndexList>
#include <QMessageBox>
#include <QtDebug>
#include <QStringList>
#include <QStandardItemModel>
#include <QtCore>

AdminWindow::AdminWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(tr("管理员"));
	setFixedSize(791, 554);
	QStringList CHeaders;
	CHeaders << tr("用户名") << tr("密码") << tr("用户类型");
	m_CAdmin.setHeaders(CHeaders);
	ui.StuView->setModel(&m_CAdmin);
	m_CAdd = new AddUserWindow(&m_CAdmin, this);
	m_CChange = new ChangeUserWindow(&m_CAdmin, this);
	ui.SearchButton->setFocus();
	ui.SearchButton->setDefault(true);
	connect(ui.StuView, SIGNAL(clicked(QModelIndex)), this, SLOT(ChangeStuView(QModelIndex)));
	connect(ui.DelButton, SIGNAL(clicked(bool)), this, SLOT(RemoveStuFromStuModel()));
	connect(ui.SearchButton, SIGNAL(clicked(bool)), this, SLOT(selectSlot()));
	connect(ui.ExitButton, SIGNAL(clicked(bool)), this, SLOT(exitSlot()));
	connect(ui.AddButton, SIGNAL(clicked(bool)), this, SLOT(addNewSlot()));
	connect(ui.ModButton, SIGNAL(clicked(bool)), this, SLOT(modifySLot()));
}

AdminWindow::~AdminWindow()
{
	delete m_CAdd;
	delete m_CChange;
}

void AdminWindow::ChangeStuView(QModelIndex index)
{
	ui.DetailInfo->clear();
	item = new QListWidgetItem(ui.DetailInfo);//为DetailInfo创建数据条目
	item->setText(QString(tr("用户名:")) + m_CAdmin.Item(index.row() + 1, 1)
		+ QString(tr("\n密码:")) + m_CAdmin.Item(index.row() + 1, 2)
		+ QString(tr("\n用户类型:")) + m_CAdmin.Item(index.row() + 1, 3));
}

void AdminWindow::RemoveStuFromStuModel()
{
	QModelIndexList select = ui.StuView->selectionModel()->selectedRows(0);
	if (!select.empty())
	{
		QModelIndex idIndex = select.at(0);
		QString name = m_CAdmin.Item(idIndex.row() + 1, 1);
		QMessageBox::StandardButton button;
		button = QMessageBox::question(this, tr("删除用户信息"),
			QString(tr("确定从数据库删除'%1'的信息吗？").arg(name)),
			QMessageBox::Yes | QMessageBox::No);
		if (button == QMessageBox::Yes)
		{
			ui.DetailInfo->clear();
			m_CAdmin.DeleteUser(idIndex.row() + 1);
		}
		else
		{
			QMessageBox::information(this,
				tr("删除用户信息"), tr("请选择要删除的用户信息！"));
		}
	}
	ui.SearchButton->setFocus();
	ui.SearchButton->setDefault(true);
}

void AdminWindow::selectSlot()
{
	QString CName = ui.TargetName->text();
	int iNum;
	if (CName.isEmpty())
	{
		return;
	}
	else if ((iNum = m_CAdmin.SearchUser(CName)) != -1)//如果有对应的人
	{
		ui.DetailInfo->clear();
		item = new QListWidgetItem(ui.DetailInfo);//为DetailInfo创建数据条目
		item->setText(QString(tr("用户名:")) + m_CAdmin.Item(iNum, 1)
			+ QString(tr("\n密码:")) + m_CAdmin.Item(iNum, 2)
			+ QString(tr("\n用户类型:")) + m_CAdmin.Item(iNum, 3));
	}
	else
	{
		QMessageBox::warning(this, tr("警告!"), tr("没有对应的用户 !"), QMessageBox::Yes);
	}
	ui.TargetName->clear();
}

void AdminWindow::exitSlot()
{
	close();
}

void AdminWindow::addNewSlot()
{
	m_CAdd->exec();
	ui.SearchButton->setFocus();
	ui.SearchButton->setDefault(true);
}

void AdminWindow::modifySLot()
{
	QModelIndexList select = ui.StuView->selectionModel()->selectedRows(0);
	if (!select.empty())
	{
		QModelIndex idIndex = select.at(0);
		m_CChange->SetData(idIndex.row() + 1);
		m_CChange->exec();
		ChangeStuView(idIndex);
	}
	ui.SearchButton->setFocus();
	ui.SearchButton->setDefault(true);
}
