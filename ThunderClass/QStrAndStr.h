/*************************************************************************
【文件名】                 QStrAndStr.h
【功能模块和目的】         避免中文乱码问题的函数
【开发者及日期】           李永健 2020/6/19
【更改记录】               无
*************************************************************************/
#ifndef _QSTRANDSTR_H_
#define _QSTRANDSTR_H_

#include <string>
#include <QString>
using std::string;

//从QString转成string
string QStrToStr(const QString qstr);
//从string转成QString
QString StrToQStr(const string str);

#endif // !_QSTRANDSTR_H_
