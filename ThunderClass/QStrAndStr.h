/*************************************************************************
���ļ�����                 QStrAndStr.h
������ģ���Ŀ�ġ�         ����������������ĺ���
�������߼����ڡ�           ������ 2020/6/19
�����ļ�¼��               ��
*************************************************************************/
#ifndef _QSTRANDSTR_H_
#define _QSTRANDSTR_H_

#include <string>
#include <QString>
using std::string;

//��QStringת��string
string QStrToStr(const QString qstr);
//��stringת��QString
QString StrToQStr(const string str);

#endif // !_QSTRANDSTR_H_
