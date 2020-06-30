/********************************************************************************
** Form generated from reading UI file 'TeacherWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERWINDOW_H
#define UI_TEACHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TeacherWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnBeginClass;
    QCheckBox *ckbScreenShare;
    QCheckBox *ckbVoiceShare;
    QPushButton *btnRandCall;
    QPushButton *btnSendQues;
    QPushButton *btnEndClass;
    QHBoxLayout *horizontalLayout;
    QLineEdit *edtChat;
    QPushButton *btnSend;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *cmbStudent;
    QComboBox *cmbChatList;

    void setupUi(QDialog *TeacherWindow)
    {
        if (TeacherWindow->objectName().isEmpty())
            TeacherWindow->setObjectName(QString::fromUtf8("TeacherWindow"));
        TeacherWindow->resize(783, 81);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TeacherWindow->sizePolicy().hasHeightForWidth());
        TeacherWindow->setSizePolicy(sizePolicy);
        TeacherWindow->setModal(false);
        gridLayout = new QGridLayout(TeacherWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 6);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnBeginClass = new QPushButton(TeacherWindow);
        btnBeginClass->setObjectName(QString::fromUtf8("btnBeginClass"));

        horizontalLayout_2->addWidget(btnBeginClass);

        ckbScreenShare = new QCheckBox(TeacherWindow);
        ckbScreenShare->setObjectName(QString::fromUtf8("ckbScreenShare"));

        horizontalLayout_2->addWidget(ckbScreenShare);

        ckbVoiceShare = new QCheckBox(TeacherWindow);
        ckbVoiceShare->setObjectName(QString::fromUtf8("ckbVoiceShare"));

        horizontalLayout_2->addWidget(ckbVoiceShare);

        btnRandCall = new QPushButton(TeacherWindow);
        btnRandCall->setObjectName(QString::fromUtf8("btnRandCall"));

        horizontalLayout_2->addWidget(btnRandCall);

        btnSendQues = new QPushButton(TeacherWindow);
        btnSendQues->setObjectName(QString::fromUtf8("btnSendQues"));

        horizontalLayout_2->addWidget(btnSendQues);

        btnEndClass = new QPushButton(TeacherWindow);
        btnEndClass->setObjectName(QString::fromUtf8("btnEndClass"));

        horizontalLayout_2->addWidget(btnEndClass);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        edtChat = new QLineEdit(TeacherWindow);
        edtChat->setObjectName(QString::fromUtf8("edtChat"));
        edtChat->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(edtChat);

        btnSend = new QPushButton(TeacherWindow);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnSend->sizePolicy().hasHeightForWidth());
        btnSend->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnSend);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        cmbStudent = new QComboBox(TeacherWindow);
        cmbStudent->setObjectName(QString::fromUtf8("cmbStudent"));

        horizontalLayout_4->addWidget(cmbStudent);

        cmbChatList = new QComboBox(TeacherWindow);
        cmbChatList->setObjectName(QString::fromUtf8("cmbChatList"));

        horizontalLayout_4->addWidget(cmbChatList);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(TeacherWindow);

        QMetaObject::connectSlotsByName(TeacherWindow);
    } // setupUi

    void retranslateUi(QDialog *TeacherWindow)
    {
        TeacherWindow->setWindowTitle(QCoreApplication::translate("TeacherWindow", "\346\225\231\345\270\210\345\267\262\347\231\273\345\275\225", nullptr));
        btnBeginClass->setText(QCoreApplication::translate("TeacherWindow", "\344\270\212\350\257\276", nullptr));
        ckbScreenShare->setText(QCoreApplication::translate("TeacherWindow", "\345\205\261\344\272\253\345\261\217\345\271\225", nullptr));
        ckbVoiceShare->setText(QCoreApplication::translate("TeacherWindow", "\345\217\221\351\200\201\351\200\201\350\257\255\351\237\263", nullptr));
        btnRandCall->setText(QCoreApplication::translate("TeacherWindow", "\351\232\217\346\234\272\346\217\220\351\227\256", nullptr));
        btnSendQues->setText(QCoreApplication::translate("TeacherWindow", "\345\217\221\351\242\230", nullptr));
        btnEndClass->setText(QCoreApplication::translate("TeacherWindow", "\344\270\213\350\257\276", nullptr));
        btnSend->setText(QCoreApplication::translate("TeacherWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherWindow: public Ui_TeacherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWINDOW_H
