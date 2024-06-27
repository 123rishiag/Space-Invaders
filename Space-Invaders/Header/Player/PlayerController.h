#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerModel.h"
#include "PlayerView.h"

class PlayerController
{
private:
    PlayerView* playerView;
    PlayerModel* playerModel;

    void ProcessPlayerInput();
    void MoveLeft();
    void MoveRight();

public:
    PlayerController();
    ~PlayerController();

    void Initialize();
    void Update();
    void Render();

    sf::Vector2f GetPlayerPosition() const;
};