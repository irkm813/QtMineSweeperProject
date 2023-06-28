#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

class Mine_Sweeper {
public:

    int rowCount{ 16 }, colCount{ 30 }, oCounter{ 0 }, iCounter{ 0 }, mineCounter = { 99 }, firstTry{ 13 };
    int totalFields{ rowCount * colCount };
    int firstTryRow{ firstTry / colCount };
    int firstTryCol{ firstTry - firstTryRow * colCount };

    int** mainBoard = new int* [rowCount];


    Mine_Sweeper() {

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

    void show_table() {

        char rowHead = 'A';
        int colHead = 1;


        cout << "    ";

        for (oCounter = 0; oCounter < colCount; oCounter++) {
            if (oCounter < 10) {
                cout << " " << oCounter << " ";
            }
            else {
                cout << oCounter << " ";
            }
        }

        cout << endl;

        for (oCounter = 0; oCounter < rowCount; oCounter++) {
            cout << rowHead << "  | ";
            rowHead++;
            for (iCounter = 0; iCounter < colCount; iCounter++) {
                cout << mainBoard[oCounter][iCounter] << "| ";
            }
            cout << endl;
            sleep_for(nanoseconds(10));
            sleep_until(system_clock::now() + nanoseconds(10000));
        }

        cout << endl;
    }
};


