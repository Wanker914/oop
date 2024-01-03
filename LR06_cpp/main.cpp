#include <iostream>
#include <vector>
#include <windows.h>

// Функция для печати игрового поля
void printBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

// Функция для проверки победы
bool checkWin(const std::vector<std::vector<char>>& board, char symbol) {
    // Проверяем все возможные комбинации для победы
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true; // Проверка горизонтальных линий
        }
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true; // Проверка вертикальных линий
        }
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true; // Проверка диагонали (слева направо)
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true; // Проверка диагонали (справа налево)
    }
    return false; // Если нет совпадений
}

// Функция для выполнения хода игрока
void makeMove(std::vector<std::vector<char>>& board, int row, int col, char symbol) {
    board[row][col] = symbol;
}

// Функция для выполнения хода компьютера
void computerMove(std::vector<std::vector<char>>& board, char symbol) {
    // Простейший AI: компьютер выбирает случайную свободную клетку
    std::vector<std::pair<int, int>> emptyCells;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                emptyCells.emplace_back(i, j);
            }
        }
    }
    if (!emptyCells.empty()) {
        int randomIndex = rand() % emptyCells.size();
        int row = emptyCells[randomIndex].first;
        int col = emptyCells[randomIndex].second;
        board[row][col] = symbol;
    }
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

    SetConsoleOutputCP(CP_UTF8);

    std::cout << "Добро пожаловать в игру Крестики-нолики!\n";
    std::cout << "Игровое поле представлено в виде 3x3 матрицы.\n";
    std::cout << "Введите номер строки и столбца для совершения хода (нумерация начинается с 0)\n";

    printBoard(board);

    char currentPlayer = 'X';
    bool gameOver = false;

    while (!gameOver) {
        int row, col;
        if (currentPlayer == 'X') {
            std::cout << "Ход игрока 'X':\n";
            std::cin >> row >> col;
            makeMove(board, row, col, currentPlayer);
        } else {
            std::cout << "Ход компьютера:\n";
            computerMove(board, currentPlayer);
        }

        printBoard(board);

        if (checkWin(board, currentPlayer)) {
            std::cout << "Игрок '" << currentPlayer << "' победил!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}