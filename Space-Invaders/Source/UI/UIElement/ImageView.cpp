#include "../../Header/UI/UIElement/ImageView.h"

namespace UI
{
    namespace UIElement
    {
        ImageView::ImageView() = default;

        ImageView::~ImageView() = default;

        void ImageView::Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f position)
        {
            UIView::Initialize();
            SetTexture(texturePath);
            SetScale(imageWidth, imageHeight);
            SetPosition(position);
        }

        void ImageView::Update()
        {
            UIView::Update();
        }

        void ImageView::Render()
        {
            UIView::Update();

            if (uiState == UIState::VISIBLE)
            {
                gameWindow->draw(imageSprite);
            }
        }

        void ImageView::SetTexture(sf::String texturePath)
        {
            if (imageTexture.loadFromFile(texturePath))
            {
                imageSprite.setTexture(imageTexture);
            }
        }

        void ImageView::SetScale(float width, float height)
        {
            float scaleX = width / imageSprite.getTexture()->getSize().x;
            float scaleY = height / imageSprite.getTexture()->getSize().y;

            imageSprite.setScale(scaleX, scaleY);
        }

        void ImageView::SetPosition(sf::Vector2f position)
        {
            imageSprite.setPosition(position);
        }

        void ImageView::SetRotation(float rotationAngle)
        {
            imageSprite.setRotation(rotationAngle);
        }

        void ImageView::SetOriginAtCentre()
        {
            imageSprite.setOrigin(imageSprite.getLocalBounds().width / 2, imageSprite.getLocalBounds().height / 2);
        }

        void ImageView::SetImageAlpha(float alpha)
        {
            sf::Color color = imageSprite.getColor();
            color.a = alpha;
            imageSprite.setColor(color);
        }

        void ImageView::SetCentreAlinged()
        {
            float xPosition = (gameWindow->getSize().x / 2) - (imageSprite.getGlobalBounds().width / 2);
            float yPosition = imageSprite.getGlobalBounds().getPosition().y;

            imageSprite.setPosition(xPosition, yPosition);
        }
    }
}