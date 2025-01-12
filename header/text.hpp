#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <unordered_map>
#include <vector>



class TextComponents 
{
private:
	std::shared_ptr<sf::Font>    font_;
	std::shared_ptr<sf::Texture> texture_;

	std::pair < std::shared_ptr<sf::Text>, std::shared_ptr<sf::Text> > text_;

	void SetText    ( const sf::String & str, const sf::Vector2f &position, const int font_size );
	void SetShadow  ( const sf::String & str, const sf::Vector2f &position, const int font_size );

	std::shared_ptr<sf::Text> GetText   () const {return text_.first; }
	std::shared_ptr<sf::Text> GetShadow () const {return text_.second;}

public:
	void SetTextInit  ( const sf::String & str
		          , const sf::Color &  color
		     	  , const sf::Vector2f position 
		     	  , const int size_font);

	TextComponents (const std::shared_ptr<sf::Font> & font);
	void Drow (sf::RenderWindow & window);
	std::pair < std::shared_ptr<sf::Text>, std::shared_ptr<sf::Text> > GetTextComponents () const { return text_; }
};

