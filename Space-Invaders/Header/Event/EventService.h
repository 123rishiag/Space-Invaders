#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Event {
	class EventService
	{
	private:
		sf::Event gameEvent; //event variable
		sf::RenderWindow* gameWindow; //ptr to our game window

		bool IsGameWindowOpen() const;
		bool GameWindowWasClosed() const; //for the condition we already had - the title bar cross.
		bool HasQuitGame() const; //for our new 'ESC' condition



	public:
		EventService();
		~EventService();

		void Initialize();
		void Update();
		void ProcessEvents(); // while window is open we will check for events

		bool PressedEscapeKey() const;
		bool IsKeyboardEvent() const;
		bool PressedLeftKey() const;
		bool PressedRightKey() const;

	};
}