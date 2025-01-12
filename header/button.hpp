#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include "text.hpp"

class Button 
{
private:
    std::shared_ptr<sf::Texture> texture_button_;
    std::shared_ptr<sf::Font> font_;

    TextComponents text_start_;
    TextComponents text_stop_;

    const sf::Vector2f button_scale_ = {0.5, 0.5};

    std::shared_ptr<sf::Sprite> start_;
    std::shared_ptr<sf::Sprite> stop_;

    void ParseTextureToSprite ();

    void SettingStop  (const sf::Vector2f &position);
    void SettingStart (const sf::Vector2f &position);

public:

    Button (const std::shared_ptr<sf::Texture> & texture);
    std::shared_ptr<sf::Sprite> GetStart() { return start_;}
    std::shared_ptr<sf::Sprite> GetStop () { return stop_;};

    void StartWaitDrow  (sf::RenderWindow & window) ;
    void StartGreenDrow (sf::RenderWindow & window) ;

    void StopWaitDrow   (sf::RenderWindow & window) ;
    void StopGreenDrow  (sf::RenderWindow & window) ;
};
