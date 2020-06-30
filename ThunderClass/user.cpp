/*************************************************************************
【文件名】                 user.cpp
【功能模块和目的】         用户类函数实现
【开发者及日期】           范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】               
	2020-05-19 由范静涛修改了LoadFromFile函数，在为找到账号文件时，会自动创建一个只包含Admin账户的文件
	2020/6/14 由李永健增加删除用户机制
	2020/6/15 由李永健增加注释
*************************************************************************/
#include "user.h"
#include "admin.h"
#include "teacher.h"
#include "student.h"
#include <stdexcept>

unsigned int User::m_uUserCount = 0;
const unsigned int& User::UserCount = User::m_uUserCount;
vector<User*> User::m_UserList;
User* User::m_LoginedUser = nullptr;

/*************************************************************************
【函数名称】       User
【函数功能】       构造函数
【参数】           用户名、密码、用户类型
【返回值】         无
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】       无
*************************************************************************/
User::User(const string& Name, const string& Password, const string& Type):Type(m_sType){
    m_sName = Name;
    m_sPassword = Password;
    m_sType = Type;
    m_uUserCount++;
}

/*************************************************************************
【函数名称】       User
【函数功能】       构造函数
【参数】           输入的文件
【返回值】         无
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】       无
*************************************************************************/
User::User(ifstream& inFile):Type(m_sType){
    getline(inFile, m_sName);
    getline(inFile, m_sPassword);
    getline(inFile, m_sType);
    m_uUserCount++;
}

/*************************************************************************
【函数名称】       ~User
【函数功能】       析构函数
【参数】           无
【返回值】         无
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】       无
*************************************************************************/
User::~User(){
    m_uUserCount--;
}

/*************************************************************************
【函数名称】       User
【函数功能】       拷贝构造函数
【参数】           另一个该类的对象
【返回值】         无
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】       无
*************************************************************************/
User::User(const User& anUser):Type(m_sType){
    m_sName = anUser.m_sName;
    m_sPassword = anUser.m_sPassword;
    m_sType = anUser.m_sType;
}

/*************************************************************************
【函数名称】       operator=
【函数功能】       赋值运算符的重载
【参数】           另一个该类的对象
【返回值】         *this
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】       无
*************************************************************************/
User& User::operator=(const User& anUser){
    if (this != &anUser) {
        m_sName = anUser.m_sName;
        m_sPassword = anUser.m_sPassword;
        m_sType = anUser.m_sType;
    }
    return *this;
}

/*************************************************************************
【函数名称】       ToMessage
【函数功能】       将用户名转化为Message类然后发送给教师端
【参数】           无
【返回值】         无
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】       无
*************************************************************************/
Message User::ToMessage() const {
	unsigned int NameLen = m_sName.length();
	unsigned int PasswordLen = m_sPassword.length();
	unsigned char* Buffer = new unsigned char[NameLen + PasswordLen + 2 * sizeof(NameLen)];
	memcpy(Buffer, (char*)&NameLen, sizeof(NameLen));
	memcpy(Buffer + sizeof(NameLen), m_sName.c_str(), NameLen);
	memcpy(Buffer + sizeof(NameLen) + NameLen, (char*)&PasswordLen, sizeof(PasswordLen));
	memcpy(Buffer + 2 * sizeof(NameLen) + NameLen, m_sPassword.c_str(), PasswordLen);
	Message ret(MSG_ID_PSW, Buffer, NameLen + PasswordLen + 2 * sizeof(NameLen));
	delete[] Buffer;
	return ret;
}

/*************************************************************************
【函数名称】       SaveToFileStream
【函数功能】       将用户存入OutFile文件
【参数】           ofstream的引用
【返回值】         无
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】       无
*************************************************************************/
void User::SaveToFileStream(ofstream& OutFile) const {
    OutFile << m_sName << endl;
    OutFile << m_sPassword << endl;
    OutFile << m_sType << endl;
}

/*************************************************************************
【函数名称】       GetName
【函数功能】       获取用户名
【参数】           无
【返回值】         用户名字符串
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】       无
*************************************************************************/
string User::GetName() const{
    return m_sName;
}

/*************************************************************************
【函数名称】       TestPassword
【函数功能】       测试密码是否正确
【参数】           待测试的密码
【返回值】         是否正确的bool类型
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】       无
*************************************************************************/
bool User::TestPassword(const string& Password) const {
    if (Password == m_sPassword) {
        return true;
    }
    else {
        return false;
    }
}

