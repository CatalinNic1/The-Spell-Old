#include "Enemy.hpp"

void Enemy_entity::Move_enemy()
{
    Move_counter++;
    if(Move_counter > Change_direction_limit * Entity_movement_speed)
    {
        Entity_direction = Generate_random(4);
        Move_counter = 0;
    }
    if(Entity_direction == Up)
    {
        Entity_rect.move(0, -Entity_movement_speed);
        Entity_rect.setTextureRect(sf::IntRect(Entity_rect_size.x * Entity_direction * Frame_counter_limit + Entity_rect_size.x * Frame_counter, 0, Entity_rect_size.x, Entity_rect_size.y));
    }
    else if(Entity_direction == Down)
    {
        Entity_rect.move(0, Entity_movement_speed);
        Entity_rect.setTextureRect(sf::IntRect(Entity_rect_size.x * Entity_direction * Frame_counter_limit + Entity_rect_size.x * Frame_counter, 0, Entity_rect_size.x, Entity_rect_size.y));
    }
    else if(Entity_direction == Left)
    {
        Entity_rect.move(-Entity_movement_speed, 0);
        Entity_rect.setTextureRect(sf::IntRect(Entity_rect_size.x * Entity_direction * Frame_counter_limit + Entity_rect_size.x * Frame_counter, 0, Entity_rect_size.x, Entity_rect_size.y));
    }
    else if(Entity_direction == Right)
    {
        Entity_rect.move(Entity_movement_speed, 0);
        Entity_rect.setTextureRect(sf::IntRect(Entity_rect_size.x * Entity_direction * Frame_counter_limit + Entity_rect_size.x * Frame_counter, 0, Entity_rect_size.x, Entity_rect_size.y));
    }
    Frame_counter++;
    if(Frame_counter == Frame_counter_limit)
       Frame_counter = 0;
}