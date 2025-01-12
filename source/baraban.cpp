#include <SFML/Graphics/Color.hpp>
#include "../header/baraban.hpp"
#include <memory>

Baraban::
Baraban (const Resource &     resource
              , const int     baraban_size
              , sf::Vector2f  position
              , const int     x_position) 
{
    icon_elements_ = std::make_shared< std::vector<BarabanSolo>>();

    auto line_1 = BarabanSolo (resource, baraban_size, position );  
    icon_elements_->push_back(line_1);
    position.x += static_cast<float>(x_position);

    auto line_2 = BarabanSolo (resource, baraban_size, position);  
    icon_elements_->push_back(line_2);
    position.x += static_cast<float>(x_position);

    auto line_3 = BarabanSolo (resource, baraban_size, position);
    icon_elements_->push_back(line_3);
    position.x += static_cast<float>(x_position);

    auto line_4 = BarabanSolo (resource, baraban_size, position);
    icon_elements_->push_back(line_4);
}



void Baraban::
Drow (sf::RenderWindow &window)
{
        for (auto line:* icon_elements_)
        {
            line.Drow(window);
        }
}
