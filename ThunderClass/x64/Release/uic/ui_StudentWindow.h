/********************************************************************************
** Form generated from reading UI file 'StudentWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTWINDOW_H
#define UI_STUDENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StudentWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblSharedScreen;
    QLabel *HintLabel;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *TypeLabel;
    QLCDNumber *TimeDisplay;
    QTextBrowser *QuesText;
    QLabel *Enterlabel;
    QLineEdit *AnswerEdit;
    QPushButton *btnSendAns;
    QHBoxLayout *horizontalLayout;
    QLineEdit *edtIP;
    QPushButton *btnEnterClass;
    QPushButton *btnExitClass;
    QSpacerItem *horizontalSpacer;
    QComboBox *cmbChatList;
    QLineEdit *edtChat;
    QPushButton *btnSend;

    void setupUi(QDialog *StudentWindow)
    {
        if (StudentWindow->objectName().isEmpty())
            StudentWindow->setObjectName(QString::fromUtf8("StudentWindow"));
        StudentWindow->resize(941, 663);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StudentWindow->sizePolicy().hasHeightForWidth());
        StudentWindow->setSizePolicy(sizePolicy);
        StudentWindow->setMinimumSize(QSize(941, 663));
        gridLayout = new QGridLayout(StudentWindow);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lblSharedScreen = new QLabel(StudentWindow);
        lblSharedScreen->setObjectName(QString::fromUtf8("lblSharedScreen"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblSharedScreen->sizePolicy().hasHeightForWidth());
        lblSharedScreen->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(lblSharedScreen);

        HintLabel = new QLabel(StudentWindow);
        HintLabel->setObjectName(QString::fromUtf8("HintLabel"));
        HintLabel->setMinimumSize(QSize(0, 20));

        verticalLayout_3->addWidget(HintLabel);

        verticalLayout_3->setStretch(0, 1);

        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        TypeLabel = new QLabel(StudentWindow);
        TypeLabel->setObjectName(QString::fromUtf8("TypeLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TypeLabel->sizePolicy().hasHeightForWidth());
        TypeLabel->setSizePolicy(sizePolicy2);
        TypeLabel->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(TypeLabel);

        TimeDisplay = new QLCDNumber(StudentWindow);
        TimeDisplay->setObjectName(QString::fromUtf8("TimeDisplay"));

        horizontalLayout_4->addWidget(TimeDisplay);


        verticalLayout_2->addLayout(horizontalLayout_4);

        QuesText = new QTextBrowser(StudentWindow);
        QuesText->setObjectName(QString::fromUtf8("QuesText"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(QuesText->sizePolicy().hasHeightForWidth());
        QuesText->setSizePolicy(sizePolicy3);
        QuesText->setMinimumSize(QSize(200, 0));

        verticalLayout_2->addWidget(QuesText);

        Enterlabel = new QLabel(StudentWindow);
        Enterlabel->setObjectName(QString::fromUtf8("Enterlabel"));
        sizePolicy2.setHeightForWidth(Enterlabel->sizePolicy().hasHeightForWidth());
        Enterlabel->setSizePolicy(sizePolicy2);
        Enterlabel->setMinimumSize(QSize(0, 30));

        verticalLayout_2->addWidget(Enterlabel);

        AnswerEdit = new QLineEdit(StudentWindow);
        AnswerEdit->setObjectName(QString::fromUtf8("AnswerEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(AnswerEdit->sizePolicy().hasHeightForWidth());
        AnswerEdit->setSizePolicy(sizePolicy4);
        AnswerEdit->setMinimumSize(QSize(0, 25));

        verticalLayout_2->addWidget(AnswerEdit);

        btnSendAns = new QPushButton(StudentWindow);
        btnSendAns->setObjectName(QString::fromUtf8("btnSendAns"));

        verticalLayout_2->addWidget(btnSendAns);

        verticalLayout_2->setStretch(1, 4);

        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        edtIP = new QLineEdit(StudentWindow);
        edtIP->setObjectName(QString::fromUtf8("edtIP"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(edtIP->sizePolicy().hasHeightForWidth());
        edtIP->setSizePolicy(sizePolicy5);
        edtIP->setClearButtonEnabled(false);

        horizontalLayout->addWidget(edtIP);

        btnEnterClass = new QPushButton(StudentWindow);
        btnEnterClass->setObjectName(QString::fromUtf8("btnEnterClass"));

        horizontalLayout->addWidget(btnEnterClass);

        btnExitClass = new QPushButton(StudentWindow);
        btnExitClass->setObjectName(QString::fromUtf8("btnExitClass"));

        horizontalLayout->addWidget(btnExitClass);

        horizontalSpacer = new QSpacerItem(20, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cmbChatList = new QComboBox(StudentWindow);
        cmbChatList->setObjectName(QString::fromUtf8("cmbChatList"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(cmbChatList->sizePolicy().hasHeightForWidth());
        cmbChatList->setSizePolicy(sizePolicy6);

        horizontalLayout->addWidget(cmbChatList);

        edtChat = new QLineEdit(StudentWindow);
        edtChat->setObjectName(QString::fromUtf8("edtChat"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(edtChat->sizePolicy().hasHeightForWidth());
        edtChat->setSizePolicy(sizePolicy7);

        horizontalLayout->addWidget(edtChat);

        btnSend = new QPushButton(StudentWindow);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));

        horizontalLayout->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);

        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(StudentWindow);

        QMetaObject::connectSlotsByName(StudentWindow);
    } // setupUi

    void retranslateUi(QDialog *StudentWindow)
    {
        StudentWindow->setWindowTitle(QCoreApplication::translate("StudentWindow", "Dialog", nullptr));
        lblSharedScreen->setText(QString());
        HintLabel->setText(QCoreApplication::translate("StudentWindow", "SetText", nullptr));
        TypeLabel->setText(QCoreApplication::translate("StudentWindow", "TextLabel", nullptr));
        Enterlabel->setText(QCoreApplication::translate("StudentWindow", "\350\276\223\345\205\245\347\255\224\346\241\210\357\274\232", nullptr));
        btnSendAns->setText(QCoreApplication::translate("StudentWindow", "\346\217\220\344\272\244\347\255\224\346\241\210", nullptr));
        edtIP->setText(QCoreApplication::translate("StudentWindow", "127.0.0.1", nullptr));
        edtIP->setPlaceholderText(QCoreApplication::translate("StudentWindow", "\350\257\267\350\276\223\345\205\245\346\225\231\345\270\210\347\253\257IP", nullptr));
        btnEnterClass->setText(QCoreApplication::translate("StudentWindow", "\350\277\233\345\205\245\350\257\276\345\240\202", nullptr));
        btnExitClass->setText(QCoreApplication::translate("StudentWindow", "\351\200\200\345\207\272\350\257\276\345\240\202", nullptr));
        btnSend->setText(QCoreApplication::translate("StudentWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentWindow: public Ui_StudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
