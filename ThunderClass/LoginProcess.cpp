/*************************************************************************
【文件名】                 LoginProcess.cpp
【功能模块和目的】         LoginProcess类函数的定义
【开发者及日期】           李永健 2020/4/27
【更改记录】               
	2020/6/14 由李永健适配User类
	2020/6/19 由李永健增加防止中文乱码的机制
*************************************************************************/
#include "LoginProcess.h"
#include "QStrAndStr.h"

/*************************************************************************
【函数名称】       构造函数
【函数功能】       类内数据初始化
【参数】           无
【返回值】         无
【开发者及日期】   李永健 2020/4/27
【更改记录】       
	2020/6/14 由李永健适配User类
*************************************************************************/
LoginProcess::LoginProcess(void)
	: WrongTime(m_iWrongTime)
{
	m_iWrongTime = 0;
	User::LoadFromFile("UserInformation.txt");
}

/*************************************************************************
【函数名称】       析构函数
【函数功能】       对象清理
【参数】           无
【返回值】         无
【开发者及日期】   李永健 2020/4/27
【更改记录】       无
*************************************************************************/
LoginProcess::~LoginProcess(void)
{
}

/*************************************************************************
【函数名称】       Result
【函数功能】       判断是否有对应用户，有的话返回用户类型，没有返回NONE
【参数】           输入的用户名和密码
【返回值】         用户类型
【开发者及日期】   李永健 2020/6/14
【更改记录】       2020/6/19 由李永健增加防止中文乱码的机制
*************************************************************************/
UserType LoginProcess::Result(const QString& CName, const QString& CPassword)
{
	const User* pCurrentUser = User::GetUser(QStrToStr(CName), QStrToStr(CPassword));//寻找对应用户
	if (nullptr == pCurrentUser)
	{
		m_iWrongTime++;//错误次数加一
		return NONE;
	}//如果没有对应用户
	if ("Admin" == pCurrentUser->Type)
	{
		return ADMIN;
	}//用户是管理员
	else if ("Teacher" == pCurrentUser->Type)
	{
		return TEACHER;
	}//用户是老师
	else
	{
		return STUDENT;
	}//用户是学生
}