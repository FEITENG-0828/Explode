#include "Board.h"

#include "Block.h"

#include <iostream>

namespace FEITENG
{
    Board::Board(short rows, short columns):
        rows(rows), columns(columns)
    {
        board.resize(rows, std::vector<Block>(columns, Block(4)));
        for(short i = 1; i <= rows; ++i)
        {
            for(short j = 1; j <= columns; ++j)
            {
                if(i == 1)
                {
                    if(j == 1)
                    {
                        board[i - 1][j - 1] = Block(2)
                            .addNeighbour(&board[i - 1][j])
                            .addNeighbour(&board[i][j - 1]);
                    }
                    else if(j == columns)
                    {
                        board[i - 1][j - 1] = Block(2)
                            .addNeighbour(&board[i - 1][j - 2])
                            .addNeighbour(&board[i][j - 1]);
                    }
                    else
                    {
                        board[i - 1][j - 1] = Block(3)
                            .addNeighbour(&board[i - 1][j - 2])
                            .addNeighbour(&board[i - 1][j])
                            .addNeighbour(&board[i][j - 1]);
                    }
                }
                else if(i == rows)
                {
                    if(j == 1)
                    {
                        board[i - 1][j - 1] = Block(2)
                            .addNeighbour(&board[i - 2][j - 1])
                            .addNeighbour(&board[i - 1][j]);
                    }
                    else if(j == columns)
                    {
                        board[i - 1][j -1] = Block(2)
                            .addNeighbour(&board[i - 2][j - 1])
                            .addNeighbour(&board[i - 1][j - 2]);
                    }
                    else
                    {
                        board[i - 1][j - 1] = Block(3)
                            .addNeighbour(&board[i - 2][j - 1])
                            .addNeighbour(&board[i - 1][j - 2])
                            .addNeighbour(&board[i - 1][j]);
                    }
                }
                else
                {
                    if(j == 1)
                    {
                        board[i - 1][j - 1] = Block(3)
                            .addNeighbour(&board[i - 2][j - 1])
                            .addNeighbour(&board[i - 1][j])
                            .addNeighbour(&board[i][j - 1]);
                    }
                    else if(j == columns)
                    {
                        board[i - 1][j -1] = Block(3)
                            .addNeighbour(&board[i - 2][j - 1])
                            .addNeighbour(&board[i - 1][j - 2])
                            .addNeighbour(&board[i][j - 1]);
                    }
                    else
                    {
                        board[i - 1][j - 1]
                            .addNeighbour(&board[i - 2][j - 1])
                            .addNeighbour(&board[i - 1][j - 2])
                            .addNeighbour(&board[i - 1][j])
                            .addNeighbour(&board[i][j - 1]);
                    }
                }
            }
        }
    }

    Board::~Board()
    { }

    bool Board::chargeBlock(Player* player_ptr, short row, short column)
    {
        bool success = false;
        if(row > 0 && row <= rows && column > 0 && column <= columns)
        {
            success = board[row - 1][column - 1].chargeByOperation(player_ptr);
        }
        return success;
    }

    void Board::explode()
    {
        for(short i = 1; i <= rows; ++i)
        {
            for(short j = 1; j <= columns; ++j)
            {
                board[i - 1][j - 1].explode();
            }
        }
        for(short i = 1; i <= rows; ++i)
        {
            for(short j = 1; j <= columns; ++j)
            {
                board[i - 1][j - 1].carryOutSchedule();
            }
        }
    }

    void Board::print() const
    {
        std::cout << "=================================\n";
        for(short i = 1; i <= rows; ++i)
        {
            std::cout << "| ";
            for(short j = 1; j <= columns; ++j)
            {
                std::cout << board[i - 1][j - 1].printSlots() << " ";
            }
            std::cout << "|\n";
        }
        std::cout << "=================================\n";
    }
} // namespace FEITENG

