#pragma once 
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "baraban.hpp"
#include "text.hpp"

class Commentary
{
	std::vector<TextComponents> texts_; 
	std::shared_ptr<Baraban> baraban_;
private:
	std::vector<std::shared_ptr<sf::Sprite>> icons_for_comments_;
	std::vector<int> barabans_score_;
    	int total_score_ = 0;

	void SetIconsForComments (); // сохраняем иконки на которых остановился барабан
	void SetScoreFromBaraban (); // подсчет очков. 
	void SetTextScore ( const sf::Color &  color
		     	  , const sf::Vector2f position 
		     	  , const int size_font);
public:
	Commentary() = delete;
	Commentary(std::shared_ptr<Baraban> baraban, const std::shared_ptr<sf::Font> & font);
	void DrawCommentsIcon (sf::RenderWindow & window);
};
