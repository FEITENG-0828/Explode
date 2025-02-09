#include "Player.h"

namespace FEITENG
{
    Player::Player(const std::string& name): name(name)
    { }

    Player::~Player()
    { }

    std::string Player::getName() const
    {
        return this->name;
    }
} // namespace FEITENG
