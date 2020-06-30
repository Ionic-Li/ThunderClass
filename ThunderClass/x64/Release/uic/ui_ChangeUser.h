/********************************************************************************
** Form generated from reading UI file 'ChangeUser.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEUSER_H
#define UI_CHANGEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChangeUser
{
public:
    QPushButton *CancelButton;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *ConfirmButton;
    QLabel *label;
    QLineEdit *UserName;
    QLineEdit *PassWord;
    QLineEdit *UserType;

    void setupUi(QDialog *ChangeUser)
    {
        if (ChangeUser->objectName().isEmpty())
            ChangeUser->setObjectName(QString::fromUtf8("ChangeUser"));
        ChangeUser->resize(415, 405);
        ChangeUser->setMinimumSize(QSize(415, 405));
        ChangeUser->setMaximumSize(QSize(415, 405));
        CancelButton = new QPushButton(ChangeUser);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setGeometry(QRect(250, 300, 75, 23));
        label_3 = new QLabel(ChangeUser);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(63, 210, 111, 21));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(ChangeUser);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(83, 170, 91, 21));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ConfirmButton = new QPushButton(ChangeUser);
        ConfirmButton->setObjectName(QString::fromUtf8("ConfirmButton"));
        ConfirmButton->setGeometry(QRect(120, 300, 75, 23));
        label = new QLabel(ChangeUser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(93, 130, 81, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        UserName = new QLineEdit(ChangeUser);
        UserName->setObjectName(QString::fromUtf8("UserName"));
        UserName->setGeometry(QRect(190, 130, 113, 21));
        PassWord = new QLineEdit(ChangeUser);
        PassWord->setObjectName(QString::fromUtf8("PassWord"));
        PassWord->setGeometry(QRect(190, 170, 113, 21));
        UserType = new QLineEdit(ChangeUser);
        UserType->setObjectName(QString::fromUtf8("UserType"));
        UserType->setGeometry(QRect(190, 210, 113, 21));
        QWidget::setTabOrder(UserName, PassWord);
        QWidget::setTabOrder(PassWord, UserType);
        QWidget::setTabOrder(UserType, ConfirmButton);
        QWidget::setTabOrder(ConfirmButton, CancelButton);

        retranslateUi(ChangeUser);

        QMetaObject::connectSlotsByName(ChangeUser);
    } // setupUi

    void retranslateUi(QDialog *ChangeUser)
    {
        ChangeUser->setWindowTitle(QCoreApplication::translate("ChangeUser", "ChangeUser", nullptr));
        CancelButton->setText(QCoreApplication::translate("ChangeUser", "\345\217\226\346\266\210", nullptr));
        label_3->setText(QCoreApplication::translate("ChangeUser", "\347\224\250\346\210\267\347\261\273\345\236\213:", nullptr));
        label_2->setText(QCoreApplication::translate("ChangeUser", "\345\257\206\347\240\201:", nullptr));
        ConfirmButton->setText(QCoreApplication::translate("ChangeUser", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("ChangeUser", "\347\224\250\346\210\267\345\220\215:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeUser: public Ui_ChangeUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEUSER_H
