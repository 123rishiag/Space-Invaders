#pragma once
#include <SFML/Graphics.hpp>

namespace Animation
{
    struct AnimationSystemConfig
    {
        sf::String animationTexturePath;

        float spriteSheetWidth;
        float spriteSheetHeight;

        float tileWidth; //one frame of the sprite sheet
        float tileHeight;

        int numberOFAnimationFrames; //total frames
        float frameDuration; //duration of a single frame

        AnimationSystemConfig() = default; // Use default for default constructor

        //this will allow us to initialize an animation with it's configuration.
        AnimationSystemConfig(sf::String texturePath, float spriteWidth, float spriteHeight,
            float tWidth, float tHeight, int frames, float duration);
        ~AnimationSystemConfig();
    };
}