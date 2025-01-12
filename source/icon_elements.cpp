#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include <random>
#include <vector>
#include "../header/icon_elements.hpp"


void IconElements::
SetSpriteIcons (const std::shared_ptr<sf::Texture> & texture)
{

    sf::Vector2i icon_size = {256, 256};
	sf::Sprite sprite_cherry     ( * texture, sf::IntRect({256, 0},   icon_size));   icons_->push_back(sprite_cherry);
	sf::Sprite sprite_grape      ( * texture, sf::IntRect({512, 0},   icon_size));   icons_->push_back(sprite_grape);
	sf::Sprite sprite_orange     ( * texture, sf::IntRect({768, 0},   icon_size));   icons_->push_back(sprite_orange);
	sf::Sprite sprite_seven      ( * texture, sf::IntRect({0,   256}, icon_size));   icons_->push_back(sprite_seven);
	sf::Sprite sprite_limon      ( * texture, sf::IntRect({256, 256}, icon_size));   icons_->push_back(sprite_limon);
	sf::Sprite sprite_plum       ( * texture, sf::IntRect({768, 256}, icon_size));   icons_->push_back(sprite_plum);
	sf::Sprite sprite_star       ( * texture, sf::IntRect({0,   512}, icon_size));   icons_->push_back(sprite_star);
	sf::Sprite sprite_watermelon ( * texture, sf::IntRect({256, 512}, icon_size));   icons_->push_back(sprite_watermelon);
};


void IconElements::
SetRandomPosition (const sf::Vector2f & position)
{

    data_icons_ = std::make_shared<std::vector<sf::Sprite>>();
	data_icons_->reserve(static_cast<size_t>(baraban_size_));

	for (int i = 0; i < baraban_size_; i++)
	{
		std::random_device rd; 
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(0, 99);

		int random_number = distrib(gen);
		int random_icon = random_number % static_cast<int>(icons_->size());
		index_to_icons_[i] = random_icon;

		data_icons_->push_back(icons_->at(static_cast<size_t>(random_icon)));
		data_icons_->back().setPosition(position_+ position );
		data_icons_->back().setScale({0.55f, 0.55f });

		position_.y+=icon_size_;
	}
}


void  IconElements::
Drow (sf::RenderWindow & window)const
{
	for (const auto & icon: *data_icons_)
	{
		window.draw(icon);
	}
};


IconElements::
IconElements(const Resource & resource
	    ,const int   baraban_size
	    ,const sf::Vector2f & position) : baraban_size_ (baraban_size) , icon_size_ (192)
{
	std::shared_ptr<Resource> resource_ = std::make_shared<Resource>(resource);

	icons_ = std::make_shared<std::vector<sf::Sprite>>();
	const int tatal_icons    = 8;
	icons_->reserve(tatal_icons);

	SetSpriteIcons(resource.GetTextureIcons());
	SetRandomPosition(position);
}
