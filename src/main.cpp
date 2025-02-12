#include <iostream>

#include "Game.h"
#include "Player.h"
#include "ConsoleRender.h"

int main()
{
    FEITENG::Player player1("Player1");
    FEITENG::Player player2("Player2");

    FEITENG::Game game(3, 3);
    game.addPlayer(&player1);
    game.addPlayer(&player2);

    FEITENG::ConsoleRender console_render;
    game.run(console_render);
    return 0;
}
