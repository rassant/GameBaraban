#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>
#include "baraban.hpp"

class Animation 
{
    std::shared_ptr<Baraban> baraban_;
private:
    sf::Clock   clock_;
    sf::Clock   start_clock_;

    float delta_time_;

    bool start_animation_ = true;
    bool all_barabans_not_stoped = true;

    void StartBaraban (const float delay);
    void  StopBaraban ();
public:

    Animation() = delete;
    Animation (const Baraban & baraban);

    void SetStatusAnimation (const bool & new_status) { start_animation_ = new_status;}
    void TimerStart();

    void StartAnimation ( const float delay_between_start_baraban );
    void StopAnimation  ();

    std::shared_ptr<Baraban> GetBaraban () { return baraban_;};
};
