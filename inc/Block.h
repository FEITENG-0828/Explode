#ifndef FEITENG_BLOCK_H
#define FEITENG_BLOCK_H

#include <string>
#include <vector>

namespace FEITENG
{
    class PlayerState;
    class BlockView;

    class Block
    {
    private:
        PlayerState *owner, *cached_new_owner;
        short filled_slots, max_slots;
        std::vector<Block*> neighbours;
        short scheduled_charges;

    public:
        explicit Block(short);
        ~Block();

        Block& addNeighbour(Block*);
        bool areSlotsFull() const;
        void addScheduledCharge(PlayerState*);
        bool chargeByOperation(PlayerState*);
        void chargeByExplosion(PlayerState*);
        bool explode();
        void carryOutSchedule();

        BlockView getBlockView() const;
    };
} // namespace FEITENG

#endif // FEITENG_BLOCK_H
