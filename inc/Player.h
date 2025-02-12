#ifndef FEITENG_PLAYER_H
#define FEITENG_PLAYER_H

#include <string>

namespace FEITENG
{
    class Player
    {
    private:
        std::string name;

    public:
        explicit Player(const std::string&);
        ~Player();

        std::string getName() const;
    };
} // namespace FEITENG

#endif // FEITENG_PLAYER_H
