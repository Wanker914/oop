#include <cassert>
#include "Game.h"

void ComputerWin() {
    Game game;
    game.makeMove(1,'O');
    game.makeMove(2,'X');
    game.makeMove(5,'O');
    game.makeMove(4,'X');
    game.makeMove(9,'O');
    char result = game.getWinner();
    assert(result == 'O');
}

void PlayerWin() {
    Game game;
    game.makeMove(1,'X');
    game.makeMove(2,'O');
    game.makeMove(5,'X');
    game.makeMove(4,'O');
    game.makeMove(9,'X');
    char result = game.getWinner();
    assert(result == 'X');
}

void DrawWin(){
    Game game;
    game.makeMove(1,'X');
    game.makeMove(2,'O');
    game.makeMove(3,'X');
    game.makeMove(4,'O');
    game.makeMove(5,'X');
    game.makeMove(6,'O');
    game.makeMove(7,'O');
    game.makeMove(8,'X');
    game.makeMove(9,'O');
    char result = game.getWinner();
    assert(result == ' ');
}

void testsGame(){
    ComputerWin();
    PlayerWin();
    DrawWin();
}