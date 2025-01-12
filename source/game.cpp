#include "../header/game.hpp"
#include "../header/interface.hpp"
#include "../header/resource.hpp"
#include "../header/baraban.hpp"
#include "../header/animation.hpp"
#include "../header/mouse_controller.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

Game::
Game (	
        const sf::String & button,  
	const sf::String & elements , 
	const sf::String & fon, 
	const sf::String & hiscore, 
	const sf::String & font)
    :
    resource_         ( std::make_shared <Resource>        ( button, elements, fon, hiscore, font )) ,
    baraban_          ( std::make_shared <Baraban>         ( *resource_, baraban_size, baraban_position , baraban_interval)) ,
    animation_        ( std::make_shared <Animation>       ( *baraban_)) ,
    button_           ( std::make_shared <Button>          ( resource_->GetTextureButton())) ,
    interface_        ( std::make_shared <Interface>       ( *resource_, *baraban_, *button_ )) ,
    mouse_controller_ ( std::make_shared <MouseController> ( *button_)),
    commentary_       ( std::make_shared <Commentary>      ( baraban_, resource_->GetFont_()) )
{}


void Game::
Draw (sf::RenderWindow & window)
{

        baraban_->Drow(window);
        interface_->Drow(window);

        mouse_controller_->UnderButtonToGreen (window);
        commentary_->DrawCommentsIcon(window);
}
