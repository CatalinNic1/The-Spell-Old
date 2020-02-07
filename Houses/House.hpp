#pragma once

#include "../Central_stuff/Central_header.hpp"

struct House
{
    sf::RectangleShape House_collision_rect, Change_area_trigger[2];
    sf::Sprite House_sprite;
    House(sf::Vector2f House_position, sf::FloatRect Collision_FloatRect, sf::FloatRect Change_area_trigger_float_rect1, sf::FloatRect Change_area_trigger_float_rect2, std::string File_name);
private:
    std::shared_ptr< sf::Texture > House_texture;
};
