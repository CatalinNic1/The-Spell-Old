#pragma once

#include "../Central_stuff/Central_header.hpp"

struct Entity
{
public:
    Entity(sf::FloatRect Entity_FloatRect, std::string File_name, int Damage, int Life, float Speed);
    void Margin_Collision(sf::Vector2f Map_Margins);
    void Collision_detect_and_move(sf::RectangleShape The_puller);
    int Entity_damage;
    int Entity_life;
    enum Direction
    {
        Up,
        Down,
        Left,
        Right
    };
    int Entity_direction = Down;
    float Entity_movement_speed;
    sf::Vector2f Map_margin;
    sf::RectangleShape Entity_rect;
protected:
    std::shared_ptr< sf::Texture > Entity_texture;
    sf::Vector2f Entity_rect_size;
    int Frame_counter = 0;
    const int Frame_counter_limit = 4;
    int Generate_random(int max);
};
