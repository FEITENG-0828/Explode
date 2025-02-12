#include "ConsoleRender.h"

#include <iostream>

#include "BlockView.h"
#include "PlayerState.h"
#include "Player.h"

namespace FEITENG
{
    std::pair<short, short> ConsoleRender::getPlayerInput(const PlayerState& player_state) const
    {
        short row, column;
        std::cout << "Player " << player_state.getPlayer()->getName() << " turn: ";
        std::cin >> row >> column;
        std::cout << std::endl;
        return std::pair<short, short>(row, column);
    }

    void ConsoleRender::renderGameStartInfo() const
    {
        std::cout << "**********Game Start**********\n" << std::endl;
    }

    void ConsoleRender::renderGameEndInfo(const PlayerState& winner) const
    {
        std::cout << "**********Game End**********" << std::endl;
        std::cout << "Winner is " << winner.getPlayer()->getName() << "!" << std::endl;
    }

    void ConsoleRender::renderGameRoundInfo(int round) const
    {
        std::cout << "**********Round " << round << "**********\n" << std::endl;
    }

    void ConsoleRender::renderBoard(const std::vector<std::vector<BlockView>>& board_view) const
    {
        short rows = board_view.size();
        short columns = board_view[0].size();
        std::cout << std::string(4 * columns + 3, '=') << std::endl;
        for(short i = 1; i <= rows; ++i)
        {
            std::cout << "| ";
            for(short j = 1; j <= columns; ++j)
            {
                std::cout << board_view[i - 1][j - 1].getFilledSlots()
                          << "/"
                          << board_view[i - 1][j - 1].getMaxSlots()
                          << " ";
            }
            std::cout << "|" << std::endl;
        }
        std::cout << std::string(4 * columns + 3, '=') << '\n' << std::endl;
    }
} // namespace FEITENG
