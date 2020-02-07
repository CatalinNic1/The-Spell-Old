#pragma once

#include "../Game_window/Game_window.hpp"
#include "../Big_rect/Big_rect.hpp"
#include "../Player/Player.hpp"
#include "../Enemy/Enemy.hpp"
#include "../Houses/House.hpp"

#define Normal_speed 4
#define Speed_multiplier 100

struct Level_core
{
    std::unique_ptr< Player_entity > Player;
    std::vector< Enemy_entity > Enemies;
    std::vector< House > Houses;
    std::vector< sf::RectangleShape > Level_rects;
    void Push_house(sf::Vector2f House_position, sf::FloatRect Collision_FloatRect, sf::FloatRect Level_switcher_FloatRect1, sf::FloatRect Level_switcher_FloatRect2, std::string File_name)
    {
        Houses.emplace_back(House_position, Collision_FloatRect, Level_switcher_FloatRect1, Level_switcher_FloatRect2, File_name);
    }
    void Push_enemy(sf::FloatRect Enemy_FloatRect, std::string File_name, int Damage, int Life, float Speed)
    {
        Enemies.emplace_back(Enemy_FloatRect, File_name, Damage, Life, Speed);
    }
    void Push_rect(sf::Vector2f Position, sf::Vector2f Size)
    {
        sf::RectangleShape Rect_to_be_pushed;
        Rect_to_be_pushed.setPosition(Position);
        Rect_to_be_pushed.setSize(Size);
        Level_rects.emplace_back(Rect_to_be_pushed);
    }
    void Move_objects()
    {
        Move_player();
        Move_view();
        Move_enemies();
    }
    void Draw_objects()
    {
        Big_rect_draw();
        Draw_houses();
        Draw_enemies();
        Draw_player();
    }
    sf::View Level_view;
    sf::Vector2f Level_limits;
    sf::Clock Delta_time;
    Game_window Game_window_session;
    Big_rect Big_rects;
    void Collosion_checker();
    void Move_view();
    void Scale_view(sf::Vector2f New_size);
    float Movement_speed;
private:
    sf::Vector2f View_size;
    sf::Vector2f View_position;
    void Big_rect_draw()
    {
        for(To_draw& Big_RectangleShape : Big_rects.Big_RectangleShapes)
            Game_window_session.Window.draw(Big_RectangleShape.To_draw_rect);
    }
    void Move_enemies()
    {
        for(Enemy_entity& Enemy : Enemies)
        {
            Enemy.Entity_movement_speed = Movement_speed;
            Enemy.Move_enemy();
        }
    }
    void Draw_enemies()
    {
        for(Enemy_entity& Enemy : Enemies)
        {
            if(Enemy.Entity_rect.getGlobalBounds().intersects({View_position.x, View_position.y, View_size.x, View_size.y}))
                Game_window_session.Window.draw(Enemy.Entity_rect);
        }
    }
    void Draw_houses()
    {
        for(House& House : Houses)
        {
            if(House.House_collision_rect.getGlobalBounds().intersects({View_position.x, View_position.y, View_size.x, View_size.y}))
                Game_window_session.Window.draw(House.House_sprite);
        }
    }
    void Move_player()
    {
        Player->Entity_movement_speed = Movement_speed;
        Player->Move_player();
    }
    void Draw_player()
    {
        Game_window_session.Window.draw(Player->Entity_rect);
    }
};
