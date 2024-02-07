#include <iostream>
using namespace std;

// Function to draw the Tic Tac Toe board
void drawBoard(char a11, char a12, char a13, char a21, char a22, char a23, char a31, char a32, char a33) {
    cout << "\nTic Tac Toe\n\n";
    cout << " " << a11 << " | " << a12 << " | " << a13 << endl;
    cout << "---|---|---\n";
    cout << " " << a21 << " | " << a22 << " | " << a23 << endl;
    cout << "---|---|---\n";
    cout << " " << a31 << " | " << a32 << " | " << a33 << endl;
}

// Function to check if a player has won
bool checkWin(char a11, char a12, char a13, char a21, char a22, char a23, char a31, char a32, char a33) {
    // Check rows, columns, and diagonals for a win
    return ((a11 == a12 && a12 == a13 && a11 != ' ') ||
            (a21 == a22 && a22 == a23 && a21 != ' ') ||
            (a31 == a32 && a32 == a33 && a31 != ' ') ||
            (a11 == a21 && a21 == a31 && a11 != ' ') ||
            (a12 == a22 && a22 == a32 && a12 != ' ') ||
            (a13 == a23 && a23 == a33 && a13 != ' ') ||
            (a11 == a22 && a22 == a33 && a11 != ' ') ||
            (a13 == a22 && a22 == a31 && a13 != ' '));
}

int main() {
    char a11 = ' ', a12 = ' ', a13 = ' ', a21 = ' ', a22 = ' ', a23 = ' ', a31 = ' ', a32 = ' ', a33 = ' ';
    int row, col;
    char currentPlayer = 'X';
    bool gameover = false;

    while (!gameover) {
        drawBoard(a11, a12, a13, a21, a22, a23, a31, a32, a33);

        // Get player input
        cout << "Player " << currentPlayer << ", enter row (1-3) and column (1-3): ";
        cin >> row >> col;

        // Validate input and update the board
        if ((row >= 1 && row <= 3) && (col >= 1 && col <= 3)) {
            char* currentCell = nullptr;
            if (row == 1 && col == 1) currentCell = &a11;
            else if (row == 1 && col == 2) currentCell = &a12;
            else if (row == 1 && col == 3) currentCell = &a13;
            else if (row == 2 && col == 1) currentCell = &a21;
            else if (row == 2 && col == 2) currentCell = &a22;
            else if (row == 2 && col == 3) currentCell = &a23;
            else if (row == 3 && col == 1) currentCell = &a31;
            else if (row == 3 && col == 2) currentCell = &a32;
            else if (row == 3 && col == 3) currentCell = &a33;

            if (currentCell != nullptr && *currentCell == ' ') {
                *currentCell = currentPlayer;
                if (checkWin(a11, a12, a13, a21, a22, a23, a31, a32, a33)) {
                    drawBoard(a11, a12, a13, a21, a22, a23, a31, a32, a33);
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameover = true;
                } else {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
                }
            } else {
                cout << "Cell already occupied. Try again.\n";
            }
        } else {
            cout << "Invalid input. Row and column must be between 1 and 3.\n";
        }
    }

    return 0;
}
