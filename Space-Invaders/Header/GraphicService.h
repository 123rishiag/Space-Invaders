#pragma once

#include <SFML/Graphics.hpp>

class GraphicService
{
private:

	const std::string gameWindowTitle = "Outscal Presents - Alien Invader";

	const int gameWindowWidth = 800;
	const int gameWindowHeight = 600;

	const sf::Color windowColor = sf::Color::Blue;

	sf::VideoMode* videoMode; // ptr to video mode
	sf::RenderWindow* gameWindow; // ptr to a RenderWindow

	void SetVideoMode(); // Method for setting our video mode
	void OnDestroy(); // method to run when window is deleted

public:
	GraphicService();
	~GraphicService(); //cleanup

	//method to create the game window. returns a pointer to an instance of the game window
	sf::RenderWindow* CreateGameWindow();


	void Initialize(); //lifecycle functions
	void Update(); //..
	void Render(); //..
	bool IsGameWindowOpen(); //check if the window is open

	sf::RenderWindow* GetGameWindow(); //getter for the game window instance
	sf::Color GetWindowColor();//get the color
};