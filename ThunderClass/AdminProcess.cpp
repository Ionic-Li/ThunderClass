/*************************************************************************
【文件名】                 AdminProcess.cpp
【功能模块和目的】         AdminProcess类函数的定义
【开发者及日期】           李永健 2020/4/29
【更改记录】               
	2020/6/14 由李永健适配Admin类
	2020/6/15 由李永健增加输入用户类型错误判断，并优化部分代码
	2020/6/19 由李永健增加了避免中文乱码的机制
*************************************************************************/
#include "AdminProcess.h"
#include "QStrAndStr.h"

/*************************************************************************
【函数名称】       构造函数
【函数功能】       类内数据初始化
【参数】           无
【返回值】         无
【开发者及日期】   李永健 2020/4/29
【更改记录】       
	2020/6/14 由李永健适配Admin类
*************************************************************************/
AdminProcess::AdminProcess(QObject *parent)
	: QAbstractTableModel(parent)
{
	m_pCUserAdmin = dynamic_cast<Admin*>(const_cast<User*>(User::GetUser("Admin")));//找到admin用户
}

/*************************************************************************
【函数名称】       析构函数
【函数功能】       对象清理
【参数】           无
【返回值】         无
【开发者及日期】   李永健 2020/4/29
【更改记录】       无
*************************************************************************/
AdminProcess::~AdminProcess()
{

}

/*************************************************************************
【函数名称】       setHeaders
【函数功能】       设置表头
【参数】           QStringList
【返回值】         无
【开发者及日期】   李永健 2020/4/29
【更改记录】       无
*************************************************************************/
void AdminProcess::setHeaders(const QStringList& headerNames)
{
	beginResetModel();
	m_CHeaders = headerNames;

	//刷新所有视图数据
	endResetModel();
}

/*************************************************************************
【函数名称】       rowCount
【函数功能】       返回行大小
【参数】           QModelIndex
【返回值】         总行数
【开发者及日期】   李永健 2020/4/29
【更改记录】       
	2020/6/14 由李永健适配Admin类
*************************************************************************/
int AdminProcess::rowCount(const QModelIndex& parent) const
{
	return m_pCUserAdmin->UserCount - 1;
}

/*************************************************************************
【函数名称】       rowRow
【函数功能】       返回列大小
【参数】           QModelIndex
【返回值】         总列数
【开发者及日期】   李永健 2020/4/29
【更改记录】       无
*************************************************************************/
int AdminProcess::columnCount(const QModelIndex& parent) const
{
	return m_CHeaders.count();
}

/*************************************************************************
【函数名称】       data
【函数功能】       输入数据
【参数】           QModelIndex和功能
【返回值】         对应的元素
【开发者及日期】   李永健 2020/4/29
【更改记录】       无
*************************************************************************/
QVariant AdminProcess::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())//如果不是有效的数据区
	{
		return QVariant();
	}
	if (role == Qt::TextAlignmentRole)//设置排版格式
	{
		return int(Qt::AlignVCenter | Qt::AlignVCenter);
	}
	else if (role == Qt::DisplayRole)//返回数据
	{
		switch (index.column())
		{
		case 1 :
			return "********";
			break;
		default:
			return Item(index.row() + 1, index.column() + 1);
			break;
		}
	}
	return QVariant();
}

/*************************************************************************
【函数名称】       headData
【函数功能】       设置表头显示数据
【参数】           位置和功能
【返回值】         总行数
【开发者及日期】   李永健 2020/4/29
【更改记录】       无
*************************************************************************/
QVariant AdminProcess::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole) //如果是表头
	{
		if (orientation == Qt::Horizontal)//列表头
		{
			return m_CHeaders[section];
		}
		else//行表头
		{
			return QVariant();
		}
	}
	return QVariant();
}