/*************************************************************************
【函数名称】       AddUser
【函数功能】       增加用户
【参数】           新增用户的用户名密码类型
【返回值】         增加成功与否
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-3
【更改记录】       
	2020/6/14 由李永健增加同名判定
*************************************************************************/
bool User::AddUser(const string& Name, const string& Password, const string& Type){
    Admin* p = nullptr;
    p = dynamic_cast<Admin*>(this);
    if (p != nullptr) {
		const User* pCUserExist = GetUser(Name);//判断是否已经存在对应的用户
		if (nullptr != pCUserExist)//如果用户已存在，就返回错误
		{
			return false;
		}
		else//如果用户不存在
		{
			if (Type == "Teacher") {
				m_UserList.push_back(new Teacher(Name, Password));
				SaveToFile("UserInformation.txt");//存入文件
				return true;
			}
			else {
				m_UserList.push_back((User*) new Student(Name, Password));
				SaveToFile("UserInformation.txt");//存入文件
				return true;
			}
		}
    }
    else {
        return false;
    }
}
/*************************************************************************
【函数名称】       DeleteUser
【函数功能】       删除第iNum个用户
【参数】           要删除的用户
【返回值】         删除成功与否
【开发者及日期】   李永健 2020/6/14
【更改记录】       无
*************************************************************************/
bool User::DeleteUser(int iNum)
{
	Admin* p = nullptr;
	p = dynamic_cast<Admin*>(this);
	if (p != nullptr)
	{
		if (iNum == 0)//如果修改的是管理员就返回错误
		{
			return false;
		}
		vector<User*>::iterator ItUser = m_UserList.begin();//迭代器初始化为第一个元素
		for (int i = 0; i < iNum; i++)//迭代器以寻找对应元素
		{
			ItUser++;
		}
		delete *ItUser;//释放对应空间
		m_UserList.erase(ItUser);//删除对应元素
		SaveToFile("UserInformation.txt");//存入文件
		return true;
	}
	else
	{
		return false;
	}
}

/*************************************************************************
【函数名称】       ChangeUser
【函数功能】       更改地iNum个User的数据
【参数】           待更改的User的位置，变更为的用户名密码和类型
【返回值】         如果添加失败就返回false
【开发者及日期】   李永健 2020/6/14
【更改记录】       无
*************************************************************************/
bool User::ChangeUser(int iNum, const string& Name, const string& Password, const string& Type)
{
	Admin* p = nullptr;
	p = dynamic_cast<Admin*>(this);
	if (p != nullptr)
	{
		const User* pCUserExist = GetUser(Name);//判断是否已经存在对应的用户
		if ("Admin" == m_UserList[iNum]->GetName())//禁止改变管理员
		{
			return false;
		}
		else if (pCUserExist != m_UserList[iNum] && pCUserExist != nullptr)//如果修改完成后用户名重复，就返回错误
		{
			return false;
		}
		else
		{
			*m_UserList[iNum] = User(Name, Password, Type);//改掉对应的用户
			SaveToFile("UserInformation.txt");//存入文件
			return true;
		}
	}
	else
	{
		return false;
	}
}

/*************************************************************************
【函数名称】       GetPassword
【函数功能】       获得指定用户的密码
【参数】           用户位置
【返回值】         密码
【开发者及日期】   李永健 2020/6/14
【更改记录】       无
*************************************************************************/
string User::GetPassword(int iNum)
{
	vector<User*>::iterator ItUser = m_UserList.begin();//迭代器初始化为第一个元素
	for (int i = 0; i < iNum; i++)//迭代器以寻找对应元素
	{
		ItUser++;
	}
	return (*ItUser)->m_sPassword;
}

/*************************************************************************
【函数名称】       SearchUser
【函数功能】       寻找对应用户名用户的位置
【参数】           用户名
【返回值】         对应位置
【开发者及日期】   李永健 2020/6/14
【更改记录】       无
*************************************************************************/
int User::SearchUser(const string& Name)
{
	vector<User*>::iterator ItUser = m_UserList.begin();//迭代器初始化为第一个元素
	for (int i = 0; m_UserList.end() != ItUser; i++)//迭代器以寻找对应元素
	{
		if ((*ItUser)->GetName() == Name)
		{
			return i;
		}
		ItUser++;
	}
	return -1;
}

