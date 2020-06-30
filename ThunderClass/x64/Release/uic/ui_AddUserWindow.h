/********************************************************************************
** Form generated from reading UI file 'AddUserWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERWINDOW_H
#define UI_ADDUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddUserWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *UserName;
    QLineEdit *PassWord;
    QLineEdit *UserType;
    QPushButton *ConfirmButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *AddUserWindow)
    {
        if (AddUserWindow->objectName().isEmpty())
            AddUserWindow->setObjectName(QString::fromUtf8("AddUserWindow"));
        AddUserWindow->resize(400, 402);
        AddUserWindow->setMinimumSize(QSize(400, 402));
        AddUserWindow->setMaximumSize(QSize(400, 402));
        label = new QLabel(AddUserWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(83, 120, 71, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(AddUserWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(53, 160, 101, 21));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(AddUserWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(63, 200, 91, 21));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        UserName = new QLineEdit(AddUserWindow);
        UserName->setObjectName(QString::fromUtf8("UserName"));
        UserName->setGeometry(QRect(170, 120, 113, 21));
        PassWord = new QLineEdit(AddUserWindow);
        PassWord->setObjectName(QString::fromUtf8("PassWord"));
        PassWord->setGeometry(QRect(170, 160, 113, 21));
        UserType = new QLineEdit(AddUserWindow);
        UserType->setObjectName(QString::fromUtf8("UserType"));
        UserType->setGeometry(QRect(170, 200, 113, 21));
        ConfirmButton = new QPushButton(AddUserWindow);
        ConfirmButton->setObjectName(QString::fromUtf8("ConfirmButton"));
        ConfirmButton->setGeometry(QRect(100, 290, 75, 23));
        CancelButton = new QPushButton(AddUserWindow);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setGeometry(QRect(230, 290, 75, 23));

        retranslateUi(AddUserWindow);

        QMetaObject::connectSlotsByName(AddUserWindow);
    } // setupUi

    void retranslateUi(QDialog *AddUserWindow)
    {
        AddUserWindow->setWindowTitle(QCoreApplication::translate("AddUserWindow", "AddUserWindow", nullptr));
        label->setText(QCoreApplication::translate("AddUserWindow", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_2->setText(QCoreApplication::translate("AddUserWindow", "\345\257\206\347\240\201:", nullptr));
        label_3->setText(QCoreApplication::translate("AddUserWindow", "\347\224\250\346\210\267\347\261\273\345\236\213:", nullptr));
        ConfirmButton->setText(QCoreApplication::translate("AddUserWindow", "\347\241\256\345\256\232", nullptr));
        CancelButton->setText(QCoreApplication::translate("AddUserWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddUserWindow: public Ui_AddUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERWINDOW_H
