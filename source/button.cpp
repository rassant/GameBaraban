#include "../header/button.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <iostream>
#include <stdexcept>
#include "../header/text.hpp"


void Button::
SettingStop  (const sf::Vector2f &position)
{
	sf::Vector2i icon_size = {640, 192};

	sf::Sprite stop_wait (*texture_button_, sf::IntRect({0,0}, icon_size));
	stop_   = std::make_shared<sf::Sprite>(stop_wait);
	stop_->setPosition(position);
	stop_->setScale(button_scale_);
}


void Button::
SettingStart  (const sf::Vector2f &position)
{
	sf::Vector2i icon_size = {640, 192};

	sf::Sprite start_wait (*texture_button_, sf::IntRect({0,0}, icon_size));
	start_   = std::make_shared<sf::Sprite>(start_wait);
	start_->setPosition(position);
	start_->setScale(button_scale_);

}


void Button::
ParseTextureToSprite()
{
	sf::Vector2f  stop_possition = {75, 1000};
	sf::Vector2f start_possition = {1320, 1000};

	SettingStop  (  stop_possition ) ;
	SettingStart ( start_possition ) ;

	text_start_.SetTextInit(L"Старт", sf::Color::White , {start_possition.x + 60, start_possition.y }, 80);
	text_stop_.SetTextInit (L"Стоп",  sf::Color::White , { stop_possition.x + 75,  stop_possition.y }, 80);
}


Button::
Button (const std::shared_ptr<sf::Texture> & texture) 
	: texture_button_ (texture)
	, font_ (std::make_shared<sf::Font>())
	, text_start_  (TextComponents (font_))
	, text_stop_   (TextComponents (font_))
{
	ParseTextureToSprite ();

	if (!font_->loadFromFile("./resource/font/impact.ttf"
			  )) {
		throw std::runtime_error( "Не удалось загрузить шрифт!" );
	}
}


void Button::
StartWaitDrow  (sf::RenderWindow & window) 
{
	(*start_).setColor(sf::Color::White);
	window.draw(*start_);
	text_start_.Drow(window);
}

void  Button::
StartGreenDrow (sf::RenderWindow & window) {
	(*start_).setColor(sf::Color (126,255,94));
	window.draw(*start_);
	text_start_.Drow(window);
}

void  Button::
StopWaitDrow   (sf::RenderWindow & window) {
	(*stop_).setColor(sf::Color::White);
	window.draw(*stop_);
	text_stop_.Drow(window);
}

void  Button::
StopGreenDrow  (sf::RenderWindow & window) {
	(*stop_).setColor(sf::Color (126,255,94));
	window.draw(*stop_);
	text_stop_.Drow(window);
}

