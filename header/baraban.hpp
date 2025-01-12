#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "resource.hpp"
#include "baraban_solo.hpp"


class Baraban {
private:
	std::shared_ptr<std::vector<BarabanSolo>> icon_elements_;
public:

	Baraban () = delete;
	Baraban (const Resource &  resource
	              , const int  baraban_size
	           , sf::Vector2f  position
	              , const int  x_position) ;

	std::shared_ptr<std::vector<BarabanSolo>>GetBarabans () const {return  icon_elements_;}
	void Drow (sf::RenderWindow &window);
};
