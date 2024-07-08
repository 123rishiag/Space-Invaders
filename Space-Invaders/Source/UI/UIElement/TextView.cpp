#include "../../header/UI/UIElement/TextView.h"
#include "../../header/Global/Config.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;

		sf::Font TextView::fontBubbleBobble;
		sf::Font TextView::fontDsDigib;

		TextView::TextView() = default;

		TextView::~TextView() = default;

		void TextView::Initialize(sf::String textValue, sf::Vector2f position, FontType fontType, int fontSize, sf::Color color)
		{
			UIView::Initialize();

			SetText(textValue);
			SetTextPosition(position);
			SetFont(fontType);
			SetFontSize(fontSize);
			SetTextColor(color);
		}

		void TextView::Update()
		{
			UIView::Update();
		}

		void TextView::Render()
		{
			UIView::Render();

			if (uiState == UIState::VISIBLE)
			{
				gameWindow->draw(text);
			}
		}

		void TextView::InitializeTextView()
		{
			LoadFont();
		}

		void TextView::LoadFont()
		{
			fontBubbleBobble.loadFromFile(Config::bubbleBobbleFontPath);
			fontDsDigib.loadFromFile(Config::dsdigibFontPath);
		}

		void TextView::SetText(sf::String textValue)
		{
			text.setString(textValue);
		}

		void TextView::SetFont(FontType fontType)
		{
			switch (fontType)
			{
			case FontType::BUBBLE_BOBBLE:
				text.setFont(fontBubbleBobble);
				break;
			case FontType::DS_DIGIB:
				text.setFont(fontDsDigib);
				break;
			}
		}

		void TextView::SetFontSize(int fontSize)
		{
			text.setCharacterSize(fontSize);
		}

		void TextView::SetTextPosition(sf::Vector2f position)
		{
			text.setPosition(position);
		}

		void TextView::SetTextColor(sf::Color color)
		{
			text.setFillColor(color);
		}

		void TextView::SetTextCentreAligned()
		{
			float xPosition = (gameWindow->getSize().x - text.getLocalBounds().width) / 2;
			float yPosition = text.getGlobalBounds().getPosition().y;

			text.setPosition(sf::Vector2f(xPosition, yPosition));
		}
	}
}