#include "../Central_stuff/Central_header.hpp"

struct To_draw
{
    sf::RectangleShape To_draw_rect;
    std::shared_ptr< sf::Texture > To_draw_texture;
    To_draw(sf::RectangleShape rect, std::shared_ptr< sf::Texture > rect_texture): To_draw_rect(rect), To_draw_texture(rect_texture)
    {
        To_draw_rect.setTexture(&*To_draw_texture);
    }
};

struct Big_rect
{
    void Load_from_file_and_set_texture(const std::string& File_name);
    sf::Vector2f Big_texture_size;
    std::vector< To_draw > Big_RectangleShapes;
    std::vector< To_draw >::iterator Big_RectangleShapes_iter;
private:
    Shared_resources shr_res;
};