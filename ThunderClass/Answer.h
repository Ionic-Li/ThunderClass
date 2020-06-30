/*************************************************************************
【文件名】                 Answer.h
【功能模块和目的】         Answer类声明
【开发者及日期】           李永健 2020/6/18
【更改记录】               无
*************************************************************************/
#ifndef _ANSWER_H_
#define _ANSWER_H_

#include <string>
using namespace std;

/*************************************************************************
【类名】             Answer
【功能】             无
【接口说明】
	构造函数Answer()
	构造函数Answer(string MyAnswer, int MyTime)
	构造函数Answer(const char* pcData)
	拷贝构造函数Answer(const Answer& data)
	析构函数~Answer()
	赋值运算符operator=(const Answer& data)
	函数SetAnswer(const string& MyAnswer)设置答案
	函数SetTime(int MyTime)设置时长
	函数GetAnswer()获取答案
	函数GetTime()获取时长(毫秒)
	函数GetHour()获取小时
	函数GetMin()获取分钟
	函数GetSec()获取秒数
	函数Check(char Option)判断对应选项是否选择
	常引用AswAndTime获取数据区指针
【开发者及日期】     李永健 2020/6/18
【更改记录】         无
*************************************************************************/
class Answer
{
public:
	//构造函数
	Answer();
	//构造函数
	Answer(const string& MyAnswer, int MyTime);
	//构造函数
	Answer(const char* pcData);
	//拷贝构造函数
	Answer(const Answer& data);
	//析构函数
	virtual ~Answer();
	//赋值运算符重载
	Answer& operator=(const Answer& data);

	//设置答案
	void SetAnswer(const string& MyAnswer);
	//设置时长
	void SetTime(int MyTime);
	//获取答案
	string GetAnswer() const;
	//获取时长
	int GetTime() const;
	//按时分秒获取
	int GetHour() const;
	int GetMin() const;
	int GetSec() const;
	//判断是否选择了选项
	bool Check(char Option) const;
	
	//数据区引用
	const char* const AswAndTime;
private:
	//答案以及所用时长，前四位为时长
	char m_cAswAndTime[9];
};

#endif
