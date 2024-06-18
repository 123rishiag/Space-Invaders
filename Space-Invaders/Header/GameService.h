#pragma once

#include <SFML/Graphics.hpp>
#include "ServiceLocator.h"

class GameService
{
private:
	ServiceLocator* serviceLocator;
	sf::RenderWindow* gameWindow;

	void Initialize();		// Handles game initialization.
	void InitializeVariables();// Handles game initialization variables.
	void Destroy();			// Handles cleanup tasks.

public:
	GameService();			// Constructor for initializing the GameService object.
	~GameService();	    // Destructor for cleaning up resources upon object deletion.

	void Ignite();			// Initiates the game.
	void Update();			// Updates the game logic and game state.
	void Render();			// Renders each frame of the game.
	bool IsRunning();		// Checks if the game is currently running.

	sf::RenderWindow* GetGameWindow(); // Getter for the game window instance

};