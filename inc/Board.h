#ifndef FEITENG_BOARD_H
#define FEITENG_BOARD_H

#include <vector>

namespace FEITENG
{
    class PlayerState;
    class Block;
    class BlockView;

    class Board
    {
    private:
        short rows, columns;
        std::vector<std::vector<Block>> board;

    public:
        Board(short, short);
        ~Board();

        bool chargeBlock(PlayerState*, short, short);
        bool explode();

        std::vector<std::vector<BlockView>> getBoardView() const;
    };
} // namespace FEITENG

#endif // FEITENG_BOARD_H
