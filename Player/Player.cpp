#include "Player.hpp"

void Player_entity::Move_player()
{
    Entity_rect.setTextureRect(sf::IntRect(Entity_rect_size.x * Entity_direction * Frame_counter_limit, 0, Entity_rect_size.x, Entity_rect_size.y));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        return;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        return;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
        return;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
        return;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        Entity_rect.move(0, -Entity_movement_speed);
        Entity_direction = Up;
        Entity_rect.setTextureRect(sf::IntRect(Entity_rect_size.x * Entity_direction * Frame_counter_limit + Entity_rect_size.x * Frame_counter, 0, Entity_rect_size.x, Entity_rect_size.y));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        Entity_rect.move(0, Entity_movement_speed);
        Entity_direction = Down;
        Entity_rect.setTextureRect(sf::IntRect(Entity_rect_size.x * Entity_direction * Frame_counter_limit + Entity_rect_size.x * Frame_counter, 0, Entity_rect_size.x, Entity_rect_size.y));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        Entity_rect.move(-Entity_movement_speed, 0);
        Entity_direction = Left;
        Entity_rect.setTextureRect(sf::IntRect(Entity_rect_size.x * Entity_direction * Frame_counter_limit + Entity_rect_size.x * Frame_counter, 0, Entity_rect_size.x, Entity_rect_size.y));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Entity_rect.move(Entity_movement_speed, 0);
        Entity_direction = Right;
        Entity_rect.setTextureRect(sf::IntRect(Entity_rect_size.x * Entity_direction * Frame_counter_limit + Entity_rect_size.x * Frame_counter, 0, Entity_rect_size.x, Entity_rect_size.y));
    }
    Frame_counter++;
    if(Frame_counter == Frame_counter_limit)
        Frame_counter = 0;
}