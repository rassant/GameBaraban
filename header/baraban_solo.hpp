#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include "icon_elements.hpp"

struct MovementController
{
	float max_speed     = 5800.0f; // Максимальная скорость перемещения
	float current_speed = 0.0f;   // Текущая скорость
	float acceleration  = 300.0f; // Ускорение (пикселей в секунду в секунду)

	sf::Clock   clock;
	float delta_time;
};


class BarabanSolo
{
private:
	MovementController move_controller_;
	size_t score_ = 0;
	std::shared_ptr<IconElements> icon_element_;
	std::shared_ptr<sf::Sprite> icon_when_element_stoped_;

	void UpdateIconSpeed(const float delta_time);
	void MoveIcons(const float delta_time);
	void SoftStop (const float delta_time);

public:
	BarabanSolo () = delete;
	BarabanSolo (const Resource &  resource
	                  , const int  baraban_size
	               , sf::Vector2f  position) ;


	void Drow(sf::RenderWindow &window);

	void StartIconPositions ( const float delta_time );
	bool  StopIconPositions ( const float delta_time );

	size_t GetScore()const {return score_;}
	std::shared_ptr<sf::Sprite> GetIconWhenElementStoped()const {return icon_when_element_stoped_;};
	std::shared_ptr<IconElements> GetIconElements (){return icon_element_;}

};
