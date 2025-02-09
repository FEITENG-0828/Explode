#ifndef FEITENG_BOARD_H
#define FEITENG_BOARD_H

#include <vector>

namespace FEITENG
{
    class Player;
    class Block;

    class Board
    {
        private:
            short rows, columns;
            std::vector<std::vector<Block>> board;

        public:
            Board(short, short);
            ~Board();

            bool chargeBlock(Player*, short, short);
            void explode();

            void print() const;
    };
} // namespace FEITENG

#endif // FEITENG_BOARD_H

