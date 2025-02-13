#include "PlayerState.h"

namespace FEITENG
{
    PlayerState::PlayerState(Player* player): player(player), state(State::NOT_STARTED)
    { }

    PlayerState::~PlayerState()
    { }

    Player* PlayerState::getPlayer() const
    {
        return player;
    }

    PlayerState::State PlayerState::getState() const
    {
        return state;
    }

    void PlayerState::setState(State state)
    {
        this->state = state;
    }

    bool PlayerState::isAlive() const
    {
        return state == State::NOT_STARTED || state == State::ALIVE;
    }
} // namespace FEITENG