/*************************************************************************
【函数名称】       Item
【函数功能】       传回对应的元素
【参数】           对应位置
【返回值】         QString
【开发者及日期】   李永健 2020/4/29
【更改记录】       
	2020/6/14 由李永健适配Admin类
	2020/6/15 由李永健优化代码
	2020/6/19 由李永健增加了避免中文乱码的机制
*************************************************************************/
QString AdminProcess::Item(int iRow, int iColumn) const
{
	switch (iColumn)//根据列数判断
	{
	case 1://如果是第一列
		return StrToQStr(User::GetUser(iRow)->GetName());//返回用户名
		break;
	case 2://如果是第二列
		return StrToQStr(m_pCUserAdmin->GetPassword(iRow));//返回用户密码
		break;
	case 3 :
		return StrToQStr(User::GetUser(iRow)->Type);
		break;
	default :
		return "";
		break;
	}
}

/*************************************************************************
【函数名称】       AddUser
【函数功能】       增加用户
【参数】           用户的信息
【返回值】         是否添加成功
【开发者及日期】   李永健 2020/4/29
【更改记录】       
	2020/6/14 由李永健适配Admin类
	2020/6/15 由李永健增加输入用户类型错误判断
	2020/6/19 由李永健增加了避免中文乱码的机制
*************************************************************************/
bool AdminProcess::AddUser(const QString& Name, const QString& Password,
	const QString& Type)
{
	beginResetModel();
	string sType = GetUserType(Type);
	bool bFlag = m_pCUserAdmin->AddUser(
		QStrToStr(Name), QStrToStr(Password), sType
	);//返回添加成功与否
	endResetModel();
	return bFlag;
}

/*************************************************************************
【函数名称】       DeleteUser
【函数功能】       删除对应行的数据
【参数】           对应的行数
【返回值】         无
【开发者及日期】   李永健 2020/4/29
【更改记录】       
	2020/6/14 由李永健适配Admin类
*************************************************************************/
void AdminProcess::DeleteUser(int iRow)
{
	beginResetModel();
	m_pCUserAdmin->DeleteUser(iRow);//删除对应行的元素
	endResetModel();
}

/*************************************************************************
【函数名称】       ChangeUser
【函数功能】       修改用户数据
【参数】           用户数据
【返回值】         是否添加成功
【开发者及日期】   李永健 2020/4/29
【更改记录】       
	2020/6/14 由李永健适配Admin类
	2020/6/15 由李永健增加输入用户类型错误判断
	2020/6/19 由李永健增加了避免中文乱码的机制
*************************************************************************/
bool AdminProcess::ChangeUser(int iRow, const QString& Name, const QString& Password,
	const QString& Type)
{
	beginResetModel();
	string sType = GetUserType(Type);
	bool bFlag = m_pCUserAdmin->ChangeUser(iRow, QStrToStr(Name),
		QStrToStr(Password), sType);//修改对应的数据
	endResetModel();
	return bFlag;
}

/*************************************************************************
【函数名称】       SearchUser
【函数功能】       查找用户
【参数】           用户名
【返回值】         对应的行数
【开发者及日期】   李永健 2020/4/29
【更改记录】       
	2020/6/14 由李永健适配Admin类
	2020/6/19 由李永健增加了避免中文乱码的机制
*************************************************************************/
int AdminProcess::SearchUser(const QString& Name)
{
	if (Name == "Admin")//不显示Admin
	{
		return -1;
	}
	return m_pCUserAdmin->SearchUser(QStrToStr(Name));
}

/*************************************************************************
【函数名称】       GetUserType
【函数功能】       返回对应的用户类型如果不是老师和学生就报错
【参数】           QString类的Type
【返回值】         对应的用户类型的string
【开发者及日期】   李永健 2020/4/29
【更改记录】       
	2020/6/15 由李永健更改函数名并将返回值改为string
*************************************************************************/
string AdminProcess::GetUserType(const QString& Type)
{
	if (Type.toLower() == "teacher")//如果是老师，将新增用户类型转化为老师
	{
		return "Teacher";
	}
	else if (Type.toLower() == "student")//如果是学生
	{
		return "Student";
	}
	else//如果都不是，抛出错误
	{
		throw invalid_argument("wrong type");
	}
}