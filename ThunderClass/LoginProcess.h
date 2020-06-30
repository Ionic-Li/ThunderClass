/*************************************************************************
【文件名】                 LoginProcess.h
【功能模块和目的】         LoginProcess类声明
【开发者及日期】           李永健 2020/4/27
【更改记录】               
	2020/6/14 由李永健适配User类
	2020/6/20 由李永健增加注释
*************************************************************************/
#ifndef _LOGINPROCESS_H_
#define _LOGINPROCESS_H_

#include "user.h"
#include <qstring.h>

enum UserType
{
	NONE, ADMIN, TEACHER, STUDENT
};

/*************************************************************************
【类名】             LoginProcess
【功能】             输入操作的业务类
【接口说明】 
	构造函数LoginProcess()
	析构函数~LoginProcess()
	函数Result(const QString& CName, const QString& CPassword)判断是否有对应用户，有的话返回用户类型，没有返回NONE
	常引用WrongTime用来输入的错误次数
【开发者及日期】     李永健 2020/4/27
【更改记录】         
	2020/6/14 由李永健适配User类
	2020/6/20 由李永健增加注释
*************************************************************************/
class LoginProcess
{
public:
	LoginProcess(void);//构造函数
	LoginProcess(const LoginProcess& data) = delete;
	virtual ~LoginProcess(void);//析构函数
	LoginProcess& operator=(const LoginProcess& data) = delete;
	//判断是否有对应用户，有的话返回用户类型，没有返回NONE
	UserType Result(const QString& CName, const QString& CPassword);

	//输入错误次数
	const unsigned int& WrongTime;
private:
	unsigned int m_iWrongTime;//输入错误的次数
};

#endif