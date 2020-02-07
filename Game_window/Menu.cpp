#include "Game_window.hpp"

void Game_window::Menu_init(int width, int height)
{
    Font.loadFromFile("Resources/Arial.ttf");
    Menu_buttons[0].Button_text.setString("Return");
    Menu_buttons[1].Button_text.setString("Controls");
    Menu_buttons[2].Button_text.setString("Exit");
    for(Button_counter = 0; Button_counter < Menu_buttons.size(); Button_counter++)
    {
        Menu_buttons[Button_counter].Button_text.setFont(Font);
        Menu_buttons[Button_counter].Button_text.setFillColor(sf::Color::Black);
        Menu_buttons[Button_counter].Button_rect.setSize(sf::Vector2f(192, 48));
        Menu_buttons[Button_counter].Button_rect.setPosition(sf::Vector2f(width / 2.3, height/(Menu_buttons.size() + 1) * (Button_counter + 1)));
        Menu_buttons[Button_counter].Button_rect.setFillColor(Gray);
        Menu_buttons[Button_counter].Button_text.setPosition(Menu_buttons[Button_counter].Button_rect.getPosition().x + (192 - Menu_buttons[Button_counter].Button_text.getLocalBounds().width) / 2, Menu_buttons[Button_counter].Button_rect.getPosition().y + (32 - Menu_buttons[Button_counter].Button_text.getLocalBounds().height) / 2);
    }
}
void Game_window::Menu(sf::RenderWindow& window)
{
    sf::Texture Menu_texture;
    sf::Sprite Menu_Sprite;
    Menu_init(window.getSize().x, window.getSize().y);
    Menu_texture.loadFromFile("Resources/Menu.png");
    Menu_Sprite.setTexture(Menu_texture);
    while(Returns_back == false)
    {
        while(window.pollEvent(Event))
        {
            switch(Event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    return;
                }
                case sf::Event::KeyPressed:
                    switch (Event.key.code)
                    {
                        case sf::Keyboard::Escape:
                            return;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
        if(Menu_buttons[0].Button_rect.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
            Menu_buttons[0].Button_text.setFillColor(sf::Color::White);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                Returns_back = true;
        }
        else
            Menu_buttons[0].Button_text.setFillColor(sf::Color::Black);
        if(Menu_buttons[1].Button_rect.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
            Menu_buttons[1].Button_text.setFillColor(sf::Color::White);
        else
            Menu_buttons[1].Button_text.setFillColor(sf::Color::Black);
        if(Menu_buttons[2].Button_rect.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
            Menu_buttons[2].Button_text.setFillColor(sf::Color::White);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                window.close();
                return;
            }
        }
        else
            Menu_buttons[2].Button_text.setFillColor(sf::Color::Black);
        window.clear();
        window.draw(Menu_Sprite);
        for(Button_counter = 0; Button_counter < Menu_buttons.size(); Button_counter++)
        {
            window.draw(Menu_buttons[Button_counter].Button_rect);
            window.draw(Menu_buttons[Button_counter].Button_text);
        }
        window.display();
    }
    Returns_back = false;
}
