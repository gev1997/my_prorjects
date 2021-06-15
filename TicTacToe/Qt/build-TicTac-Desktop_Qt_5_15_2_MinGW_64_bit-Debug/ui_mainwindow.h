/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 0));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color:  #f0f0f0;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 80, 80));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #f3f3f3;\n"
"color: #00557f;\n"
"font: bold 50px;\n"
"border: 1px solid #e3e3e3;\n"
"border-radius: 2px;"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 10, 80, 80));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #f3f3f3;\n"
"color: #00557f;\n"
"font: bold 50px;\n"
"border: 1px solid #e3e3e3;\n"
"border-radius: 2px;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 10, 80, 80));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: #f3f3f3;\n"
"color: #00557f;\n"
"font: bold 50px;\n"
"border: 1px solid #e3e3e3;\n"
"border-radius: 2px;"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 90, 80, 80));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: #f3f3f3;\n"
"color: #00557f;\n"
"font: bold 50px;\n"
"border: 1px solid #e3e3e3;\n"
"border-radius: 2px;"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(90, 90, 80, 80));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: #f3f3f3;\n"
"color: #00557f;\n"
"font: bold 50px;\n"
"border: 1px solid #e3e3e3;\n"
"border-radius: 2px;"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(170, 90, 80, 80));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: #f3f3f3;\n"
"color: #00557f;\n"
"font: bold 50px;\n"
"border: 1px solid #e3e3e3;\n"
"border-radius: 2px;"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 170, 80, 80));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: #f3f3f3;\n"
"color: #00557f;\n"
"font: bold 50px;\n"
"border: 1px solid #e3e3e3;\n"
"border-radius: 2px;"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(90, 170, 80, 80));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: #f3f3f3;\n"
"color: #00557f;\n"
"font: bold 50px;\n"
"border: 1px solid #e3e3e3;\n"
"border-radius: 2px;"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(170, 170, 80, 80));
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: #f3f3f3;\n"
"color: #00557f;\n"
"font: bold 50px;\n"
"border: 1px solid #e3e3e3;\n"
"border-radius: 2px;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Tic Tac Toe", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
