/*************************************************************************
【文件名】                 TimeCount.h
【功能模块和目的】         TimeCount类声明
【开发者及日期】           李永健 2020/6/17
【更改记录】               无
*************************************************************************/
#ifndef _TIMECOUNT_H_
#define _TIMECOUNT_H_

/*************************************************************************
【类名】             TimeCount
【功能】             记录在课堂中的时间和注意力时间
【接口说明】         
	构造函数TimeCount(int TimeInClass = 0, int TimeFocused = 0)
	构造函数TimeCount(const int* dat)
	拷贝构造函数TimeCount(const TimeCount& data)
	析构函数~TimeCount()
	赋值运算符operator=(const TimeCount& data)
	函数SetTimeInClass(int iMilliSecond)设置在课堂时间
	函数SetocusedTime(int iMilliSecond)设置注意力集中时间
	函数GetFocusedRate()返回注意力占百分比
	函数GetHourInClass()及一下两个函数按时分秒获取上课时间
	函数GetMinInClass()
	函数GetSecFocused()
	函数GetHourFocused()及一下两个函数按时分秒获取专注时间
	函数GetMinFocused()
	函数GetSecFocused()
	加法运算符重载operator+(const TimeCount& CToAdd)
	常引用pData返回数据区指针
【开发者及日期】     李永健 2020/6/17
【更改记录】         无
*************************************************************************/
class TimeCount
{
public:
	//构造函数
	TimeCount(int TimeInClass = 0, int TimeFocused = 0);
	//构造函数
	TimeCount(const int* dat);
	//拷贝构造函数
	TimeCount(const TimeCount& data);
	//析构函数
	virtual ~TimeCount();
	//赋值运算符重载
	TimeCount& operator=(const TimeCount& data);
	
	//设置在课堂时间
	void SetTimeInClass(int iMilliSecond);
	//设置注意力集中时间
	void SetFocusedTime(int iMilliSecond);
	//加法运算符重载
	TimeCount operator+(const TimeCount& CToAdd) const;
	//返回注意力占百分比
	int GetFocusedRate() const;
	//在课堂时间按照时分秒获取
	int GetHourInClass() const;
	int GetMinInClass() const;
	int GetSecInClass() const;
	//专注时间按照时分秒获取
	int GetHourFocused() const;
	int GetMinFocused() const;
	int GetSecFocused() const;
	
	//数据的引用
	const int* const Data;
private:
	//数据记录
	int m_iData[2];
};

#endif