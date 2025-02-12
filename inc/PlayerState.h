#ifndef FEITENG_PLAYERSTATE_H
#define FEITENG_PLAYERSTATE_H

#include <string>

namespace FEITENG
{
    class Player;

    class PlayerState
    {
    private:
        Player* player;
        bool is_dead;

    public:
        explicit PlayerState(Player*);
        ~PlayerState();

        Player* getPlayer() const;
        bool isDead() const;
        void setDead(bool);
    };
} // namespace FEITENG

#endif // FEITENG_PLAYERSTATE_H
