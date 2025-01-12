#include "../header/animation.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

// Класс для анимации барабана 

// StartBaraban - запускает анимацию барабана
// StopBaraban - останавливает анимацию барабана

// TimerStart - запускает таймер
// Drow - отрисовывает барабан

Animation::
Animation (const Baraban & baraban )
{
    baraban_    = std::make_shared<Baraban>(baraban);
    delta_time_ = clock_.restart().asSeconds();

    start_clock_.restart();
    start_clock_.restart().asSeconds();
}


void Animation::
TimerStart()
{
	delta_time_ = clock_.restart().asSeconds(); 
}


void Animation::
StartBaraban(const float delay)
{
	if (start_animation_ == false)
	{
		return;
	}

	baraban_->GetBarabans()->at(0).StartIconPositions(delta_time_);

	if ( start_clock_.getElapsedTime().asSeconds() >= delay * 2.0f) { 
		baraban_->GetBarabans()->at(1).StartIconPositions(delta_time_);
	}
	if ( start_clock_.getElapsedTime().asSeconds() >= delay * 3.0f) { 
		baraban_->GetBarabans()->at(2).StartIconPositions(delta_time_);
	}
	if ( start_clock_.getElapsedTime().asSeconds() >= delay * 4.0f) { 
		baraban_->GetBarabans()->at(3).StartIconPositions(delta_time_);
	}
}


void Animation::
StartAnimation ( const float delay_between_start_baraban )
{
    if ( all_barabans_not_stoped == true )
    {
        start_animation_ = true;
        StartBaraban (delay_between_start_baraban);
    }else {
        StopBaraban();
    }
}

void Animation::
StopAnimation ()
{
    start_animation_ = false;
    start_clock_.restart();
    StopBaraban();
}


void  Animation::
StopBaraban ()
{
	if (start_animation_ == true)
	{
		return ;
	}
    all_barabans_not_stoped  = baraban_->GetBarabans()->at(0).StopIconPositions(delta_time_);
    baraban_->GetBarabans()->at(1).StopIconPositions(delta_time_);
    baraban_->GetBarabans()->at(2).StopIconPositions(delta_time_);
    baraban_->GetBarabans()->at(3).StopIconPositions(delta_time_);
}

