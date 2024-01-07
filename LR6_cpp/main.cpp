#include <windows.h>
#include "TestGame.h"
#include "Game.h"

int main() {

    testsGame();

    SetConsoleOutputCP(CP_UTF8);

    Game game;
    game.start();

    return 0;
}