#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtMineSweeper.h"

class QtMineSweeper : public QMainWindow
{
    Q_OBJECT

public:
    QtMineSweeper(QWidget *parent = nullptr);
    ~QtMineSweeper();

    void tableGenerator();

    void numberReveal(int,int);

private:
    Ui::QtMineSweeperClass ui;
};

class MineSweeperCore {
public:

    int rowCount{ 16 }, colCount{ 30 }, oCounter{ 0 }, iCounter{ 0 }, mineCounter = { 99 }, firstTry{ 13 };
    int totalFields{ rowCount * colCount };
    int firstTryRow{ firstTry / colCount };
    int firstTryCol{ firstTry - firstTryRow * colCount };

    int** mainBoard = new int* [rowCount];


    MineSweeperCore() {

        for (iCounter = 0; iCounter < rowCount; ++iCounter) {
            mainBoard[iCounter] = new int[colCount] {0};
        }

    }

    int field_number_counter(int row, int col) {

        int ic{ 0 }, oc{ 0 }, searchRow{ 0 }, searchCol{ 0 }, mines{ 0 };

        if (mainBoard[row][col] == 9) {
            return 9;
        }

        else {

            for (oc = 0; oc < 3; oc++) {
                searchRow = (row + (oc - 1));

                if (searchRow < 0 || searchRow >= rowCount) {
                    continue;
                }

                for (ic = 0; ic < 3; ic++) {
                    searchCol = (col + (ic - 1));

                    if (searchCol < 0 || searchCol >= colCount) {
                        continue;
                    }

                    if (searchRow == row && searchCol == col) {
                        continue;
                    }
                    else {
                        if (mainBoard[searchRow][searchCol] == 9) {
                            mines++;
                        }
                    }

                }
            }

        }
        return mines;
    }

    void mine_generator() {

        srand((unsigned)time(NULL));


        for (mineCounter = 99; mineCounter > 0; mineCounter--) {
            int randomRow = rand() % rowCount; int randomCol = rand() % colCount;


            if (randomRow == firstTryRow && randomCol == firstTryCol) {
                mainBoard[randomRow][randomCol] = 0;
                mineCounter++;
            }
            else {
                mainBoard[randomRow][randomCol] = 9;
            }

        }

        for (oCounter = 0; oCounter < rowCount; oCounter++) {

            for (iCounter = 0; iCounter < colCount; iCounter++) {

                mainBoard[oCounter][iCounter] = field_number_counter(oCounter, iCounter);
            }
        }

    }
    ~MineSweeperCore() {
        delete mainBoard;
    }
};
