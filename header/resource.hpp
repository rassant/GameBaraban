#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>


class Resource
{
private:
    std::shared_ptr<sf::Texture> button_; 	
    std::shared_ptr<sf::Texture> icon_elements_;
    /*std::shared_ptr<sf::Texture> lives_;*/

    std::shared_ptr<sf::Texture> fon_;
    std::shared_ptr<sf::Texture> hiscore_;

    std::shared_ptr<sf::Font> font_;

public:
    Resource () = delete;
    Resource (const sf::String & path_button
	    , const sf::String & path_icons
	    , const sf::String & path_fon
	    , const sf::String & path_hiscore
	    , const sf::String & path_to_font
            );

    std::shared_ptr<sf::Texture> GetTextureButton()const {return button_;}
    std::shared_ptr<sf::Texture> GetTextureIcons ()const {return icon_elements_;}
    std::shared_ptr<sf::Texture> GetTextureFon   ()const {return fon_;}
    std::shared_ptr<sf::Texture> GetHiscore      ()const {return hiscore_;}

    std::shared_ptr<sf::Font> GetFont_()const {return font_;}
    /*std::shared_ptr<sf::Texture> GetLives        ()const {return lives_;}*/


};

