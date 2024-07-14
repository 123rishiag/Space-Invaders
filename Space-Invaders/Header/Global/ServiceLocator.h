#pragma once

#include "../Graphic/GraphicService.h"
#include "../Time/TimeService.h"
#include "../Event/EventService.h"
#include "../Gameplay/GameplayService.h"
#include "../Player/PlayerService.h"
#include "../Enemy/EnemyService.h"
#include "../Bullet/BulletService.h"
#include "../Element/ElementService.h"
#include "../Powerup/PowerupService.h"
#include "../Collision/CollisionService.h"
#include "../AnimationSystem/AnimationService.h"
#include "../UI/UIService.h"
#include "../Sound/SoundService.h"

namespace Global {

    // ServiceLocator Class Summary: This class manages access to various services in the application.
    // include relevant s files
    class ServiceLocator
    {
    private:
        // Private Attributes:
        Graphic::GraphicService* graphicService;
        Time::TimeService* timeService;
        Event::EventService* eventService;
        Gameplay::GameplayService* gameplayService;
        Player::PlayerService* playerService;
        Enemy::EnemyService* enemyService;
        Bullet::BulletService* bulletService;
        Element::ElementService* elementService;
        Powerup::PowerupService* powerupService;
        Collision::CollisionService* collisionService;
        Animation::AnimationService* animationService;
        UI::UIService* uiService;
        Sound::SoundService* soundService;
        // ..........................
        // ..........................


        // Private Constructor and Destructor:

        // Constructor for initializing the ServiceLocator.
        ServiceLocator();

        // Destructor for cleaning up resources upon object deletion.
        ~ServiceLocator();

        // Private Methods:
        void CreateServices(); 			// Creates instances of all services.
        void ClearAllServices(); 		//	Deletes and deallocates memory for all services.

    public:
        // Public Methods:
        static ServiceLocator* GetInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

        void Initialize(); 			//	Initializes the ServiceLocator.
        void Update(); 				//	Updates all services.
        void Render(); 				//	Renders using the services.

        // Methods to Get Specific Services: 
        Graphic::GraphicService* GetGraphicService() const;   // Retrieve the GraphicService instance
        Time::TimeService* GetTimeService() const;   // Retrieve the TimeService instance
        Event::EventService* GetEventService() const;   // Retrieve the EventService instance
        Gameplay::GameplayService* GetGameplayService() const;   // Retrieve the GameplayService instance
        Player::PlayerService* GetPlayerService() const;   // Retrieve the PlayerService instance
        Enemy::EnemyService* GetEnemyService() const;   // Retrieve the EnemyService instance
        Bullet::BulletService* GetBulletService() const;   // Retrieve the BulletService instance
        Element::ElementService* GetElementService() const;   // Retrieve the ElementService instance
        Powerup::PowerupService* GetPowerupService() const;   // Retrieve the PowerupService instance
        Collision::CollisionService* GetCollisionService() const;   // Retrieve the CollisionService instance
        Animation::AnimationService* GetAnimationService() const;   // Retrieve the AnimationService instance
        UI::UIService* GetUIService() const;   // Retrieve the UIService instance
        Sound::SoundService* GetSoundService() const;   // Retrieve the SoundService instance

        void DeleteServiceLocator();
    };
}