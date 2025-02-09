#include "Game.h"

namespace FEITENG
{
    Game::Game(short rows, short columns):
        players(),
        board(rows, columns)
    { }

    Game::~Game()
    { }

    void Game::addPlayer(Player* player)
    {
        players.push_back(player);
    }

    void Game::removePlayer(Player* player)
    {
        players.remove(player);
    }

    void Game::run()
    {
        board.print();
        board.chargeBlock(players.front(), 1, 1);
        board.explode();

        board.print();
        board.chargeBlock(players.back(), 1, 2);
        board.explode();

        board.print();
        board.chargeBlock(players.front(), 2, 1);
        board.explode();

        board.print();
        board.chargeBlock(players.back(), 3, 3);
        board.explode();

        board.print();
        board.chargeBlock(players.front(), 2, 1);
        board.explode();

        board.print();
        board.chargeBlock(players.back(), 3, 3);
        board.explode();

        board.print();
        board.chargeBlock(players.front(), 1, 1);
        board.explode();

        board.print();
        board.explode();
        board.print();
    }
} // namespace FEITENG
