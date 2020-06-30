/*************************************************************************
【文件名】admin.h
【功能模块和目的】管理员类声明
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-10
【版权信息】开发者范静涛(fanjingtao@tsinghua.edu.cn)声明放弃任何版权诉求，任何使用者可做出任何修改、用于任何目的
【更改记录】
	2020-5-15 由范静涛增加注释
	2020/6/14 由李永健增加删改函数
*************************************************************************/
#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include <string>
using std::string;

/*************************************************************************
【类名】Admin
【功能】管理员类
【接口说明】
	函数AddUser(const string &Name, const string &Password, const string &Type)用于新增一个用户对象，具体功能见相应函数定义处的注释
	函数DeleteUser(int iNum)用于删除用户
	函数ChangeUser(int iNum, const string& Name, const string& Password, const string& Type)用于更改用户
	函数GetPassword(int iNum)用于获取密码
	函数SearchUser(const string& Name)用于获取用户位置
【开发者及日期】范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-10
【更改记录】
	2020-5-15 由范静涛增加注释
	2020/6/14 由李永健增加删改和获取密码函数
*************************************************************************/
class Admin : public User
{
public:
    //新增用户
    bool AddUser(const string& Name, const string& Password, const string& Type) override;
	//删除用户
	bool DeleteUser(int iNum) override;
	//更改用户
	bool ChangeUser(int iNum, const string& Name, const string& Password, const string& Type) override;
	//获取地iNum个用户的密码
	string GetPassword(int iNum) override;
	//获取对应用户的位置
	int SearchUser(const string& Name) override;
private:
    //友元
    friend class User;
    //私有构造函数，不允许在类外显性创建Admin对象
    Admin();
};

#endif // ADMIN_H
