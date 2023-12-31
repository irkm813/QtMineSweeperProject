/********************************************************************************
** Form generated from reading UI file 'QtMineSweeper.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTMINESWEEPER_H
#define UI_QTMINESWEEPER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtMineSweeperClass
{
public:
    QAction *actionEasy;
    QAction *actionNormal;
    QAction *actionHard;
    QAction *actionInfo;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *NavBar;
    QTimeEdit *mineTimer;
    QPushButton *ResetButton;
    QLabel *scoreLabel;
    QGridLayout *InnerGrid;
    QMenuBar *menuBar;
    QMenu *menuDifficulty;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtMineSweeperClass)
    {
        if (QtMineSweeperClass->objectName().isEmpty())
            QtMineSweeperClass->setObjectName("QtMineSweeperClass");
        QtMineSweeperClass->setWindowModality(Qt::ApplicationModal);
        QtMineSweeperClass->resize(900, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtMineSweeperClass->sizePolicy().hasHeightForWidth());
        QtMineSweeperClass->setSizePolicy(sizePolicy);
        QtMineSweeperClass->setTabShape(QTabWidget::Rounded);
        actionEasy = new QAction(QtMineSweeperClass);
        actionEasy->setObjectName("actionEasy");
        actionNormal = new QAction(QtMineSweeperClass);
        actionNormal->setObjectName("actionNormal");
        actionHard = new QAction(QtMineSweeperClass);
        actionHard->setObjectName("actionHard");
        actionInfo = new QAction(QtMineSweeperClass);
        actionInfo->setObjectName("actionInfo");
        centralWidget = new QWidget(QtMineSweeperClass);
        centralWidget->setObjectName("centralWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(5, 5, 5, 5);
        NavBar = new QHBoxLayout();
        NavBar->setSpacing(0);
        NavBar->setObjectName("NavBar");
        NavBar->setSizeConstraint(QLayout::SetMinimumSize);
        NavBar->setContentsMargins(-1, -1, -1, 0);
        mineTimer = new QTimeEdit(centralWidget);
        mineTimer->setObjectName("mineTimer");
        sizePolicy.setHeightForWidth(mineTimer->sizePolicy().hasHeightForWidth());
        mineTimer->setSizePolicy(sizePolicy);
        mineTimer->setFocusPolicy(Qt::NoFocus);
        mineTimer->setContextMenuPolicy(Qt::DefaultContextMenu);
        mineTimer->setAcceptDrops(false);
        mineTimer->setFrame(true);
        mineTimer->setAlignment(Qt::AlignCenter);
        mineTimer->setReadOnly(true);
        mineTimer->setButtonSymbols(QAbstractSpinBox::NoButtons);
        mineTimer->setAccelerated(false);
        mineTimer->setKeyboardTracking(false);
        mineTimer->setProperty("showGroupSeparator", QVariant(false));

        NavBar->addWidget(mineTimer);

        ResetButton = new QPushButton(centralWidget);
        ResetButton->setObjectName("ResetButton");
        sizePolicy.setHeightForWidth(ResetButton->sizePolicy().hasHeightForWidth());
        ResetButton->setSizePolicy(sizePolicy);
        ResetButton->setAutoFillBackground(false);
        ResetButton->setStyleSheet(QString::fromUtf8("background-color: lightgray"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/happy.png"), QSize(), QIcon::Normal, QIcon::Off);
        ResetButton->setIcon(icon);
        ResetButton->setIconSize(QSize(64, 63));
        ResetButton->setAutoRepeat(false);

        NavBar->addWidget(ResetButton);

        scoreLabel = new QLabel(centralWidget);
        scoreLabel->setObjectName("scoreLabel");
        sizePolicy.setHeightForWidth(scoreLabel->sizePolicy().hasHeightForWidth());
        scoreLabel->setSizePolicy(sizePolicy);
        scoreLabel->setAlignment(Qt::AlignCenter);

        NavBar->addWidget(scoreLabel);


        gridLayout->addLayout(NavBar, 0, 0, 1, 1);

        InnerGrid = new QGridLayout();
        InnerGrid->setSpacing(0);
        InnerGrid->setObjectName("InnerGrid");

        gridLayout->addLayout(InnerGrid, 1, 0, 1, 1);

        QtMineSweeperClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtMineSweeperClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 900, 22));
        menuDifficulty = new QMenu(menuBar);
        menuDifficulty->setObjectName("menuDifficulty");
        QtMineSweeperClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtMineSweeperClass);
        mainToolBar->setObjectName("mainToolBar");
        QtMineSweeperClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtMineSweeperClass);
        statusBar->setObjectName("statusBar");
        QtMineSweeperClass->setStatusBar(statusBar);

        menuBar->addAction(menuDifficulty->menuAction());
        menuDifficulty->addAction(actionEasy);
        menuDifficulty->addAction(actionNormal);
        menuDifficulty->addAction(actionHard);
        menuDifficulty->addSeparator();
        menuDifficulty->addAction(actionInfo);
        menuDifficulty->addSeparator();

        retranslateUi(QtMineSweeperClass);

        QMetaObject::connectSlotsByName(QtMineSweeperClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtMineSweeperClass)
    {
        QtMineSweeperClass->setWindowTitle(QCoreApplication::translate("QtMineSweeperClass", "QtMineSweeper", nullptr));
        actionEasy->setText(QCoreApplication::translate("QtMineSweeperClass", "Easy", nullptr));
        actionNormal->setText(QCoreApplication::translate("QtMineSweeperClass", "Normal", nullptr));
        actionHard->setText(QCoreApplication::translate("QtMineSweeperClass", "Hard", nullptr));
        actionInfo->setText(QCoreApplication::translate("QtMineSweeperClass", "Info", nullptr));
        ResetButton->setText(QString());
        scoreLabel->setText(QCoreApplication::translate("QtMineSweeperClass", "Score: 0", nullptr));
        menuDifficulty->setTitle(QCoreApplication::translate("QtMineSweeperClass", "Difficulty", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtMineSweeperClass: public Ui_QtMineSweeperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTMINESWEEPER_H
