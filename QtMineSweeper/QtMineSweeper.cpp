#include "QtMineSweeper.h"
#include "QTimer"
#include <string>

int difficulty = 0, highScore = 0;
MineSweeperCore mtable(difficulty);  //creating the table with full of zeroes
QPushButton* gameButton[480];

int rowList[3]{ 10,16,16 };
int colList[3]{ 10,16,30 };
int mineList[3]{ 15,40,99 };

void QtMineSweeper::revealEmpties() {

}
//This function show a window to the player if they manages to find all the mines
void QtMineSweeper::showWinScreen() {

    QWidget* winWindow = new QWidget;
    QVBoxLayout* winLayout = new QVBoxLayout(winWindow);

    QLabel* winLabel = new QLabel(winWindow);
    winLabel->setText("Congrats, claim your trophy:");

    QIcon icon3;
    icon3.addFile(QString::fromUtf8("icons/winner.png"), QSize(), QIcon::Normal, QIcon::Off);

    QPushButton* exitWin = new QPushButton(winWindow); // creating a button that closes the win window
    exitWin->setIcon(icon3);
    exitWin->setIconSize(QSize(350, 350));
    

    connect(exitWin, &QPushButton::clicked, this, [this, winWindow]() {
        resetGame(difficulty);
        winWindow->close();
        });

    winLayout->addWidget(winLabel, 0);
    winLayout->addWidget(exitWin, 1);

    winWindow->setWindowModality(Qt::ApplicationModal);


    winWindow->show();
}
//This function shows a window that displays the developer's name and email address
void QtMineSweeper::showInfo() {
    
    QWidget* infoWindow = new QWidget;
    QVBoxLayout* infoLayout = new QVBoxLayout(infoWindow);
    
    QLabel* infoLabel = new QLabel(infoWindow);
    QLabel* infoLabel2 = new QLabel(infoWindow);
    infoLabel->setText("Developed by: Ferenc Szabo");
    infoLabel2->setText("Email: irkm813@gmail.com");

    QPushButton* exitInfo = new QPushButton(infoWindow); // creating a button that closes the info window
    exitInfo->setText("Okay, whatever");

    connect(exitInfo, &QPushButton::clicked, this, [this, infoWindow]() {   //
        infoWindow->close();
        });

    infoLayout->addWidget(infoLabel, 0);
    infoLayout->addWidget(infoLabel2, 1);
    infoLayout->addWidget(exitInfo, 2);

    infoWindow->setWindowModality(Qt::ApplicationModal);



    infoWindow->show();
} 
//This function is for creating the main table where the game takes place
void QtMineSweeper::tableGenerator(int diff = 0) {

    diff = difficulty;

    mtable.reset(difficulty);
    mtable.mine_generator(mineList[difficulty]); //filling the table with mines

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
        gameButton[i]->setStyleSheet("background-color: #D3D3D3");
        connect(gameButton[i], &QPushButton::clicked, this, [this,cellNumber,i]() {
            
            if (cellNumber > 0) {
                numberReveal(cellNumber, i);
            }
            else {
                numberReveal(cellNumber, i);    
            }
            });
        colCounter++;
}
    QtMineSweeper::setFixedHeight(800);
    QtMineSweeper::setFixedWidth(1000);
}
//When a user clicks on a button, this function reveals the number behind it
void QtMineSweeper::numberReveal(int displayNum, int buttonId) {

    bool cont{ true };

    QString possibleTexts[10]{
        " ","1","2","3","4","5","6","7","8","M"
    };

    QString possibleColors[10]{
        "color: red; background-color: #FFFFFF; font-weight: bold",
        "color: green; background-color: #FFFFFF; font-weight: bold",
        "color: blue; background-color: #FFFFFF; font-weight: bold",
        "color: cyan; background-color: #FFFFFF; font-weight: bold",
        "color: darkblue; background-color: #FFFFFF; font-weight: bold",
        "color: brown; background-color: #FFFFFF; font-weight: bold",
        "color: darkgreen; background-color: #FFFFFF; font-weight: bold",
        "color: black; background-color: #FFFFFF; font-weight: bold",
        "color: red; background-color: #FFFFFF; font-weight: bold",
        "color: black; background-color: red; font-weight: bold",
    };
    
    gameButton[buttonId]->setText(possibleTexts[displayNum]);
    gameButton[buttonId]->setStyleSheet(possibleColors[displayNum]);

    //this is what happens if the player clicks on a mine
    if (displayNum == 9) {

        //changing the reset button's icon to a sad cat face
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icons/sadface.png"), QSize(), QIcon::Normal, QIcon::Off);
        ui.ResetButton->setIcon(icon2);
        ui.ResetButton->setIconSize(QSize(64, 63));
        ui.ResetButton->setAutoRepeat(false);

        //disables all the buttons, thus the player cannot proceed unless they resets the game
        int colCounter{ 0 }, rowCounter{ 0 };
        int totalFields = rowList[difficulty] * colList[difficulty];

        for (int i = 0; i < totalFields; i++) {

            if (colCounter == colList[difficulty]) {
                rowCounter++;
                colCounter = 0;
            }
            
            if (mtable.mainBoard[rowCounter][colCounter] == 9) {
                gameButton[i]->setText("M");
                gameButton[i]->setStyleSheet("color: red; background-color: #D3D3D3");
            }

            gameButton[i]->setDisabled(true);

            colCounter++;
        }

        //Resets the score
        highScore = 0;
    }
    else {
        highScore++;
        QString str = QString::fromUtf8("Score: " + std::to_string(highScore));
        ui.scoreLabel->setText(str);
    }

    if (highScore == (rowList[difficulty] * colList[difficulty] - mineList[difficulty])) {
        showWinScreen();
    }
}
//Resets the game field
void QtMineSweeper::resetGame(int diff) {


    int colCounterr{ 0 }, rowCounterr{ 0 };
    int totalFields = rowList[difficulty] * colList[difficulty];

    ui.scoreLabel->setText("Score: 0");
    ui.mineTimer->startTimer(1000);

    for (int i = 0; i < totalFields; i++) {

        if (colCounterr == colList[difficulty]) {
            rowCounterr++;
            colCounterr = 0;
        }

        ui.InnerGrid->removeWidget(gameButton[i]);
        delete[] gameButton[i];

        colCounterr++;
    }

    if (diff != 4) {
        difficulty = diff;
    }

    tableGenerator(difficulty);

    QIcon icon2;
    icon2.addFile(QString::fromUtf8("icons/happy.png"), QSize(), QIcon::Normal, QIcon::Off);
    ui.ResetButton->setIcon(icon2);
    ui.ResetButton->setIconSize(QSize(64, 63));
    ui.ResetButton->setAutoRepeat(false);
}


QtMineSweeper::QtMineSweeper(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QIcon icon2;
    icon2.addFile(QString::fromUtf8("icons/happy.png"), QSize(), QIcon::Normal, QIcon::Off);
    ui.ResetButton->setIcon(icon2);
    ui.ResetButton->setIconSize(QSize(64, 63));
    ui.ResetButton->setAutoRepeat(false);

    QTimer* timer = new QTimer;
    timer->setInterval(1000);
    timer->start();

    connect(ui.actionInfo, &QAction::triggered, this, &QtMineSweeper::showInfo);

    connect(ui.ResetButton, &QPushButton::clicked, this, [this]() {
        resetGame(4);
        });

    connect(ui.actionEasy, &QAction::triggered, this, [this]() {
        resetGame(0);
        });

    connect(ui.actionNormal, &QAction::triggered, this, [this]() {
        resetGame(1);
        });

    connect(ui.actionHard, &QAction::triggered, this, [this]() {
        resetGame(2);
        });

    tableGenerator(difficulty);
}

QtMineSweeper::~QtMineSweeper()
{}


