#include "QtMineSweeper.h"
#include <string>
#include <iostream>

QPushButton* gameButton[480];

void QtMineSweeper::tableGenerator(int diff = 0) {


    int rowList[3]{ 10,16,16 };
    int colList[3]{ 10,16,30 };
    int mineList[3]{ 10,40,99 };

    MineSweeperCore mtable(diff);  //creating the table with full of zeroes
    mtable.mine_generator(mineList[diff]); //filling the table with mines


    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred); //setting up a size policy that we can apply for the buttons

    sizePolicy1.setHorizontalStretch(0);  //defininig size policy for the buttons
    sizePolicy1.setVerticalStretch(0);

    int rowCounter{ 0 }, colCounter{ 0 };
    int totalFields = rowList[diff] * colList[diff];

    for (int i = 0; i < totalFields ; i++) {

        if (colCounter == colList[diff]) {
            rowCounter++;
            colCounter = 0;
        }

        int cellNumber = mtable.mainBoard[rowCounter][colCounter];

        gameButton[i] = new QPushButton(ui.centralWidget);
        gameButton[i]->setObjectName("gameButton"+std::to_string(i));
        sizePolicy1.setHeightForWidth(gameButton[i]->sizePolicy().hasHeightForWidth());
        gameButton[i]->setSizePolicy(sizePolicy1);
        ui.InnerGrid->addWidget(gameButton[i], rowCounter, colCounter, 1, 1);
        gameButton[i]->setText(" ");
        gameButton[i]->setStyleSheet("color: red; background-color: #A9A9A9; font-weight: bold");
        connect(gameButton[i], &QPushButton::clicked, this, [this,cellNumber,i]() {
            numberReveal(cellNumber,i);
            });
        colCounter++;
}
}

void QtMineSweeper::resetGame() {
    
}

void QtMineSweeper::numberReveal(int displayNum, int buttonId) {

    QString possibleTexts[10]{
        " ","1","2","3","4","5","6","7","8","A"
    };

    QString possibleColors[10]{
        "color: red; background-color: #D3D3D3; font-weight: bold",
        "color: green; background-color: #D3D3D3; font-weight: bold",
        "color: blue; background-color: #D3D3D3; font-weight: bold",
        "color: cyan; background-color: #D3D3D3; font-weight: bold",
        "color: darkblue; background-color: #D3D3D3; font-weight: bold",
        "color: brown; background-color: #D3D3D3; font-weight: bold",
        "color: darkgreen; background-color: #D3D3D3; font-weight: bold",
        "color: black; background-color: #D3D3D3; font-weight: bold",
        "color: red; background-color: #D3D3D3; font-weight: bold",
        "color: black; background-color: red; font-weight: bold",
    };

    gameButton[buttonId]->setText(possibleTexts[displayNum]);
    gameButton[buttonId]->setStyleSheet(possibleColors[displayNum]);

}

QtMineSweeper::QtMineSweeper(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.ResetButton, &QPushButton::clicked, this, &QtMineSweeper::resetGame);

    tableGenerator();

    ui.centralWidget->setFixedSize(1280, 720);

}

QtMineSweeper::~QtMineSweeper()
{}


