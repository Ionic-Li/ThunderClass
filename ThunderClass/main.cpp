/***************************************************************************** 
【文件名】				main.cpp
【功能模块和目的】      雷课堂主函数
【开发者及日期】        李永健 2020/4/24
【更改记录】            
	2020/6/15 由李永健适配更改后的LoginWindow
*****************************************************************************/
#include "LoginWindow.h"
#include "log.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication CThunder(argc, argv);
	LoginWindow CLogin;//登录窗口类
	logInit();
	CLogin.show();
	return CThunder.exec();
}
