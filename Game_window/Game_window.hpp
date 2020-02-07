#pragma once

#include "../Central_stuff/Central_header.hpp"

struct Game_window
{
    sf::Event Event;
    sf::RenderWindow Window;
    void Menu(sf::RenderWindow& window);
private:
    void Menu_init(int width, int height);
    uint Button_counter;
    bool Returns_back = false;
    sf::Font Font;
    sf::Color Gray{sf::Color(144, 144, 144)};
    std::array< Button, 3 > Menu_buttons;
};
