#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Element/Bunker/BunkerModel.h"

namespace Element 
{
    namespace Bunker 
    {
        class BunkerView;

        class BunkerController 
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
        };
    }
}