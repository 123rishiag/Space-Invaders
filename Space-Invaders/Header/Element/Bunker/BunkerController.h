#pragma once
#include <SFML/Graphics.hpp>

namespace Element {
    class BunkerView;
    class BunkerModel;
	class BunkerController {
    protected:
        BunkerView* bunkerView;
        BunkerModel* bunkerModel;

    public:
        BunkerController();
        virtual ~BunkerController();

        virtual void Initialize();
        void Update();
        void Render();

        sf::Vector2f GetBunkerPosition();
	};
}