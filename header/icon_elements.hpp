#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <unordered_map>
#include <vector>
#include "resource.hpp"


class IconElements
{
    std::shared_ptr<Resource> resource_;
private:
    std::shared_ptr<std::vector<sf::Sprite>>  data_icons_;
    sf::Vector2f  position_;
    std::shared_ptr<std::vector<sf::Sprite>>  icons_;
    std::unordered_map<int, int>  index_to_icons_;

	            /*std::unordered_map<int, int>  icons_to_score_;*/

	int baraban_size_;    // количество элементов в барабане
	float icon_size_ = 192; // размер картинки

	void SetSpriteIcons    (const std::shared_ptr<sf::Texture> & );
	void SetRandomPosition (const sf::Vector2f & position);

public:
	void Drow (sf::RenderWindow & window)const;

	std::shared_ptr<std::vector<sf::Sprite>> GetIcons()        const {return icons_;}
	                           sf::Vector2f  GetPosition()     const {return position_;}
	std::shared_ptr<std::vector<sf::Sprite>> GetDataIcons()    const {return data_icons_;}
	            std::unordered_map<int, int> GetIndexToIcons() const {return index_to_icons_;}
	            /*std::unordered_map<int, int> GetIconsToScore() const {return icons_to_score_;};*/
    
    int GetBarabanSize()const {return baraban_size_;}	
    float GetIconSize()const {return icon_size_;}
	float GetIconElementsSize () const {return icon_size_;}

	IconElements (const Resource &  resource
                           , const int  baraban_size
		 , const sf::Vector2f&  position) ;


};
