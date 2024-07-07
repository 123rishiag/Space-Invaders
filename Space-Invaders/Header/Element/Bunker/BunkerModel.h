#pragma once
#include <SFML/Graphics.hpp>

namespace Element {
	class BunkerModel {
	private:
		sf::Vector2f referencePosition = sf::Vector2f(950.f, 650.f);
		sf::Vector2f bunkerPosition;

    public:
        BunkerModel();
        ~BunkerModel();

        void Initialize();

        sf::Vector2f GetBunkerPosition() const;
        void SetBunkerPosition(sf::Vector2f position);

        sf::Vector2f GetReferencePosition() const;
        void SetReferencePosition(sf::Vector2f position);

	};
}