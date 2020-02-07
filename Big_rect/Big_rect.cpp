#include "Big_rect.hpp"

void Big_rect::Load_from_file_and_set_texture(const std::string& File_name)
{
    Big_RectangleShapes.clear();
    sf::RectangleShape rect;
    sf::Image image;
    uint texture_max_size = sf::Texture::getMaximumSize();
    image.loadFromFile(File_name);
    for(uint x = 0; x <= image.getSize().x; x += texture_max_size)
        for(uint y = 0; y <= image.getSize().y; y += texture_max_size)
        {
            std::shared_ptr< sf::Texture > ptr_txt = Shared_resources::Acquire(File_name, sf::IntRect(x, y, texture_max_size, texture_max_size));
            rect.setPosition(x, y);
            rect.setSize(sf::Vector2f(ptr_txt->getSize()));
            Big_RectangleShapes.emplace_back(rect, ptr_txt);
        }
}
