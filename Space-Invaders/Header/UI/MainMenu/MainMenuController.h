#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:
			// Constants:
			const float buttonWidth = 400.f;
			const float buttonHeight = 140.f;

			sf::RenderWindow* gameWindow;

			// Textures:
			sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;

			sf::Texture playButtonTexture;
			sf::Sprite playButtonSprite;

			sf::Texture instructionsButtonTexture;
			sf::Sprite instructionsButtonSprite;

			sf::Texture quitButtonTexture;
			sf::Sprite quitButtonSprite;

			// Since this is a single image, we can check if it loaded or not during initialization
			void InitializeBackgroundImage();
			void ScaleBackgroundImage();

			// however, we have 3 buttons so it's better to create a separate function to check if they are loaded
			void InitializeButtons();
			bool LoadButtonTexturesFromFile();
			void SetButtonSprites();

			void ScaleAllButtons();
			void ScaleButton(sf::Sprite* buttonToScale) const;
			void PositionButtons();

			void ProcessButtonInteractions();
			bool ClickedButton(sf::Sprite*, sf::Vector2f);

		public:
			MainMenuUIController();

			void Initialize();
			void Update();
			void Render();

		};
	}
}