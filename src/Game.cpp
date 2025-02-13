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

    void Game::updatePlayerState()
    {
        for(auto& player: players)
        {
            bool is_alive = false;
            for(auto& block_row: board.getBoardView())
            {
                for(auto& block_view: block_row)
                {
                    if(block_view.getPlayer() == &player)
                    {
                        is_alive = true;
                        break;
                    }
                }
                if(is_alive)
                {
                    break;
                }
            }
            if(is_alive)
            {
                player.setState(PlayerState::State::ALIVE);
            }
            else if(player.getState() == PlayerState::State::ALIVE)
            {
                player.setState(PlayerState::State::DEAD);
            }
        }
    }

    bool Game::checkWinner() const
    {
        bool has_winner = false;
        if(std::count_if(players.begin(), players.end(),
            [](const PlayerState& player) { return player.isAlive(); }) == 1)
        {
            has_winner = true;
        }
        return has_winner;
    }

    void Game::run(const ConsoleRender& console_render)
    {
        PlayerState* winner = nullptr;
        console_render.renderGameStartInfo();
        console_render.renderBoard(board.getBoardView());
        for(int round = 1;; ++round)
        {
            console_render.renderGameRoundInfo(round);
            for(auto& player: players)
            {
                if(player.isAlive())
                {
                    std::pair<short, short> input;
                    do
                    {
                        input = console_render.getPlayerInput(player);
                    } while(!board.chargeBlock(&player, input.first, input.second));
                    updatePlayerState();
                    console_render.renderBoard(board.getBoardView());
                    while(board.explode())
                    {
                        updatePlayerState();
                        console_render.renderBoard(board.getBoardView());
                        if(checkWinner())
                        {
                            winner = &player;
                            break;
                        }
                    }
                }
                if(winner)
                {
                    break;
                }
            }
            if(winner)
            {
                break;
            }
        }
        console_render.renderGameEndInfo(*winner);
    }
} // namespace FEITENG
