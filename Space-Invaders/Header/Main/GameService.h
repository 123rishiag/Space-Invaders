#pragma once

#include <SFML/Graphics.hpp>
namespace Global {
	class ServiceLocator;
}
namespace Main {
	class GameService
	{
	private:
		Global::ServiceLocator* serviceLocator;
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
		bool IsRunning() const;		// Checks if the game is currently running.

		sf::RenderWindow* GetGameWindow() const; // Getter for the game window instance

	};
}