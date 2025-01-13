#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include "./header/game.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1728, 1152), "Game", sf::Style::Close);
    const float auto_stop_time = 10.0; // авто остановка после старта
    sf::Event event;
    bool start_animation = false;
    sf::Clock delta_clock;

    bool auto_stop = false;
    sf::Clock auto_stop_clock;

    //------------------------------------------------------------------------------------------------------
    Game game (
        "./resource/image/button_clean_big.png"
        ,"./resource/image/all_elements_green.png"
        ,"./resource/image/photo/_fon_city_shadow.png"
        ,"./resource/image/hiscore.png"
        ,"./resource/font/impact.ttf"
    );


    while (window.isOpen()) {
        if (auto_stop == false )
        {
            auto_stop_clock.restart().asSeconds();
        }

        while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) { window.close(); }
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { window.close(); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && start_animation == false) 
			{ 
				start_animation = true; 
				auto_stop = true;
			};
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && start_animation == true)  
			{
				start_animation = false; };


			if (start_animation == false )
			{
				game.GetMouseController()->ClickStart(window, event, start_animation, delta_clock);
				auto_stop = true;
			}	

			if (start_animation == true )
			{
				game.GetMouseController()->ClickStop(window, event, start_animation );
			}	

		}
        window.clear();

        if (start_animation == true) {
            game.GetAnimation()->StartAnimation( 0.5);

        if (auto_stop == true && auto_stop_clock.getElapsedTime().asSeconds() > auto_stop_time)
        {
           start_animation = false;
           auto_stop = false;
        }
        } else {
            game.GetAnimation()->StopAnimation();
            auto_stop_clock.restart().asSeconds();
        }

        game.Draw(window);

        window.display();
        game.GetAnimation()->TimerStart();

    }//while
    return 0;
}
