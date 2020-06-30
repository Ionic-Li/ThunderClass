/********************************************************************************
** Form generated from reading UI file 'WaitForConnectionWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITFORCONNECTIONWINDOW_H
#define UI_WAITFORCONNECTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WaitForConnectionWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *Hintlabel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *CancelButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *WaitForConnectionWindow)
    {
        if (WaitForConnectionWindow->objectName().isEmpty())
            WaitForConnectionWindow->setObjectName(QString::fromUtf8("WaitForConnectionWindow"));
        WaitForConnectionWindow->resize(613, 140);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WaitForConnectionWindow->sizePolicy().hasHeightForWidth());
        WaitForConnectionWindow->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(WaitForConnectionWindow);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Hintlabel = new QLabel(WaitForConnectionWindow);
        Hintlabel->setObjectName(QString::fromUtf8("Hintlabel"));

        verticalLayout->addWidget(Hintlabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        CancelButton = new QPushButton(WaitForConnectionWindow);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        horizontalLayout->addWidget(CancelButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(WaitForConnectionWindow);

        QMetaObject::connectSlotsByName(WaitForConnectionWindow);
    } // setupUi

    void retranslateUi(QDialog *WaitForConnectionWindow)
    {
        WaitForConnectionWindow->setWindowTitle(QCoreApplication::translate("WaitForConnectionWindow", "WaitForConnectionWindow", nullptr));
        Hintlabel->setText(QCoreApplication::translate("WaitForConnectionWindow", "TextLabel", nullptr));
        CancelButton->setText(QCoreApplication::translate("WaitForConnectionWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaitForConnectionWindow: public Ui_WaitForConnectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITFORCONNECTIONWINDOW_H
