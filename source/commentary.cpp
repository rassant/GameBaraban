#include "../header/commentary.hpp"
#include <SFML/System/String.hpp>
#include <stdexcept>
#include <string>

void Commentary::
SetIconsForComments ()
{
	icons_for_comments_.clear();
	icons_for_comments_.push_back( baraban_->GetBarabans()->at(0).GetIconWhenElementStoped());
	icons_for_comments_.push_back( baraban_->GetBarabans()->at(1).GetIconWhenElementStoped());
	icons_for_comments_.push_back( baraban_->GetBarabans()->at(2).GetIconWhenElementStoped());
	icons_for_comments_.push_back( baraban_->GetBarabans()->at(3).GetIconWhenElementStoped());

	if (icons_for_comments_.at(0)->getTexture()==nullptr)
	{
		throw std::runtime_error (" ERROR Commentary. не загрузил текстуру");
	}

	float bias = 65;
	float y_position = 757;

	icons_for_comments_.at(0)->setScale(0.25,0.25);
	icons_for_comments_.at(0)->setPosition(700, y_position);

	icons_for_comments_.at(1)->setScale(0.25, 0.25);
	icons_for_comments_.at(1)->setPosition(700, y_position + bias);

	icons_for_comments_.at(2)->setScale(0.25, 0.25);
	icons_for_comments_.at(2)->setPosition(700, y_position + bias * 2 );

	icons_for_comments_.at(3)->setScale(0.25, 0.25);
	icons_for_comments_.at(3)->setPosition(700, y_position + bias * 3 );

	SetScoreFromBaraban();
	SetTextScore( sf::Color::White, {800, y_position}, 50);
}


void Commentary::
DrawCommentsIcon (sf::RenderWindow & window)
{
	SetIconsForComments();
	window.draw(*icons_for_comments_.at(0));
	window.draw(*icons_for_comments_.at(1));
	window.draw(*icons_for_comments_.at(2));
	window.draw(*icons_for_comments_.at(3));

	texts_.at(0).Drow(window);
	texts_.at(1).Drow(window);
	texts_.at(2).Drow(window);
	texts_.at(3).Drow(window);
	texts_.at(4).Drow(window);
}


Commentary::
Commentary(std::shared_ptr<Baraban> baraban, const std::shared_ptr<sf::Font> & font)
:baraban_(baraban)
{
	texts_.emplace_back(font);
	texts_.emplace_back(font);
	texts_.emplace_back(font);
	texts_.emplace_back(font);

	texts_.emplace_back(font);
} 


void Commentary::
SetScoreFromBaraban ()
{
	barabans_score_.clear();

	for (auto baraban_solo: *baraban_->GetBarabans())
	{
		barabans_score_.push_back(static_cast<int>( baraban_solo.GetScore()));
	}
}


void Commentary::
SetTextScore(const sf::Color &color,
	     const sf::Vector2f position,
	     const int size_font) 
{
	float bias = 65;
	float y_position = 757;

	std::string number_str;
	total_score_ = 0;

	for (int i = 0; i < 4; ++i) {
		int score = (barabans_score_.at(static_cast<size_t>(i))== 0) ? 100 : barabans_score_.at(static_cast<size_t>(i)) * 10;
		total_score_ += score;
		number_str = std::to_string(score);

		texts_.at(static_cast<size_t>(i)).SetTextInit(number_str, color, {position.x, y_position + bias * static_cast<float>(i)}, size_font);
	}

	// total_score
	number_str = std::to_string(total_score_);
	texts_.at(4).SetTextInit(number_str, color, {position.x + 100, y_position + 50}, 120);
}
