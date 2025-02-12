#include "Game.h"

#include <algorithm>

#include "BlockView.h"
#include "ConsoleRender.h"
#include "PlayerState.h"

namespace FEITENG
{
    Game::Game(short rows, short columns): players(), board(rows, columns)
    { }

    Game::~Game()
    { }

    void Game::addPlayer(Player* player)
    {
        players.push_back(PlayerState(player));
    }

    void Game::run(const ConsoleRender& console_render)
    {
        console_render.renderGameStartInfo();
        console_render.renderBoard(board.getBoardView());
        for(int round = 1, alive_players_cnt = players.size(); alive_players_cnt > 1; ++round)
        {
            console_render.renderGameRoundInfo(round);
            for(auto& player: players)
            {
                if(!player.isDead())
                {
                    std::pair<short, short> input;
                    do
                    {
                        input = console_render.getPlayerInput(player);
                    } while(!board.chargeBlock(&player, input.first, input.second));
                    console_render.renderBoard(board.getBoardView());
                    while(board.explode())
                    {
                        console_render.renderBoard(board.getBoardView());
                        // FIXME: 爆炸后需要检查是否有人死亡
                    }
                }
                player.setDead(true);
            }
            for(auto& board_row: board.getBoardView())
            {
                for(auto& block_view: board_row)
                {
                    if(block_view.getPlayer())
                    {
                        block_view.getPlayer()->setDead(false);
                    }
                }
            }
            alive_players_cnt = std::count_if(players.begin(), players.end(),
                [](const PlayerState& player) { return !player.isDead(); });
        }
        console_render.renderGameEndInfo(*std::find_if(players.begin(), players.end(),
            [](const PlayerState& player) { return !player.isDead(); }));
    }
} // namespace FEITENG
