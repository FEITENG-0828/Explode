#include <iostream>

#include "Player.h"
#include "Game.h"

int main()
{
    FEITENG::Player player1("Player1");
    FEITENG::Player player2("Player2");

    FEITENG::Game game(3, 3);
    game.addPlayer(&player1);
    game.addPlayer(&player2);
    game.run();
    return 0;
}

