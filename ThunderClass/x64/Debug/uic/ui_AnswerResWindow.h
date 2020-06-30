/********************************************************************************
** Form generated from reading UI file 'AnswerResWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANSWERRESWINDOW_H
#define UI_ANSWERRESWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AnswerResWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *StuResView;
    QLabel *label_2;
    QTableView *AnsResView;

    void setupUi(QDialog *AnswerResWindow)
    {
        if (AnswerResWindow->objectName().isEmpty())
            AnswerResWindow->setObjectName(QString::fromUtf8("AnswerResWindow"));
        AnswerResWindow->resize(618, 510);
        AnswerResWindow->setMinimumSize(QSize(618, 510));
        verticalLayout_2 = new QVBoxLayout(AnswerResWindow);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(AnswerResWindow);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        StuResView = new QTableView(AnswerResWindow);
        StuResView->setObjectName(QString::fromUtf8("StuResView"));

        verticalLayout->addWidget(StuResView);

        label_2 = new QLabel(AnswerResWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        AnsResView = new QTableView(AnswerResWindow);
        AnsResView->setObjectName(QString::fromUtf8("AnsResView"));

        verticalLayout->addWidget(AnsResView);

        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(3, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AnswerResWindow);

        QMetaObject::connectSlotsByName(AnswerResWindow);
    } // setupUi

    void retranslateUi(QDialog *AnswerResWindow)
    {
        AnswerResWindow->setWindowTitle(QCoreApplication::translate("AnswerResWindow", "AnswerResWindow", nullptr));
        label->setText(QCoreApplication::translate("AnswerResWindow", "\345\255\246\347\224\237\344\275\234\347\255\224\346\203\205\345\206\265", nullptr));
        label_2->setText(QCoreApplication::translate("AnswerResWindow", "\351\200\211\351\241\271\351\200\211\346\213\251\346\203\205\345\206\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnswerResWindow: public Ui_AnswerResWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANSWERRESWINDOW_H
