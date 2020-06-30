/********************************************************************************
** Form generated from reading UI file 'AdminWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *Information;
    QTableView *StuView;
    QGroupBox *Detailed;
    QListWidget *DetailInfo;
    QPushButton *DelButton;
    QPushButton *AddButton;
    QLineEdit *TargetName;
    QPushButton *SearchButton;
    QPushButton *ExitButton;
    QPushButton *ModButton;
    QStatusBar *statusBar;

    void setupUi(QDialog *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->setWindowModality(Qt::ApplicationModal);
        AdminWindow->resize(791, 554);
        AdminWindow->setMinimumSize(QSize(791, 554));
        AdminWindow->setMaximumSize(QSize(791, 554));
        centralWidget = new QWidget(AdminWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Information = new QGroupBox(centralWidget);
        Information->setObjectName(QString::fromUtf8("Information"));
        Information->setGeometry(QRect(0, 10, 501, 521));
        StuView = new QTableView(Information);
        StuView->setObjectName(QString::fromUtf8("StuView"));
        StuView->setGeometry(QRect(10, 20, 481, 491));
        StuView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        StuView->setAlternatingRowColors(true);
        StuView->setSelectionMode(QAbstractItemView::SingleSelection);
        StuView->setSelectionBehavior(QAbstractItemView::SelectRows);
        StuView->setShowGrid(false);
        Detailed = new QGroupBox(centralWidget);
        Detailed->setObjectName(QString::fromUtf8("Detailed"));
        Detailed->setGeometry(QRect(510, 10, 271, 531));
        DetailInfo = new QListWidget(Detailed);
        DetailInfo->setObjectName(QString::fromUtf8("DetailInfo"));
        DetailInfo->setGeometry(QRect(10, 20, 251, 321));
        DelButton = new QPushButton(Detailed);
        DelButton->setObjectName(QString::fromUtf8("DelButton"));
        DelButton->setGeometry(QRect(10, 360, 121, 31));
        AddButton = new QPushButton(Detailed);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(140, 360, 121, 31));
        TargetName = new QLineEdit(Detailed);
        TargetName->setObjectName(QString::fromUtf8("TargetName"));
        TargetName->setGeometry(QRect(10, 420, 121, 31));
        SearchButton = new QPushButton(Detailed);
        SearchButton->setObjectName(QString::fromUtf8("SearchButton"));
        SearchButton->setGeometry(QRect(140, 420, 121, 31));
        ExitButton = new QPushButton(Detailed);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        ExitButton->setGeometry(QRect(139, 483, 121, 31));
        ModButton = new QPushButton(Detailed);
        ModButton->setObjectName(QString::fromUtf8("ModButton"));
        ModButton->setGeometry(QRect(11, 483, 121, 31));
        statusBar = new QStatusBar(AdminWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QWidget::setTabOrder(StuView, DetailInfo);
        QWidget::setTabOrder(DetailInfo, DelButton);
        QWidget::setTabOrder(DelButton, AddButton);
        QWidget::setTabOrder(AddButton, TargetName);
        QWidget::setTabOrder(TargetName, SearchButton);
        QWidget::setTabOrder(SearchButton, ModButton);
        QWidget::setTabOrder(ModButton, ExitButton);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "AdminWindow", nullptr));
        Information->setTitle(QCoreApplication::translate("AdminWindow", "\347\224\250\346\210\267\344\277\241\346\201\257", nullptr));
        Detailed->setTitle(QCoreApplication::translate("AdminWindow", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        DelButton->setText(QCoreApplication::translate("AdminWindow", "\345\210\240\351\231\244", nullptr));
        AddButton->setText(QCoreApplication::translate("AdminWindow", "\346\267\273\345\212\240", nullptr));
        SearchButton->setText(QCoreApplication::translate("AdminWindow", "\346\237\245\346\211\276", nullptr));
        ExitButton->setText(QCoreApplication::translate("AdminWindow", "\351\200\200\345\207\272", nullptr));
        ModButton->setText(QCoreApplication::translate("AdminWindow", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
