#include "Level_core.hpp"

void Level_core::Move_view()
{
    sf::Vector2f Level_view_position = Level_view.getCenter();
    sf::Vector2f Player_position = Player->Entity_rect.getPosition();
    if(Player_position.y > Level_view_position.y && Level_view_position.y + (View_size.y / 2) < Level_limits.y)
        Level_view.move(0, Player_position.y - Level_view_position.y);
    else if(Player_position.y < Level_view_position.y && Level_view_position.y - (View_size.y / 2) > 0)
        Level_view.move(0, Player_position.y - Level_view_position.y);
    else if(Player_position.x > Level_view_position.x && Level_view_position.x + (View_size.x / 2) < Level_limits.x)
        Level_view.move(Player_position.x - Level_view_position.x, 0);
    else if(Player_position.x < Level_view_position.x && Level_view_position.x - (View_size.x / 2) > 0)
        Level_view.move(Player_position.x - Level_view_position.x, 0);
}

void Level_core::Scale_view(sf::Vector2f New_size)
{
    const sf::Vector2f Default_size = {960, 540};
    float Factor = 1;
    while(New_size.x / Factor > Default_size.x || New_size.y / Factor > Default_size.y)
        Factor++;
    Level_view.setSize(New_size.x / Factor, New_size.y / Factor);
    View_size = {New_size.x / Factor, New_size.y / Factor};
}

void Level_core::Collosion_checker()
{
    View_position = {Level_view.getCenter().x  - View_size.x / 2, Level_view.getCenter().y - View_size.y / 2};
    Player->Margin_Collision(Level_limits);
    if (Level_rects.begin() != Level_rects.end())
        for(sf::RectangleShape& Level_rects_iter : Level_rects)
        {
            Player->Collision_detect_and_move(Level_rects_iter);
            for (House& Houses_iter : Houses)
            {
                Player->Collision_detect_and_move(Houses_iter.House_collision_rect);
                for(Enemy_entity& Enemies_iter : Enemies)
                {
                    Enemies_iter.Margin_Collision(Level_limits);
                    Enemies_iter.Collision_detect_and_move(Level_rects_iter);
                    Enemies_iter.Collision_detect_and_move(Houses_iter.House_collision_rect);
                }
            }
        }
}
