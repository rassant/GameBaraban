#include "../header/interface.hpp"
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>


Interface::
Interface (const Resource &resource, const Baraban & baraban, const Button &button) 
                     : resource_ (resource), baraban_(baraban), button_(button) 
{
	comments_ = std::make_shared <sf::Sprite> ();

	fon_.setTexture(*resource.GetTextureFon());
	highscore_.setTexture(*resource.GetHiscore());
	highscore_.setPosition (1300, 30);

	comments_->setTexture(*resource.GetHiscore());
	comments_->setPosition(515,630);
	comments_->setScale(3,3);
};


void Interface::Drow (sf::RenderWindow & window)
{
	window.draw(fon_);
	button_.StopWaitDrow(window);
	button_.StartWaitDrow(window);
	window.draw(*comments_);
}


