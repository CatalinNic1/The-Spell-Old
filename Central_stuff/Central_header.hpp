#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <array>
#include <random>

#define BREAKPOINT \
    asm("int $3")

typedef unsigned int uint;

struct Button
{
    sf::Text Button_text;
    sf::RectangleShape Button_rect;
};

struct Shared_resources
{
    static std::shared_ptr< sf::Texture > Acquire(const std::string& Texture_file_name)
    {
        Texture_map_iter = Texture_map.find(Texture_file_name);
        if(Texture_map_iter != Texture_map.end())
            return Texture_map_iter->second;
        else
        {
            std::shared_ptr< sf::Texture > Ptr_texture = std::make_shared< sf::Texture >();
            Ptr_texture->loadFromFile(Texture_file_name);
            Texture_map.insert({Texture_file_name, Ptr_texture});
            return Ptr_texture;
        }
    }

    static std::shared_ptr< sf::Texture > Acquire(const std::string& Texture_file_name, sf::IntRect Texture_area)
    {
        Texture_map_iter = Texture_map.find(Texture_file_name);
        if(Texture_map_iter != Texture_map.end())
            return Texture_map_iter->second;
        else
        {
            std::shared_ptr< sf::Texture > Ptr_texture = std::make_shared< sf::Texture >();
            Ptr_texture->loadFromFile(Texture_file_name, Texture_area);
            Texture_map.insert({Texture_file_name, Ptr_texture});
            return Ptr_texture;
        }
    }

    static void Remove_Orphans()
    {
        for(Texture_map_iter = Texture_map.begin(); Texture_map_iter != Texture_map.end(); Texture_map_iter++)
        {
            if(Texture_map_iter->second.use_count() == 1)
                Texture_map_iter = Texture_map.erase(Texture_map_iter);
        }
    }

private:
    static inline std::unordered_map< std::string, std::shared_ptr< sf::Texture > > Texture_map;
    static inline std::unordered_map< std::string, std::shared_ptr< sf::Texture > >::iterator Texture_map_iter;
};
