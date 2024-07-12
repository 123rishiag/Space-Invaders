#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Element/Bunker/BunkerData.h"
#include "../../Header/Collision/ICollider.h"

namespace Element 
{
    namespace Bunker 
    {
        class BunkerView;

        class BunkerController : public Collision::ICollider
        {
        private:
            BunkerView* bunkerView;
            BunkerData bunkerData;

        public:
            BunkerController();
            virtual ~BunkerController();

            virtual void Initialize(BunkerData data);
            void Update();
            void Render();

            sf::Vector2f GetBunkerPosition() const;

            const sf::Sprite& GetColliderSprite() override;
            void OnCollision(ICollider* otherCollider) override;
        };
    }
}