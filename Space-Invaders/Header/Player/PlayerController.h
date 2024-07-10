#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

namespace Player {
    enum class PlayerState;
    class PlayerModel;
    class PlayerView;

    class PlayerController
    {
    private:
        PlayerView* playerView;
        PlayerModel* playerModel;

        void ProcessPlayerInput();
        void FireBullet();
        void MoveLeft();
        void MoveRight();

    public:
        PlayerController(Entity::EntityType ownerType);
        ~PlayerController();

        void Initialize();
        void Update();
        void Render();

        sf::Vector2f GetPlayerPosition() const;

        Entity::EntityType GetEntityType() const;

    };
}