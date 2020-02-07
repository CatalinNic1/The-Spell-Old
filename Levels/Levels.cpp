#include "Levels.hpp"

void Levels::Level1()
{
    Game_window_session.Window.create(sf::VideoMode(1280, 768), "game");
    Player = std::make_unique< Player_entity >(sf::FloatRect(400, 400, 24, 32), "Resources/Player.png", 0, 0, 0.25f);
    Big_rects.Load_from_file_and_set_texture("Resources/Thevillage.png");
    Level_limits = {1280, 768};
    Level_view.reset(sf::FloatRect(0, 0, 1280, 768));
    Push_rect(sf::Vector2f(832, 1), sf::Vector2f(96, 1));
    Push_rect(sf::Vector2f(0 ,0), sf::Vector2f(448, 352));
    Push_house(sf::Vector2f(992, 64), sf::FloatRect(992, 64, 224, 176), sf::FloatRect(0, 0, 0, 0), sf::FloatRect(0, 0, 0, 0), "Resources/house4.png");
    Push_house(sf::Vector2f(992, 352), sf::FloatRect(992, 352, 160, 112), sf::FloatRect(0, 0, 0, 0), sf::FloatRect(0, 0, 0, 0), "Resources/house3.png");
    Push_house(sf::Vector2f(576, 320), sf::FloatRect(576, 320, 192, 144), sf::FloatRect(0, 0, 0, 0), sf::FloatRect(0, 0, 0, 0), "Resources/store1.png");
    Push_house(sf::Vector2f(0, 416), sf::FloatRect(0, 416, 192, 176), sf::FloatRect(0, 0, 0, 0), sf::FloatRect(0, 0, 0, 0), "Resources/house1.png");
    Push_house(sf::Vector2f(992, 544), sf::FloatRect(992, 544, 224, 144), sf::FloatRect(0, 0, 0, 0), sf::FloatRect(0, 0, 0, 0), "Resources/house2.png");
    for(uint i = 1; i <= 10; i++)
        Push_enemy(sf::FloatRect(800, 300, 24, 32), "Resources/Enemy.png", 0, 0, 0.025f);
    while(Game_window_session.Window.isOpen())
    {
        while(Game_window_session.Window.pollEvent(Game_window_session.Event))
        {
            if(Game_window_session.Event.type == sf::Event::Closed)
                Game_window_session.Window.close();
            if(Game_window_session.Event.type == sf::Event::Resized)
                Scale_view(sf::Vector2f(Game_window_session.Event.size.width, Game_window_session.Event.size.height));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Game_window_session.Menu(Game_window_session.Window);
            Game_window_session.Window.setView(Level_view);
        }
        Movement_speed = Normal_speed * Speed_multiplier * Delta_time.restart().asSeconds();
        Game_window_session.Window.clear();
        Draw_objects();
        Move_objects();
        Collosion_checker();
        Game_window_session.Window.setView(Level_view);
        Game_window_session.Window.display();
    }
    Shared_resources::Remove_Orphans();
}
