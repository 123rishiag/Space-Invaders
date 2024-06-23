#pragma once
#include <SFML/Graphics.hpp>

class PlayerService
{

private:

    int health = 3;
    sf::Vector2f position = sf::Vector2f(100.0f, 500.0f);
    float movementSpeed = 350.0f;
    int playerScore = 0;

    const sf::String playerTexturePath = "assets/textures/player_ship.png";

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    sf::RenderWindow* gameWindow; //as always

    void InitializePlayerSprite();
    void ProcessPlayerInput();

public:

    PlayerService();
    ~PlayerService();

    void Initialize();
    void Update();
    void Render();

    void MoveLeft();
    void MoveRight();
    sf::Vector2f GetPlayerPosition();
    int GetMoveSpeed();
    int GetScore() const;
    void SetScore(int newScore);
};