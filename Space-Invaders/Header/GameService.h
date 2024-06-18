#pragma once

class GameService
{
private:
	void Initialize();		// Handles game initialization.
	void Destroy();			// Handles cleanup tasks.

public:
	GameService();			// Constructor for initializing the GameService object.
	~GameService();	    // Destructor for cleaning up resources upon object deletion.

	void Ignite();			// Initiates the game.
	void Update();			// Updates the game logic and game state.
	void Render();			// Renders each frame of the game.
	bool IsRunning();		// Checks if the game is currently running.
};