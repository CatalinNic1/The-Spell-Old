#pragma once

#include "../Entity/Entity.hpp"

struct Player_entity: Entity
{
    Player_entity(sf::FloatRect Player_FloatRect, std::string File_name, int Damage, int Life, float Speed)
    : Entity(Player_FloatRect, File_name, Damage, Life, Speed){}
    void Move_player();
};
