// Task 3 (TIC-TAC-TOE GAME)
// Build a simple console-based Tic-Tac-Toe game that allows two players to play against each other.
// Game Board: Create a 3x3 grid as the game board.
// Players: Assign "X" and "O" to two players.
// Display Board: Show the current state of the board.
// Player Input: Prompt the current player to enter their move.
// Update Board: Update the game board with the player's move.
// Check for Win: Check if the current player has won.
// Check for Draw: Determine if the game is a draw.
// Switch Players: Alternate turns between "X" and "O" players.
// Display Result: Show the result of the game (win, draw, or ongoing).
// Play Again: Ask if the players want to play another game

#include <iostream>
using namespace std;

// Function to initialize the game board
void InitializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void DisplayBoard(char board[3][3]) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -+-+-" << endl;
    }
}

// Function to check if the current player has won
bool CheckWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check if the game is a draw
bool CheckDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameover = false;

    InitializeBoard(board);

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameover) {
        DisplayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        int row, col;
        cin >> row >> col;

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the board
        board[row - 1][col - 1] = currentPlayer;

        // Check for a win
        if (CheckWin(board, currentPlayer)) {
            DisplayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            gameover = true;
        }
        // Check for a draw
        else if (CheckDraw(board)) {
            DisplayBoard(board);
            cout << "It's a draw!" << endl;
            gameover = true;
        }
        // Switch players
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    cout << "Do you want to play again? (yes/no): ";
    string playAgain;
    cin >> playAgain;

    if (playAgain == "yes" || playAgain == "y") {
        InitializeBoard(board);
        gameover = false;
        currentPlayer = 'X';
    } else {
        cout << "Thank you for playing Tic-Tac-Toe!" << endl;
    }

    return 0;
}
