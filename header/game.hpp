#pragma once
#include "button.hpp"
#include "interface.hpp"
#include "resource.hpp"
#include "baraban.hpp"
#include "animation.hpp"
#include "mouse_controller.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include "commentary.hpp"

class Game {
private:

    const int baraban_size = 36; // должно быть >= 6
    const sf::Vector2f baraban_position {520, -267}; // расположение первого барабана {x,y} остальные х+200
    const int baraban_interval = 200;

	std::shared_ptr<Resource>         resource_;
	std::shared_ptr<Baraban>          baraban_;
	std::shared_ptr<Animation>        animation_;
	std::shared_ptr<Button>           button_;
	std::shared_ptr<Interface>        interface_;
	std::shared_ptr<MouseController>  mouse_controller_;
	std::shared_ptr<Commentary>       commentary_;

    void SetResource (const sf::String & path_button
	        , const sf::String & path_icons
	        , const sf::String & path_fon
	        , const sf::String & path_hiscore
	        , const sf::String & path_to_font
              );


public:

std::shared_ptr<Animation> GetAnimation() const {return animation_;}
std::shared_ptr<Interface> GetInterface() const {return interface_;}
std::shared_ptr<Resource>  GetResource () const {return resource_;}
std::shared_ptr<MouseController> GetMouseController() const { return  mouse_controller_; }

Game () = delete;
Game (	const sf::String & button,  
	const sf::String & elements , 
	const sf::String & fon, 
	const sf::String & hiscore, 
	const sf::String & font
);
void Draw (sf::RenderWindow &);
};


