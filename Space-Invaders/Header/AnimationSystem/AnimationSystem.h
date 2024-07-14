#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/AnimationSystem/AnimationSystemConfig.h"
#include "../../Header/UI/UIElement/ImageView.h"

namespace Animation
{
    class AnimationSystem
    {
    private:
        AnimationSystemConfig animationSystemConfig;

        sf::Vector2f animationPosition;
        UI::UIElement::ImageView* animationImage;

        void CreateUIElements();
        void InitializeImage();

        int currentFrame;
        sf::Clock clock;
        sf::Time frameTime;

    public:
        AnimationSystem(AnimationSystemConfig config);
        ~AnimationSystem();

        void Initialize(sf::Vector2f position);
        void Update();
        void Render();

        void Destroy();
    };
}