/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *EInput;
    QPushButton *colorButton;
    QCheckBox *breaksCheckBox;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QPushButton *undoButton;
    QPushButton *resetButton;
    QMenuBar *menubar;
    QAction *actionEnglish;
    QAction *actionRussian;
    QAction *actionGerman;
    QAction *actionFrench;
    QAction *actionChinese;
    QAction *actionJapanese;
    QAction *actionSpanish;
    QAction *actionLightTheme;
    QAction *actionDarkTheme;
    QAction *actionToggleNativeWidgets;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuLanguage;
    QMenu *menuTheme;
    QMenu *menuAdaptation;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        MainWindow->setFont(font);
        MainWindow->setCursor(QCursor(Qt::CursorShape::CrossCursor));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        actionOpen->setFont(font1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave->setFont(font1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        EInput = new QLineEdit(centralwidget);
        EInput->setObjectName("EInput");
        EInput->setEnabled(true);

        horizontalLayout->addWidget(EInput);

        colorButton = new QPushButton(centralwidget);
        colorButton->setObjectName("colorButton");

        horizontalLayout->addWidget(colorButton);

        breaksCheckBox = new QCheckBox(centralwidget);
        breaksCheckBox->setObjectName("breaksCheckBox");

        horizontalLayout->addWidget(breaksCheckBox);

        zoomInButton = new QPushButton(centralwidget);
        zoomInButton->setObjectName("zoomInButton");

        horizontalLayout->addWidget(zoomInButton);

        zoomOutButton = new QPushButton(centralwidget);
        zoomOutButton->setObjectName("zoomOutButton");

        horizontalLayout->addWidget(zoomOutButton);

        undoButton = new QPushButton(centralwidget);
        undoButton->setObjectName("undoButton");

        horizontalLayout->addWidget(undoButton);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");

        horizontalLayout->addWidget(resetButton);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        actionEnglish = new QAction(menubar);
        actionEnglish->setObjectName("actionEnglish");
        actionEnglish->setFont(font1);
        actionRussian = new QAction(menubar);
        actionRussian->setObjectName("actionRussian");
        actionRussian->setFont(font1);
        actionGerman = new QAction(menubar);
        actionGerman->setObjectName("actionGerman");
        actionGerman->setFont(font1);
        actionFrench = new QAction(menubar);
        actionFrench->setObjectName("actionFrench");
        actionFrench->setFont(font1);
        actionChinese = new QAction(menubar);
        actionChinese->setObjectName("actionChinese");
        actionChinese->setFont(font1);
        actionJapanese = new QAction(menubar);
        actionJapanese->setObjectName("actionJapanese");
        actionJapanese->setFont(font1);
        actionSpanish = new QAction(menubar);
        actionSpanish->setObjectName("actionSpanish");
        actionSpanish->setFont(font1);
        actionLightTheme = new QAction(menubar);
        actionLightTheme->setObjectName("actionLightTheme");
        actionLightTheme->setFont(font1);
        actionDarkTheme = new QAction(menubar);
        actionDarkTheme->setObjectName("actionDarkTheme");
        actionDarkTheme->setFont(font1);
        actionToggleNativeWidgets = new QAction(menubar);
        actionToggleNativeWidgets->setObjectName("actionToggleNativeWidgets");
        actionToggleNativeWidgets->setCheckable(true);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        menuSettings->setFont(font1);
        menuLanguage = new QMenu(menuSettings);
        menuLanguage->setObjectName("menuLanguage");
        menuLanguage->setFont(font1);
        menuTheme = new QMenu(menuSettings);
        menuTheme->setObjectName("menuTheme");
        menuAdaptation = new QMenu(menuSettings);
        menuAdaptation->setObjectName("menuAdaptation");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuSettings->addAction(menuLanguage->menuAction());
        menuSettings->addAction(menuTheme->menuAction());
        menuSettings->addAction(menuAdaptation->menuAction());
        menuLanguage->addAction(actionEnglish);
        menuLanguage->addAction(actionRussian);
        menuLanguage->addAction(actionGerman);
        menuLanguage->addAction(actionFrench);
        menuLanguage->addAction(actionChinese);
        menuLanguage->addAction(actionJapanese);
        menuLanguage->addAction(actionSpanish);
        menuTheme->addAction(actionLightTheme);
        menuTheme->addAction(actionDarkTheme);
        menuAdaptation->addAction(actionToggleNativeWidgets);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Medical Image Processor", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "E:", nullptr));
        EInput->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        colorButton->setText(QCoreApplication::translate("MainWindow", "Fill Color", nullptr));
        breaksCheckBox->setText(QCoreApplication::translate("MainWindow", "Breaks", nullptr));
        zoomInButton->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
        zoomOutButton->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
        undoButton->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        actionEnglish->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        actionRussian->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        actionGerman->setText(QCoreApplication::translate("MainWindow", "Deutsch", nullptr));
        actionFrench->setText(QCoreApplication::translate("MainWindow", "Fran\303\247ais", nullptr));
        actionChinese->setText(QCoreApplication::translate("MainWindow", "\344\270\255\346\226\207", nullptr));
        actionJapanese->setText(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\254\350\252\236", nullptr));
        actionSpanish->setText(QCoreApplication::translate("MainWindow", "Espa\303\261ol", nullptr));
        actionLightTheme->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        actionDarkTheme->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        actionToggleNativeWidgets->setText(QCoreApplication::translate("MainWindow", "OS Adaptation", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
        menuTheme->setTitle(QCoreApplication::translate("MainWindow", "Theme", nullptr));
        menuAdaptation->setTitle(QCoreApplication::translate("MainWindow", "OS Adaptation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
