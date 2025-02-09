#include "Block.h"

#include <iostream>

namespace FEITENG
{
    Block::Block(short max_slots):
        owner(nullptr), cached_new_owner(nullptr),
        filled_slots(0), max_slots(max_slots),
        neighbours(),
        scheduled_charges(0)
    {
        for(short i = 0; i < max_slots; ++i)
        {
            neighbours.push_back(nullptr);
        }
    }

    Block::~Block()
    { }

    Block& Block::addNeighbour(Block* neighbour)
    {
        neighbours.push_back(neighbour);
        return *this;
    }

    bool Block::areSlotsFull() const
    {
        return filled_slots >= max_slots;
    }

    void Block::addScheduledCharge(Player* new_owner)
    {
        cached_new_owner = new_owner;
        ++scheduled_charges;
    }

    bool Block::chargeByOperation(Player* player)
    {
        bool success = false;
        if(owner == nullptr || owner == player)
        {
            owner = player;
            if(filled_slots < max_slots)
            {
                ++filled_slots;
                success = true;
            }
        }
        return success;
    }

    void Block::chargeByExplosion(Player* new_owner)
    {
        owner = new_owner;
        ++filled_slots;
    }

    bool Block::explode()
    {
        bool success = false;
        if(areSlotsFull())
        {
            filled_slots = 0;
            for(auto& neighbour : neighbours)
            {
                if(neighbour)
                {
                    neighbour -> addScheduledCharge(owner);
                }
            }
            owner = nullptr;
            success = true;
        }
        return success;
    }

    void Block::carryOutSchedule()
    {
        for(int i = 1; i <= scheduled_charges; ++i)
        {
            chargeByExplosion(cached_new_owner);
        }
        cached_new_owner = nullptr;
        scheduled_charges = 0;
    }

    std::string Block::printSlots() const
    {
        return std::to_string(filled_slots) + "/" + std::to_string(max_slots);
    }
} // namespace FEITENG
