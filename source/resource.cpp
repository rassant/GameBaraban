#include "../header/resource.hpp"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <stdexcept>

Resource::Resource (const sf::String & path_button
		  , const sf::String & path_icons
		  , const sf::String & path_fon
		  , const sf::String & path_hiscore
		  , const sf::String & path_to_font)
{
	button_ = std::make_shared<sf::Texture>();
	if (!button_->loadFromFile(path_button) ) { throw std::runtime_error("ERROR LOAD TEXTURE BUTTON");}

	fon_    = std::make_shared<sf::Texture>();
	if (!fon_->loadFromFile(path_fon)) { throw std::runtime_error("ERROR LOAD TEXTURE FON");}

	icon_elements_ = std::make_shared<sf::Texture>();
	if (!icon_elements_->loadFromFile(path_icons) ) {throw std::runtime_error("ERROR LOAD TEXTURE ICONS");}

	hiscore_ = std::make_shared<sf::Texture>();
	if (! hiscore_->loadFromFile(path_hiscore) ) {throw std::runtime_error("ERROR LOAD TEXTURE HISCORE");}

	font_ = std::make_shared<sf::Font>();
	font_->loadFromFile(path_to_font);
}
