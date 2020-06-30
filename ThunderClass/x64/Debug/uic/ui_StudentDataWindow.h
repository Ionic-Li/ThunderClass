/********************************************************************************
** Form generated from reading UI file 'StudentDataWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTDATAWINDOW_H
#define UI_STUDENTDATAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StudentDataWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QDialog *StudentDataWindow)
    {
        if (StudentDataWindow->objectName().isEmpty())
            StudentDataWindow->setObjectName(QString::fromUtf8("StudentDataWindow"));
        StudentDataWindow->resize(443, 349);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StudentDataWindow->sizePolicy().hasHeightForWidth());
        StudentDataWindow->setSizePolicy(sizePolicy);
        StudentDataWindow->setMinimumSize(QSize(443, 349));
        verticalLayout_2 = new QVBoxLayout(StudentDataWindow);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(StudentDataWindow);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(StudentDataWindow);

        QMetaObject::connectSlotsByName(StudentDataWindow);
    } // setupUi

    void retranslateUi(QDialog *StudentDataWindow)
    {
        StudentDataWindow->setWindowTitle(QCoreApplication::translate("StudentDataWindow", "StudentDataWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentDataWindow: public Ui_StudentDataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDATAWINDOW_H
