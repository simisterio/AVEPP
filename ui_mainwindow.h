/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QScrollArea *scrollArea_Video;
    QWidget *scrollAreaWidgetContents;
    QPushButton *Button_tipo_trabajo;
    QPushButton *Button_casco;
    QPushButton *Button_guantes;
    QPushButton *Button_mascara;
    QPushButton *Button_chaleco;
    QPushButton *Button_reset;
    QPushButton *Button_salir;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 720);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        scrollArea_Video = new QScrollArea(centralWidget);
        scrollArea_Video->setObjectName(QStringLiteral("scrollArea_Video"));
        scrollArea_Video->setGeometry(QRect(20, 20, 850, 630));
        scrollArea_Video->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 848, 628));
        scrollArea_Video->setWidget(scrollAreaWidgetContents);
        Button_tipo_trabajo = new QPushButton(centralWidget);
        Button_tipo_trabajo->setObjectName(QStringLiteral("Button_tipo_trabajo"));
        Button_tipo_trabajo->setGeometry(QRect(970, 20, 181, 51));
        QFont font;
        font.setPointSize(13);
        Button_tipo_trabajo->setFont(font);
        Button_casco = new QPushButton(centralWidget);
        Button_casco->setObjectName(QStringLiteral("Button_casco"));
        Button_casco->setGeometry(QRect(900, 140, 150, 40));
        QFont font1;
        font1.setPointSize(11);
        Button_casco->setFont(font1);
        Button_guantes = new QPushButton(centralWidget);
        Button_guantes->setObjectName(QStringLiteral("Button_guantes"));
        Button_guantes->setGeometry(QRect(900, 250, 150, 40));
        Button_guantes->setFont(font1);
        Button_mascara = new QPushButton(centralWidget);
        Button_mascara->setObjectName(QStringLiteral("Button_mascara"));
        Button_mascara->setGeometry(QRect(900, 360, 150, 40));
        Button_mascara->setFont(font1);
        Button_chaleco = new QPushButton(centralWidget);
        Button_chaleco->setObjectName(QStringLiteral("Button_chaleco"));
        Button_chaleco->setGeometry(QRect(900, 470, 150, 40));
        Button_chaleco->setFont(font1);
        Button_reset = new QPushButton(centralWidget);
        Button_reset->setObjectName(QStringLiteral("Button_reset"));
        Button_reset->setGeometry(QRect(930, 580, 121, 41));
        QFont font2;
        font2.setPointSize(12);
        Button_reset->setFont(font2);
        Button_salir = new QPushButton(centralWidget);
        Button_salir->setObjectName(QStringLiteral("Button_salir"));
        Button_salir->setGeometry(QRect(1060, 580, 121, 41));
        Button_salir->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Button_tipo_trabajo->setText(QApplication::translate("MainWindow", "Tipo Trabajo", 0));
        Button_casco->setText(QApplication::translate("MainWindow", "Casco", 0));
        Button_guantes->setText(QApplication::translate("MainWindow", "Guantes", 0));
        Button_mascara->setText(QApplication::translate("MainWindow", "M\303\241scara", 0));
        Button_chaleco->setText(QApplication::translate("MainWindow", "Chaleco", 0));
        Button_reset->setText(QApplication::translate("MainWindow", "Reset", 0));
        Button_salir->setText(QApplication::translate("MainWindow", "Salir", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
