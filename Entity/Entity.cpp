#include "Entity.hpp"

Entity::Entity(sf::FloatRect Entity_FloatRect, std::string File_name, int Damage, int Life, float Speed)
{
    Entity_rect_size = sf::Vector2f(Entity_FloatRect.width, Entity_FloatRect.height);
    Entity_rect.setSize(sf::Vector2f(Entity_FloatRect.width, Entity_FloatRect.height));
    Entity_rect.setPosition(sf::Vector2f(Entity_FloatRect.left, Entity_FloatRect.top));
    Entity_texture = Shared_resources::Acquire(File_name);
    Entity_rect.setTexture(&*Entity_texture);
    Entity_rect.setTextureRect(sf::IntRect(0, 0, (int)Entity_FloatRect.width, (int)Entity_FloatRect.height));
    Entity_damage = Damage;
    Entity_life = Life;
    Entity_movement_speed = Speed;
}

void Entity::Collision_detect_and_move(sf::RectangleShape The_puller)
{
    if(Entity_rect.getGlobalBounds().intersects(The_puller.getGlobalBounds()))
    {
        if(Entity_direction == Up)
        {
            Entity_rect.move(0, -(Entity_rect.getPosition().y - (The_puller.getPosition().y + The_puller.getSize().y)));
            Entity_direction = Down;
            return;
        }
        else if(Entity_direction == Down)
        {
            Entity_rect.move(0, The_puller.getPosition().y - (Entity_rect.getPosition().y + Entity_rect.getSize().y));
            Entity_direction = Up;
            return;
        }
        else if(Entity_direction == Left)
        {
            Entity_rect.move(-(Entity_rect.getPosition().x - (The_puller.getPosition().x + The_puller.getSize().x)), 0);
            Entity_direction = Right;
            return;
        }
        else if(Entity_direction == Right)
        {
            Entity_rect.move(The_puller.getPosition().x - (Entity_rect.getPosition().x + Entity_rect.getSize().x), 0);
            Entity_direction = Left;
            return;
        }
    }
}

void Entity::Margin_Collision(sf::Vector2f Map_Margins)
{
    if(Entity_rect.getPosition().y >= Map_Margins.y - Entity_rect.getSize().y)
    {
        Entity_rect.move(0, -Entity_movement_speed);
        Entity_direction = Up;
        return;
    }
    else if(Entity_rect.getPosition().y <= 0)
    {
        Entity_rect.move(0, Entity_movement_speed);
        Entity_direction = Down;
        return;
    }
    else if(Entity_rect.getPosition().x >= Map_Margins.x - Entity_rect.getSize().y)
    {
        Entity_rect.move(-Entity_movement_speed, 0);
        Entity_direction = Left;
        return;
    }
    else if(Entity_rect.getPosition().x <= 0)
    {
        Entity_rect.move(Entity_movement_speed, 0);
        Entity_direction = Right;
        return;
    }
}

int Entity::Generate_random(int max)
{
    int randomNumber = std::rand();
    float random = (randomNumber % max);
    int myRandom = random;
    return myRandom;
}
