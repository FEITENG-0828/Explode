#include "PlayerState.h"

namespace FEITENG
{
    PlayerState::PlayerState(Player* player): player(player), is_dead(false)
    { }

    PlayerState::~PlayerState()
    { }

    Player* PlayerState::getPlayer() const
    {
        return player;
    }

    bool PlayerState::isDead() const
    {
        return is_dead;
    }

    void PlayerState::setDead(bool is_dead)
    {
        this->is_dead = is_dead;
    }
} // namespace FEITENG
