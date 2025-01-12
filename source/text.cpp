#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include "../header/text.hpp"

TextComponents::
TextComponents (const std::shared_ptr<sf::Font> & font): font_ (font)
{
	text_.first  = std::make_shared< sf::Text >();
	text_.second = std::make_shared< sf::Text >();

	texture_ = std::make_shared<sf::Texture>();
}

void TextComponents::
SetTextInit  ( const sf::String & str, const sf::Color & color, const sf::Vector2f position , const int font_size)
{
	SetText   (str, position, font_size);
	SetShadow (str, position, font_size);

	text_.first->setFillColor  ( color ) ;
	text_.second->setFillColor ( sf::Color::Black ) ;
}

void TextComponents::
Drow (sf::RenderWindow & window)
{
	window.draw(*GetShadow());
	window.draw(*GetText());
}

void TextComponents::
SetText    ( const sf::String & str, const sf::Vector2f &position, const int font_size )
{
	text_.first->setFont     ( *font_   ) ;
	text_.first->setString   ( str      ) ;
	text_.first->setPosition ( position ) ;
	text_.first->setCharacterSize  ( static_cast<unsigned int>( font_size )) ;
}

void TextComponents::
SetShadow  ( const sf::String & str, const sf::Vector2f &position, const int font_size )
{
	text_.second->setFont     ( *font_ );
	text_.second->setString   ( str    ) ;
	text_.second->setPosition ( position.x + 1, position.y + 1 ) ;
	text_.second->setCharacterSize ( static_cast<unsigned int>(font_size )) ;
}
