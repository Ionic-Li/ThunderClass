/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *label_3;
    QSplitter *splitter;
    QPushButton *LoginButton;
    QPushButton *ExitButton;
    QLabel *label;
    QLineEdit *UserNameLineEdit;
    QLabel *label_2;
    QLineEdit *PassWordLineEdit;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(577, 432);
        LoginWindow->setMinimumSize(QSize(577, 432));
        LoginWindow->setMaximumSize(QSize(577, 432));
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(120, 70, 321, 20));
        label_3->setAlignment(Qt::AlignCenter);
        splitter = new QSplitter(LoginWindow);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(130, 340, 291, 23));
        splitter->setOrientation(Qt::Horizontal);
        LoginButton = new QPushButton(splitter);
        LoginButton->setObjectName(QString::fromUtf8("LoginButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginButton->sizePolicy().hasHeightForWidth());
        LoginButton->setSizePolicy(sizePolicy);
        splitter->addWidget(LoginButton);
        ExitButton = new QPushButton(splitter);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        sizePolicy.setHeightForWidth(ExitButton->sizePolicy().hasHeightForWidth());
        ExitButton->setSizePolicy(sizePolicy);
        splitter->addWidget(ExitButton);
        label = new QLabel(LoginWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(143, 172, 71, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        UserNameLineEdit = new QLineEdit(LoginWindow);
        UserNameLineEdit->setObjectName(QString::fromUtf8("UserNameLineEdit"));
        UserNameLineEdit->setGeometry(QRect(220, 170, 161, 21));
        sizePolicy.setHeightForWidth(UserNameLineEdit->sizePolicy().hasHeightForWidth());
        UserNameLineEdit->setSizePolicy(sizePolicy);
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 231, 71, 20));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        PassWordLineEdit = new QLineEdit(LoginWindow);
        PassWordLineEdit->setObjectName(QString::fromUtf8("PassWordLineEdit"));
        PassWordLineEdit->setGeometry(QRect(220, 230, 161, 21));
        QWidget::setTabOrder(UserNameLineEdit, PassWordLineEdit);
        QWidget::setTabOrder(PassWordLineEdit, LoginButton);
        QWidget::setTabOrder(LoginButton, ExitButton);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\345\222\214\345\257\206\347\240\201\344\273\245\347\231\273\345\275\225\351\233\267\350\257\276\345\240\202", nullptr));
        LoginButton->setText(QCoreApplication::translate("LoginWindow", "\347\241\256\345\256\232", nullptr));
        ExitButton->setText(QCoreApplication::translate("LoginWindow", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
