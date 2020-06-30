/*************************************************************************
【文件名】                 Question.h
【功能模块和目的】         Question类声明
【开发者及日期】           李永健 2020/6/18
【更改记录】               无
*************************************************************************/
#ifndef _QUESTION_H_
#define _QUESTION_H_

#include <string>
using namespace std;

enum QuestionType
{
	SING_CH, MULTI_CH
};

/*************************************************************************
【类名】             Question
【功能】             题目类
【接口说明】
	构造函数Question()
	构造函数Question(const string& Qus, const string& OptionA, const string& OptionB, const string& OptionC, const string& OptionD)
	构造函数Question(const char* pQusDat)
	拷贝构造函数Question(const Question& data)
	析构函数~Question()
	赋值运算符operator=(const Question& data)
	函数GetData()获取数据区指针
	函数Size()获取数据区大小
	常引用sQuestion获取问题
	常引用sOptions获取选项
	常引用Type获取类型
【开发者及日期】     李永健 2020/6/18
【更改记录】         无
*************************************************************************/
class Question
{
public:
	//构造函数
	Question();
	//构造函数
	Question(const string& Qus, const string& OptionA, const string& OptionB,
		const string& OptionC, const string& OptionD, QuestionType Type);
	//构造函数
	Question(const char* pQusDat);
	//拷贝构造函数
	Question(const Question& data);
	//析构函数
	virtual ~Question();
	//赋值运算符重载
	Question& operator=(const Question& data);

	//获取数据区指针
	const char* GetData() const;
	//获取大小
	int Size() const;

	//数据的读取
	const string& sQuestion;
	const string* const sOptions;
	const QuestionType& Type;
private:
	//将问题从数据解码
	void SetData(const char* pQusDat);
	//将数据存入数据区
	void Encode();

	//问题和四个选项
	string m_sQuestion;
	string m_sOptions[4];
	QuestionType m_eType;
	//数据区
	char* m_pcData;
};

#endif