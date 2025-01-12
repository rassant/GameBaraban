#include "../header/baraban_solo.hpp"
#include "../header/icon_elements.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>


BarabanSolo::
BarabanSolo (const Resource &  resource
                  , const int  baraban_size
	       , sf::Vector2f  position) 
{
    icon_element_ = std::make_shared< IconElements>(IconElements(resource, baraban_size, position ));
    icon_when_element_stoped_ = std::make_shared<sf::Sprite>();

    move_controller_.clock.restart();
}


// Запуск перемещения иконок с плавным стартом
void BarabanSolo::
StartIconPositions ( const float delta_time )
{
    if (move_controller_.current_speed < move_controller_.max_speed) {
        move_controller_.current_speed += move_controller_.acceleration * delta_time; // Увеличиваем скорость
        if (move_controller_.current_speed > move_controller_.max_speed) {
            move_controller_.current_speed = move_controller_.max_speed; // Ограничиваем максимальную скорость
        }
    }
    for (auto &icon :* icon_element_->GetDataIcons()) {
        sf::Vector2f current_position = icon.getPosition();
        current_position.y += move_controller_.current_speed * delta_time;
        icon.setPosition(current_position);

        if (current_position.y > (static_cast<float>(icon_element_->GetBarabanSize()) - 1.0f) * icon_element_->GetIconSize() ) {
            icon.setPosition({current_position.x, - icon_element_->GetIconSize()}); // Начинаем сверху (используем высоту иконки)
        }
    }
}


void BarabanSolo::
UpdateIconSpeed(const float delta_time)
{
        move_controller_.current_speed -= move_controller_.acceleration * delta_time; 
}


void BarabanSolo::
MoveIcons(const float delta_time)
{
        move_controller_.current_speed -= move_controller_.acceleration * delta_time; 

        for (auto &icon : *icon_element_->GetDataIcons()) 
        {
            sf::Vector2f current_position = icon.getPosition();

            current_position.y += move_controller_.current_speed * delta_time/2;
            icon.setPosition(current_position);

            if (current_position.y > (static_cast<float>(icon_element_->GetBarabanSize())- 1) * icon_element_->GetIconSize() ) {
                icon.setPosition({current_position.x, -icon_element_->GetIconSize()}); // Начинаем сверху (можно использовать высоту иконки)
            }
        }
}


void BarabanSolo::
SoftStop (const float delta_time)
{
        for (size_t i = 0; i < icon_element_->GetDataIcons()->size(); i++) 
        {
            sf::Vector2f current_position = icon_element_->GetDataIcons()->at(i).getPosition();

            // получаем значение остановившейся иконки
            if (static_cast<int>((icon_element_->GetDataIcons()->at(i).getPosition().y-420)) % 192 > 0
             && static_cast<int>((icon_element_->GetDataIcons()->at(i).getPosition().y-420)) < 192){
                score_ = static_cast<size_t>(icon_element_->GetIndexToIcons().at(static_cast< int>(i)));
                icon_when_element_stoped_ = std::make_shared<sf::Sprite>( icon_element_->GetIcons()->at(score_));
            }
            if (static_cast<int>((current_position.y-120)) % static_cast<int>((icon_element_->GetIconSize())) == 0)
            {
                break;
            }
            else {
                move_controller_.current_speed += move_controller_.acceleration * delta_time/2; 
            }

            if (current_position.y > (static_cast<float>(icon_element_->GetBarabanSize())- 1) * icon_element_->GetIconSize() ) {
                icon_element_->GetDataIcons()->at(i).setPosition({current_position.x, -icon_element_->GetIconSize()}); // Начинаем сверху (можно использовать высоту иконки)
            }
        }
}


bool  BarabanSolo::
StopIconPositions ( const float delta_time )
{
    float min_speed = move_controller_.acceleration;

    if (move_controller_.current_speed > min_speed) {
        UpdateIconSpeed ( delta_time );
        MoveIcons       ( delta_time );
        return false;
    }
    else {
        SoftStop(delta_time);
        return true;
    }
}


void BarabanSolo::
Drow(sf::RenderWindow &window)
{
    for (const auto &icon: *icon_element_->GetDataIcons() )
    {
        window.draw(icon);
    }
}

