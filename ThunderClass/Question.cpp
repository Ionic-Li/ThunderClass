#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
/*************************************************************************
【文件名】                 Question.cpp
【功能模块和目的】         Question类函数的定义
【开发者及日期】           李永健 2020/6/18
【更改记录】               无
*************************************************************************/
#include "Question.h"
#include <cstring>

/*************************************************************************
【函数名称】       构造函数
【函数功能】       类内数据初始化
【参数】           无
【返回值】         无
【开发者及日期】   李永健 2020/6/18
【更改记录】       无
*************************************************************************/
Question::Question()
	: sQuestion(m_sQuestion), sOptions(m_sOptions), Type(m_eType)
{
	m_eType = SING_CH;
	m_pcData = nullptr;
}

/*************************************************************************
【函数名称】       构造函数
【函数功能】       类内数据初始化
【参数】           问题和选项的字符串和题目类型
【返回值】         无
【开发者及日期】   李永健 2020/6/18
【更改记录】       无
*************************************************************************/
Question::Question(const string& Qus, const string& OptionA, const string& OptionB,
	const string& OptionC, const string& OptionD, QuestionType Type)
	: sQuestion(m_sQuestion), sOptions(m_sOptions), Type(m_eType)
{
	m_sQuestion = Qus;
	m_sOptions[0] = OptionA;
	m_sOptions[1] = OptionB;
	m_sOptions[2] = OptionC;
	m_sOptions[3] = OptionD;
	m_eType = Type;
	m_pcData = nullptr;
	Encode();
}

/*************************************************************************
【函数名称】       构造函数
【函数功能】       类内数据初始化
【参数】           数据区指针
【返回值】         无
【开发者及日期】   李永健 2020/6/18
【更改记录】       无
*************************************************************************/
Question::Question(const char* pQusDat)
	: sQuestion(m_sQuestion), sOptions(m_sOptions), Type(m_eType)
{
	m_pcData = nullptr;
	SetData(pQusDat);
}

/*************************************************************************
【函数名称】       拷贝构造函数
【函数功能】       初始化时对象的拷贝
【参数】           Question类对象的常引用
【返回值】         无
【开发者及日期】   李永健 2020/6/18
【更改记录】       无
*************************************************************************/
Question::Question(const Question& data)
	: sQuestion(m_sQuestion), sOptions(m_sOptions), Type(m_eType)
{
	m_sQuestion = data.m_sQuestion;
	for (int i = 0; i < 4; i++)
	{
		m_sOptions[i] = data.m_sOptions[i];
	}
	m_eType = data.m_eType;
	m_pcData = nullptr;
	Encode();
}

/*************************************************************************
【函数名称】       析构函数
【函数功能】       对象清理
【参数】           无
【返回值】         无
【开发者及日期】   李永健 2020/6/18
【更改记录】       无
*************************************************************************/
Question::~Question()
{
	if (m_pcData != nullptr)
	{
		delete m_pcData;
	}
}

/*************************************************************************
【函数名称】       赋值运算符重载
【函数功能】       对象的赋值
【参数】           Question类对象的常引用
【返回值】         this指针指向的对象
【开发者及日期】   李永健 2020
【更改记录】       无
*************************************************************************/
Question& Question::operator=(const Question& data)
{
	if (&data != this)
	{
		m_sQuestion = data.m_sQuestion;
		for (int i = 0; i < 4; i++)
		{
			m_sOptions[i] = data.m_sOptions[i];
		}
		m_eType = data.m_eType;
		Encode();
	}
	return *this;
}

/*************************************************************************
【函数名称】       GetData
【函数功能】       获取数据区指针
【参数】           无
【返回值】         数据区的指针
【开发者及日期】   李永健 2020/6/18
【更改记录】       无
*************************************************************************/
const char* Question::GetData() const
{
	return m_pcData;
}

/*************************************************************************
【函数名称】       Size
【函数功能】       获取大小
【参数】           无
【返回值】         数据区大小
【开发者及日期】   李永健 2020/6/18
【更改记录】       无
*************************************************************************/
int Question::Size() const
{
	string sAllInfo = m_sQuestion;
	for (int i = 0; i < 4; i++)//将所有数据存成一个临时字符串
	{
		sAllInfo += m_sOptions[i];
	}
	return (6 * sizeof(int) + sAllInfo.length());
}

/*************************************************************************
【函数名称】       SetData
【函数功能】       将问题从数据解码
【参数】           数据区指针
【返回值】         无
【开发者及日期】   李永健 2020/6/18
【更改记录】       无
*************************************************************************/
void Question::SetData(const char* pQusDat)
{
	const int* piLength = (const int*)pQusDat;//用于读取长度的指针
	m_eType = (QuestionType)piLength[0];//读取题目类型
	int iPos = 6 * sizeof(int);//读取数据的位置
	m_sQuestion = string(pQusDat + iPos, piLength[1]);
	iPos += piLength[1];
	for (int i = 0; i < 4; i++)//读取选项
	{
		m_sOptions[i] = string(pQusDat + iPos, piLength[i + 2]);
		iPos += piLength[i + 2];//读取位置后移
	}
	Encode();
}

/*************************************************************************
【函数名称】       Encode
【函数功能】       将数据存入数据区
【参数】           无
【返回值】         无
【开发者及日期】   李永健 2020/6/18
【更改记录】       无
*************************************************************************/
void Question::Encode()
{
	if (m_pcData != nullptr)
	{
		delete m_pcData;
	}
	string sAllInfo = m_sQuestion;
	for (int i = 0; i < 4; i++)//将所有数据存成一个临时字符串
	{
		sAllInfo += m_sOptions[i];
	}
	m_pcData = new char[6 * sizeof(int) + sAllInfo.length()];//新建数据区
	int* piLength = (int*)m_pcData;//存储长度和问题类型
	piLength[0] = (int)m_eType;
	piLength[1] = m_sQuestion.length();
	for (int i = 0; i < 4; i++)
	{
		piLength[i + 2] = m_sOptions[i].length();
	}
	memcpy(m_pcData + 6 * sizeof(int), sAllInfo.c_str(), sAllInfo.length());//存储题目数据
}