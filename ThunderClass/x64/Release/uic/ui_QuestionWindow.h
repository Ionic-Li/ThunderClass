/********************************************************************************
** Form generated from reading UI file 'QuestionWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONWINDOW_H
#define UI_QUESTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionWindow
{
public:
    QLCDNumber *TimeDisplay;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *QuestionEdit;
    QHBoxLayout *horizontalLayout_2;
    QSplitter *splitter;
    QRadioButton *SingleButton;
    QRadioButton *MultipleButton;
    QGridLayout *gridLayout;
    QLineEdit *BLineEdit;
    QLabel *label_2;
    QLineEdit *CLineEdit;
    QLabel *label_3;
    QLineEdit *ALineEdit;
    QLabel *label_4;
    QLineEdit *DLineEdit;
    QLabel *label;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *SendButton;
    QPushButton *StopButton;

    void setupUi(QDialog *QuestionWindow)
    {
        if (QuestionWindow->objectName().isEmpty())
            QuestionWindow->setObjectName(QString::fromUtf8("QuestionWindow"));
        QuestionWindow->resize(544, 488);
        TimeDisplay = new QLCDNumber(QuestionWindow);
        TimeDisplay->setObjectName(QString::fromUtf8("TimeDisplay"));
        TimeDisplay->setGeometry(QRect(50, 20, 81, 31));
        layoutWidget = new QWidget(QuestionWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 60, 441, 341));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        QuestionEdit = new QTextEdit(layoutWidget);
        QuestionEdit->setObjectName(QString::fromUtf8("QuestionEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QuestionEdit->sizePolicy().hasHeightForWidth());
        QuestionEdit->setSizePolicy(sizePolicy);
        QuestionEdit->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \344\273\277\345\256\213 Std R"));
        font.setPointSize(12);
        QuestionEdit->setFont(font);

        verticalLayout->addWidget(QuestionEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        splitter = new QSplitter(layoutWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(false);
        splitter->setHandleWidth(5);
        SingleButton = new QRadioButton(splitter);
        SingleButton->setObjectName(QString::fromUtf8("SingleButton"));
        splitter->addWidget(SingleButton);
        MultipleButton = new QRadioButton(splitter);
        MultipleButton->setObjectName(QString::fromUtf8("MultipleButton"));
        splitter->addWidget(MultipleButton);

        horizontalLayout_2->addWidget(splitter);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(23);
        BLineEdit = new QLineEdit(layoutWidget);
        BLineEdit->setObjectName(QString::fromUtf8("BLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(BLineEdit->sizePolicy().hasHeightForWidth());
        BLineEdit->setSizePolicy(sizePolicy1);
        BLineEdit->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setPointSize(11);
        BLineEdit->setFont(font1);

        gridLayout->addWidget(BLineEdit, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(15);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setMargin(0);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        CLineEdit = new QLineEdit(layoutWidget);
        CLineEdit->setObjectName(QString::fromUtf8("CLineEdit"));
        sizePolicy1.setHeightForWidth(CLineEdit->sizePolicy().hasHeightForWidth());
        CLineEdit->setSizePolicy(sizePolicy1);
        CLineEdit->setMaximumSize(QSize(16777215, 30));
        CLineEdit->setFont(font1);

        gridLayout->addWidget(CLineEdit, 2, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setMargin(0);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        ALineEdit = new QLineEdit(layoutWidget);
        ALineEdit->setObjectName(QString::fromUtf8("ALineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ALineEdit->sizePolicy().hasHeightForWidth());
        ALineEdit->setSizePolicy(sizePolicy2);
        ALineEdit->setMaximumSize(QSize(16777215, 30));
        QFont font3;
        font3.setPointSize(11);
        font3.setItalic(false);
        ALineEdit->setFont(font3);

        gridLayout->addWidget(ALineEdit, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setMargin(0);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        DLineEdit = new QLineEdit(layoutWidget);
        DLineEdit->setObjectName(QString::fromUtf8("DLineEdit"));
        sizePolicy2.setHeightForWidth(DLineEdit->sizePolicy().hasHeightForWidth());
        DLineEdit->setSizePolicy(sizePolicy2);
        DLineEdit->setMaximumSize(QSize(16777215, 30));
        DLineEdit->setFont(font1);

        gridLayout->addWidget(DLineEdit, 3, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(15);
        font4.setItalic(false);
        font4.setUnderline(false);
        label->setFont(font4);
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(0);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        gridLayout->setRowStretch(0, 10);
        gridLayout->setRowStretch(1, 10);
        gridLayout->setRowStretch(2, 10);
        gridLayout->setRowStretch(3, 10);

        verticalLayout->addLayout(gridLayout);

        layoutWidget1 = new QWidget(QuestionWindow);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 420, 441, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(100);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        SendButton = new QPushButton(layoutWidget1);
        SendButton->setObjectName(QString::fromUtf8("SendButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(SendButton->sizePolicy().hasHeightForWidth());
        SendButton->setSizePolicy(sizePolicy3);
        SendButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(SendButton);

        StopButton = new QPushButton(layoutWidget1);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        sizePolicy3.setHeightForWidth(StopButton->sizePolicy().hasHeightForWidth());
        StopButton->setSizePolicy(sizePolicy3);
        StopButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(StopButton);


        retranslateUi(QuestionWindow);

        QMetaObject::connectSlotsByName(QuestionWindow);
    } // setupUi

    void retranslateUi(QDialog *QuestionWindow)
    {
        QuestionWindow->setWindowTitle(QCoreApplication::translate("QuestionWindow", "QuestionWindow", nullptr));
        QuestionEdit->setHtml(QCoreApplication::translate("QuestionWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Adobe \344\273\277\345\256\213 Std R'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        SingleButton->setText(QCoreApplication::translate("QuestionWindow", "\345\215\225\351\200\211\351\242\230", nullptr));
        MultipleButton->setText(QCoreApplication::translate("QuestionWindow", "\345\244\232\351\200\211\351\242\230", nullptr));
        label_2->setText(QCoreApplication::translate("QuestionWindow", "B", nullptr));
        label_3->setText(QCoreApplication::translate("QuestionWindow", "C", nullptr));
        ALineEdit->setText(QString());
        label_4->setText(QCoreApplication::translate("QuestionWindow", "D", nullptr));
        label->setText(QCoreApplication::translate("QuestionWindow", "A", nullptr));
        SendButton->setText(QCoreApplication::translate("QuestionWindow", "\345\217\221\351\242\230", nullptr));
        StopButton->setText(QCoreApplication::translate("QuestionWindow", "\346\224\266\351\242\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionWindow: public Ui_QuestionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONWINDOW_H