/*************************************************************************
【函数名称】       LoadFromFile
【函数功能】       从文件读入一批用户
【参数】           文件名
【返回值】         无
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-3
【更改记录】       
	2020-05-19 范静涛增加了未找到文件则自动创建只包含Admin用户的功能
	2020/6/14 由李永健增加vector内指针对象释放功能
*************************************************************************/
void User::LoadFromFile(const string& FileName) {
	ifstream inFile(FileName.c_str());
	if (inFile.fail()) {
		ofstream OutFile(FileName.c_str(), ios::out | ios::app);
		OutFile << 1 << endl << "Admin" << endl << "Admin" << endl << "Admin" << endl;
		OutFile.close();
	}
	inFile.close();
	inFile.open(FileName.c_str());

	for (std::vector<User*>::iterator IterUser = m_UserList.begin();
		m_UserList.end() != IterUser; IterUser++)
	{
		delete *IterUser;//释放对应的空间
	}
    m_UserList.clear();
    unsigned int UserCount;
    inFile >> UserCount;
    inFile.get();
    for (unsigned int i  = 0; i < UserCount; i++) {
        string Name;
        string Password;
        string Type;
        getline(inFile, Name);
        getline(inFile, Password);
        getline(inFile, Type);
        if (Type == "Admin"){
            m_UserList.push_back(new Admin());
        }
        else if (Type == "Teacher"){
            m_UserList.push_back(new Teacher(Name, Password));
        }
        else {
            m_UserList.push_back((User*)new Student(Name, Password));
        }
    }
    inFile.close();
}

/*************************************************************************
【函数名称】       SaveToFile
【函数功能】       将所有用户存入名为FileName的文件
【参数】           文件名FileName
【返回值】         无
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】       无
*************************************************************************/
void User::SaveToFile(const string& FileName){
    ofstream OutFile(FileName.c_str());
    OutFile << m_UserList.size() << endl;
    for (unsigned int i  = 0; i < m_UserList.size(); i++) {
        m_UserList[i]->SaveToFileStream(OutFile);
    }
}

/*************************************************************************
【函数名称】       GetUser
【函数功能】       按用户名密码获取用户
【参数】           用户名、密码
【返回值】         对应用户的指针
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-11
【更改记录】       无
*************************************************************************/
const User* User::GetUser(const string& Name, const string& Password){
    const User* Current = nullptr;
    for (unsigned int i  = 0; i < m_UserList.size(); i++) {
        if (m_UserList[i]->GetName() == Name && m_UserList[i]->TestPassword(Password)) {
            Current = m_UserList[i];
            m_LoginedUser = m_UserList[i];
            break;
        }
    }
    return Current;

}

/*************************************************************************
【函数名称】       GetUser
【函数功能】       按用户名搜索用户
【参数】           用户名
【返回值】         用户的指针
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-3
【更改记录】       无
*************************************************************************/
const User* User::GetUser(const string& Name) {
    const User* Current = nullptr;
    for (unsigned int i  = 0; i < m_UserList.size(); i++) {
        if (m_UserList[i]->GetName() == Name) {
            Current = m_UserList[i];
            break;
        }
    }
    return Current;

}

/*************************************************************************
【函数名称】       GetUser
【函数功能】       按照给定位置搜索用户
【参数】           对应位置
【返回值】         User类指针
【开发者及日期】   李永健 2020/6/14
【更改记录】       无
*************************************************************************/
const User* User::GetUser(int iNum)
{
	vector<User*>::iterator ItUser = m_UserList.begin();//迭代器初始化为第一个元素
	for (int i = 0; i < iNum; i++)//迭代器以寻找对应元素
	{
		ItUser++;
	}
	return *ItUser;
}

/*************************************************************************
【函数名称】       GetLoginedUser
【函数功能】       获取最后一次登录的用户指针
【参数】           无
【返回值】         最后一次登录的用户指针
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-3
【更改记录】       无
*************************************************************************/
User* User::GetLoginedUser() {
    return m_LoginedUser;
}

/*************************************************************************
【函数名称】       OfflineAllStudents
【函数功能】       将所有学生对象离线
【参数】           无
【返回值】         无
【开发者及日期】   范静涛(fanjingtao@tsinghua.edu.cn) 2020-5-3
【更改记录】       无
*************************************************************************/
void User::OfflineAllStudents(){
    Student* pStudent;
    for (unsigned int i  = 0; i < m_UserList.size(); i++) {
        if (m_UserList[i]->Type == "Student") {
            pStudent = dynamic_cast<Student*>(m_UserList[i]);
            pStudent->Offline();
        }
    }
}
