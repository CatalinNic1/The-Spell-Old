#pragma once

#include "../Entity/Entity.hpp"

struct Enemy_entity: Entity
{
    Enemy_entity(sf::FloatRect Enemy_FloatRect, std::string File_name, int Damage, int Life, float Speed)
    : Entity(Enemy_FloatRect, File_name, Damage, Life, Speed){}
    void Move_enemy();
private:
    int Move_counter = 0;
    const int Change_direction_limit = 5000;    
};