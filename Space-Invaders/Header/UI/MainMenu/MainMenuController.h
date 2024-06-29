#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:

			sf::RenderWindow* gameWindow;

		public:
			MainMenuUIController();

			void Initialize();
			void Update();
			void Render();

		};
	}
}