#ifndef FEITENG_PLAYERSTATE_H
#define FEITENG_PLAYERSTATE_H

#include <string>

namespace FEITENG
{
    class Player;

    class PlayerState
    {
    public:
        enum class State
        {
            NOT_STARTED,
            ALIVE,
            DEAD
        };

    private:
        Player* player;
        State state;

    public:
        explicit PlayerState(Player*);
        ~PlayerState();

        Player* getPlayer() const;
        State getState() const;
        void setState(State);
        bool isAlive() const;
    };
} // namespace FEITENG

#endif // FEITENG_PLAYERSTATE_H
