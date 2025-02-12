#include "BlockView.h"

namespace FEITENG
{
    BlockView::BlockView(): owner(nullptr), filled_slots(0), max_slots(0)
    { }

    BlockView::BlockView(PlayerState* owner, short filled_slots, short max_slots):
        owner(owner),
        filled_slots(filled_slots),
        max_slots(max_slots)
    { }

    BlockView::~BlockView()
    { }

    PlayerState* BlockView::getPlayer() const
    {
        return owner;
    }

    void BlockView::setPlayer(PlayerState* new_owner)
    {
        owner = new_owner;
    }

    short BlockView::getFilledSlots() const
    {
        return filled_slots;
    }

    void BlockView::setFilledSlots(short new_filled_slots)
    {
        filled_slots = new_filled_slots;
    }

    short BlockView::getMaxSlots() const
    {
        return max_slots;
    }

    void BlockView::setMaxSlots(short new_max_slots)
    {
        max_slots = new_max_slots;
    }
} // namespace FEITENG
