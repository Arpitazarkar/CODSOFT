#include <iostream>
using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

void printBoard(char board[3][3]) {
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl << endl;
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void playerMove(char board[3][3], char player) {
    int x, y;
    do {
        cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
        cin >> x >> y;
    } while (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != EMPTY);
    board[x][y] = player;
}

int main() {
    char board[3][3] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY}
    };
    char currentPlayer = PLAYER_X;
    bool gameEnded = false;

    while (!gameEnded) {
        printBoard(board);
        playerMove(board, currentPlayer);
        gameEnded = checkWin(board, currentPlayer);

        if (gameEnded) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            gameEnded = true;
        }

        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    return 0;
}