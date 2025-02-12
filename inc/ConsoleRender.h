#ifndef FEITENG_CONSOLERENDER_H
#define FEITENG_CONSOLERENDER_H

#include <vector>
#include <utility>

namespace FEITENG
{
    class BlockView;
    class PlayerState;

    class ConsoleRender
    {
    public:
        ConsoleRender() = default;
        ~ConsoleRender() = default;

        std::pair<short, short> getPlayerInput(const PlayerState&) const;
        void renderGameStartInfo() const;
        void renderGameEndInfo(const PlayerState&) const;
        void renderGameRoundInfo(int) const;
        void renderBoard(const std::vector<std::vector<BlockView>>& board_view) const;
    };
} // namespace FEITENG

#endif // FEITENG_CONSOLERENDER_H
