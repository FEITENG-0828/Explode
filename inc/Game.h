#ifndef FEITENG_GAME_H
#define FEITENG_GAME_H

#include <vector>

#include "Board.h"

namespace FEITENG
{
    class PlayerState;
    class Player;
    class ConsoleRender;

    class Game
    {
    private:
        std::vector<PlayerState> players;
        Board board;

    public:
        Game(short, short);
        ~Game();

        void addPlayer(Player*);
        void updatePlayerState();
        bool checkWinner() const;
        void run(const ConsoleRender&);
    };
} // namespace FEITENG

#endif // FEITENG_GAME_H
