#ifndef FEITENG_BLOCK_H
#define FEITENG_BLOCK_H

#include <vector>
#include <string>

namespace FEITENG
{
    class Player;

    class Block
    {
        private:
            Player* owner, *cached_new_owner;
            short filled_slots, max_slots;
            std::vector<Block*> neighbours;
            short scheduled_charges;

        public:
            explicit Block(short);
            ~Block();

            Block& addNeighbour(Block*);
            bool areSlotsFull() const;
            void addScheduledCharge(Player*);
            bool chargeByOperation(Player*);
            void chargeByExplosion(Player*);
            bool explode();
            void carryOutSchedule();

            std::string printSlots() const;
    };
} // namespace FEITENG

#endif // FEITENG_BLOCK_H
