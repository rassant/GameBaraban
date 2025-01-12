#include "../header/mouse_controller.hpp"

MouseController::MouseController ( const Button &button):  button_(button) 
{ }


bool MouseController:: 
ClickStop (sf::RenderWindow & window, sf::Event &event,  bool& stop_baraban)
{
	sf::Vector2f mouse_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

	if ((*button_.GetStop()).getGlobalBounds().contains(mouse_position) 
		      && event.type == sf::Event::MouseButtonPressed)
	{
		stop_baraban  = false;
		return true;
	}
	return false;
}


bool MouseController:: 
ClickStart (sf::RenderWindow & window, sf::Event &event,  bool& start_baraban, sf::Clock &start_clock)
{
	sf::Vector2f mouse_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

	if ((*button_.GetStart()).getGlobalBounds().contains(mouse_position)
		&& event.type == sf::Event::MouseButtonPressed ) 
	{
		start_clock.restart();
		start_baraban  = true;
		return  true;
	}
	return false;
}


void MouseController::
UnderButtonToGreen (sf::RenderWindow & window)
{
	sf::Vector2f mouse_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

	if ((*button_.GetStart()).getGlobalBounds().contains(mouse_position) ) {
		button_.StartGreenDrow(window);

	} else if ((*button_.GetStop()).getGlobalBounds().contains(mouse_position) ) {
		button_.StopGreenDrow(window);
	}
}

