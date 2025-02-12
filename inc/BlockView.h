#ifndef FEITENG_BLOCKVIEW_H
#define FEITENG_BLOCKVIEW_H

namespace FEITENG
{
    class PlayerState;

    class BlockView
    {
    private:
        PlayerState* owner;
        short filled_slots, max_slots;

    public:
        BlockView();
        BlockView(PlayerState*, short, short);
        ~BlockView();

        PlayerState* getPlayer() const;
        void setPlayer(PlayerState*);
        short getFilledSlots() const;
        void setFilledSlots(short);
        short getMaxSlots() const;
        void setMaxSlots(short);
    };
} // namespace FEITENG

#endif // FEITENG_BLOCKVIEW_H
