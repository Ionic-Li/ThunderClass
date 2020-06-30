/*************************************************************************
【文件名】                 AdminProcess.h
【功能模块和目的】         AdminProcess类声明
【开发者及日期】           李永健 2020/4/29
【更改记录】               
	2020/6/14 由李永健适配Admin类
	2020/6/15 由李永健增加注释并更改GetUserType函数名和返回值
*************************************************************************/
#ifndef _ADMINPROCESS_H_
#define _ADMINPROCESS_H_

#include "admin.h"
#include <QString>
#include <string>
#include <QAbstractTableModel>
using namespace std;

/*************************************************************************
【类名】             AdminProcess
【功能】             用于管理的业务类，与ui的列表耦合
【接口说明】         
	构造函数AdminProcess(QObject *parent = 0)
	虚析构函数~AdminProcess(void)
	函数setHeaders(const QStringList& headerNames)设置表头显示
	函数rowCount(const QModelIndex& parent)返回行大小
	函数columnCount(const QModelIndex& parent)返回列大小
	函数data(const QModelIndex& index, int role)输入数据
	函数headerData(int section, Qt::Orientation orientation,int role)设置表头显示数据
	函数Item(int iRow, int iColumn)传回对应的元素
	函数AddUser(const QString& Name, const QString& Password, const QString& Type)增加用户
	函数DeleteUser(int iRow)删除对应行数据
	函数ChangeUser(int iRow, const QString& Name, const QString& Password, const QString& Type)更改对应行数据
	函数SearchUser(const QString& Name)查找用户
【开发者及日期】     李永健 2020/4/29
【更改记录】         
	2020/6/14 由李永健适配Admin类
	2020/6/15 由李永健更改GetUserType函数名和返回值
*************************************************************************/
class AdminProcess : public QAbstractTableModel
{
	Q_OBJECT

public:
	//构造函数
	AdminProcess(QObject *parent = 0);
	//禁用拷贝构造函数
	AdminProcess(const AdminProcess& data) = delete;
	//虚析构函数
	virtual ~AdminProcess(void);
	//禁用赋值运算符重载
	AdminProcess& operator=(const AdminProcess& data) = delete;

	//设置表头显示
	void setHeaders(const QStringList& headerNames);
	//返回行大小
	int rowCount(const QModelIndex& parent) const;
	//返回列大小
	int columnCount(const QModelIndex& parent) const;
	//输入数据
	QVariant data(const QModelIndex& index, int role) const;
	//设置表头显示数据
	QVariant headerData(int section, Qt::Orientation orientation,
		int role) const;
	
	//传回对应的元素
	QString Item(int iRow, int iColumn) const;
	//增加用户
	bool AddUser(const QString& Name, const QString& Password, 
		const QString& Type);
	//删除对应行的数据
	void DeleteUser(int iRow);
	//修改用户数据
	bool ChangeUser(int iRow, const QString& Name, const QString& Password, 
		const QString& Type);
	//查找用户
	int SearchUser(const QString& Name);
private:
	Admin* m_pCUserAdmin;
	QStringList m_CHeaders;

	//返回对应的用户类型
	string GetUserType(const QString& Type);
};

#endif