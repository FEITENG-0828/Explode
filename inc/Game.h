#ifndef FEITENG_GAME_H
#define FEITENG_GAME_H

#include <list>

#include "Board.h"

namespace FEITENG
{
    class Player;

    class Game
    {
        private:
            std::list<Player*> players;
            Board board;

        public:
            Game(short, short);
            ~Game();

            void addPlayer(Player*);
            void removePlayer(Player*);
            void run();
    };
} // namespace FEITENG

#endif // FEITENG_GAME_H

