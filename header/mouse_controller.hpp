#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "button.hpp"
#include "animation.hpp"

class MouseController
{
	Button button_;

    bool ChangeColorOnHover (const sf::Event & event
                            ,const sf::RenderWindow &window
                            , std::vector<sf::Sprite> & clicked);


public:
    MouseController ( const Button &button );

    void UnderButtonToGreen   (sf::RenderWindow & window);

    bool ClickStop   (sf::RenderWindow & window,  sf::Event &event, bool& stop_baraban);
    bool ClickStart  (sf::RenderWindow & window,  sf::Event &event, bool& start_baraban, sf::Clock &start_clock);
    Button GetButton() {return button_;}

};

