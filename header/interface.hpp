#pragma once
#include "baraban.hpp"
#include "animation.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include "button.hpp"


class Interface 
{
private:
    Resource  resource_;
    Baraban   baraban_;
    Button    button_;

    bool      start_animation = false;

    sf::Sprite fon_;
    sf::Sprite highscore_;
    std::shared_ptr<sf::Sprite> comments_;


public:
    Interface (const Resource &resource,  const Baraban & baraban, const Button &button) ;

    void Drow (sf::RenderWindow & window);
    std::shared_ptr<sf::Sprite> GetComments() {return comments_;};
};
