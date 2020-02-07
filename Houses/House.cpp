#include "House.hpp"

House::House(sf::Vector2f House_position, sf::FloatRect Collision_FloatRect, sf::FloatRect Change_area_trigger_float_rect1, sf::FloatRect Change_area_trigger_float_rect2, std::string File_name)
{
    House_collision_rect.setPosition(sf::Vector2f(Collision_FloatRect.left, Collision_FloatRect.top));
    House_collision_rect.setSize(sf::Vector2f(Collision_FloatRect.width, Collision_FloatRect.height));
    House_sprite.setPosition(House_position);
    House_texture = Shared_resources::Acquire(File_name);
    House_sprite.setTexture(*House_texture);
    Change_area_trigger[0].setPosition(sf::Vector2f(Change_area_trigger_float_rect1.left, Change_area_trigger_float_rect1.top));
    Change_area_trigger[0].setSize(sf::Vector2f(Change_area_trigger_float_rect1.width, Change_area_trigger_float_rect1.height));
    Change_area_trigger[1].setPosition(sf::Vector2f(Change_area_trigger_float_rect2.left, Change_area_trigger_float_rect2.top));
    Change_area_trigger[1].setSize(sf::Vector2f(Change_area_trigger_float_rect2.width, Change_area_trigger_float_rect2.height));
}
