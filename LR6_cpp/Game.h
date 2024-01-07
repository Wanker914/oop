#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

class Game {
public:

    Game() : board(9, ' ') {}

    void start() {
        char currentPlayer = 'X';

        while (!isGameOver()) {
            drawBoard();

            if (currentPlayer == 'X') {
                // Ходит пользователь
                int move;
                do {
                    std::cout << "Ходите (1-9): ";
                    std::cin >> move;
                } while (!isValidMove(move));

                makeMove(move, currentPlayer);
            } else {
                // Ходит компьютер
                int move = getComputerMove();
                makeMove(move, currentPlayer);
                std::cout << "Компьютер сделал ход " << move << std::endl;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        drawBoard();

        char winner = getWinner();
        if (winner == 'X' || winner == 'O') {
            std::cout << "Игрок " << winner << " победил!" << std::endl;
        } else {
            std::cout << "Ничья!" << std::endl;
        }
    }

    void makeMove(int move, char currentPlayer) {
        board[move - 1] = currentPlayer;
    }

    char getWinner() const {
        // Проверка горизонтальных и вертикальных линий
        for (int i = 0; i < 3; ++i) {
            if (board[i] == board[i + 3] && board[i] == board[i + 6] && board[i] != ' ') {
                return board[i];
            }
            if (board[i * 3] == board[i * 3 + 1] && board[i * 3] == board[i * 3 + 2] && board[i * 3] != ' ') {
                return board[i * 3];
            }
        }

        // Проверка диагональных линий
        if ((board[0] == board[4] && board[0] == board[8] && board[0] != ' ') ||
            (board[2] == board[4] && board[2] == board[6] && board[2] != ' ')) {
            return board[4];
        }

        return ' ';
    }

private:

    void drawBoard() const {
        std::cout << " 1 | 2 | 3 \n";
        std::cout << "---+---+---\n";
        std::cout << " 4 | 5 | 6 \n";
        std::cout << "---+---+---\n";
        std::cout << " 7 | 8 | 9 \n";

        std::cout << std::endl;
        std::cout << " ";
        for (int i = 0; i < 9; ++i) {
            std::cout << board[i];
            if (i % 3 == 2) {
                std::cout << std::endl;
                if (i < 8) {
                    std::cout << "-----------\n";
                    std::cout << " ";
                }
            } else {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
    }

    bool isValidMove(int move) const {
        return (move >= 1 && move <= 9 && board[move - 1] == ' ');
    }

    bool isGameOver() const {
        return (getWinner() != ' ' || std::count(board.begin(), board.end(), ' ') == 0);
    }

    int getComputerMove() const {
        // Просто выбираем первую свободную ячейку
        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                return i + 1;
            }
        }

        return -1; // Недостижимый код, чтобы избежать предупреждения компилятора
    }

    std::vector<char> board;

};
