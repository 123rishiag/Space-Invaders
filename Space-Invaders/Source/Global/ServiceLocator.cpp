#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Global {
    using namespace Graphic;
    using namespace Time;
    using namespace Event;
    using namespace Gameplay;
    using namespace Player;
    using namespace Enemy;
    using namespace Bullet;
    using namespace Element;
    using namespace Powerup;
    using namespace Collision;
    using namespace UI;
    using namespace Sound;
    using namespace Main;

    // Constructor for initializing the ServiceLocator.
    ServiceLocator::ServiceLocator() {
        graphicService = nullptr; // Initialize graphicService to null
        timeService = nullptr; // Initialize timeService to null
        eventService = nullptr; // Initialize eventService to null
        gameplayService = nullptr; // Initialize gameplayService to null
        playerService = nullptr; // Initialize playerService to null
        enemyService = nullptr; // Initialize enemyService to null
        bulletService = nullptr; // Initialize bulletService to null
        elementService = nullptr; // Initialize elementService to null
        powerupService = nullptr; // Initialize powerupService to null
        collisionService = nullptr; // Initialize collisionService to null
        uiService = nullptr; // Initialize uiService to null
        soundService = nullptr; // Initialize uiService to null
        CreateServices(); // Call CreateServices to instantiate services
    }

    // Destructor for cleaning up resources upon object deletion.
    ServiceLocator::~ServiceLocator() {
        ClearAllServices(); // Call ClearAllServices to delete any allocated services	
    }

    // Creates instances of all services.
    void ServiceLocator::CreateServices() {
        graphicService = new GraphicService(); // Dynamically create a GraphicService instance
        timeService = new TimeService(); // Dynamically create a TimeService instance
        eventService = new EventService(); // Dynamically create a EventService instance
        gameplayService = new GameplayService(); // Dynamically create a GameplayService instance
        playerService = new PlayerService(); // Dynamically create a PlayerService instance
        enemyService = new EnemyService(); // Dynamically create a EnemyService instance
        bulletService = new BulletService(); // Dynamically create a bulletService instance
        elementService = new ElementService(); // Dynamically create a ElementService instance
        powerupService = new PowerupService(); // Dynamically create a PowerupService instance
        collisionService = new CollisionService(); // Dynamically create a CollisionService instance
        uiService = new UIService(); // Dynamically create a UIService instance
        soundService = new SoundService(); // Dynamically create a SoundService instance
    }

    // Deletes and deallocates memory for all services.
    void ServiceLocator::ClearAllServices() {
        delete(graphicService); // Delete the graphicService instance
        delete(timeService); // Delete the timeService instance
        delete(eventService); // Delete the eventService instance
        delete(gameplayService); // Delete the gameplayService instance
        delete(playerService); // Delete the playerService instance
        delete(enemyService); // Delete the enemyService instance
        delete(bulletService); // Delete the bulletService instance
        delete(elementService); // Delete the elementService instance
        delete(powerupService); // Delete the powerupService instance
        delete(collisionService); // Delete the collisionService instance
        delete(uiService); // Delete the uiService instance
        delete(soundService); // Delete the soundService instance
    }

    // Provides a method to access the unique ServiceLocator instance (object).
    ServiceLocator* ServiceLocator::GetInstance() {
        static ServiceLocator instance; // we will discuss what 'static' means at a later time.
        return &instance; // Return address of the instance
    }

    // Initializes the ServiceLocator.
    void ServiceLocator::Initialize() {
        graphicService->Initialize(); // Initialize graphic service
        timeService->Initialize(); // Initialize time service
        eventService->Initialize(); // Initialize event service
        gameplayService->Initialize(); // Initialize gameplay service
        playerService->Initialize(); // Initialize player service
        enemyService->Initialize(); // Initialize enemy service
        bulletService->Initialize(); // Initialize bullet service
        elementService->Initialize(); // Initialize element service
        powerupService->Initialize(); // Initialize powerup service
        collisionService->Initialize(); // Initialize collision service
        uiService->Initialize(); // Initialize ui service
        soundService->Initialize(); // Initialize sound service
    }

    // Updates all services.
    void ServiceLocator::Update() {
        graphicService->Update(); // Update graphic service
        timeService->Update(); // Update time service
        eventService->Update(); // Update event service
        if (GameService::GetGameState() == GameState::GAMEPLAY)
        {
            gameplayService->Update(); // Update gameplay service
            playerService->Update(); // Update player service
            enemyService->Update(); // Update enemy service
            bulletService->Update(); // Update bullet service
            elementService->Update(); // Update element service
            powerupService->Update(); // Update powerup service
            collisionService->Update(); // Update collision service
        }
        uiService->Update(); // Update ui service
    }

    // Renders using the services.
    void ServiceLocator::Render() {
        graphicService->Render(); // Render graphic service
        // no time service because nothing to render
        // no event service because nothing to render
        if (GameService::GetGameState() == GameState::GAMEPLAY)
        {
            gameplayService->Render(); // Update gameplay service
            playerService->Render(); // Render player service
            enemyService->Render(); // Render enemy service
            bulletService->Render(); // Render bullet service
            elementService->Render(); // Render element service
            powerupService->Render(); // Render powerup service
            // No render for collision service
        }
        uiService->Render(); // Render ui service
    }

    // Methods to Get Specific Services:

    // Retrieve the GraphicService instance
    GraphicService* ServiceLocator::GetGraphicService() const {
        return graphicService;
    }
    // Retrieve the TimeService instance
    TimeService* ServiceLocator::GetTimeService() const {
        return timeService;
    }
    // Retrieve the EventService instance
    EventService* ServiceLocator::GetEventService() const {
        return eventService;
    }
    // Retrieve the GameplayService instance
    GameplayService* ServiceLocator::GetGameplayService() const {
        return gameplayService;
    }
    // Retrieve the PlayerService instance
    PlayerService* ServiceLocator::GetPlayerService() const {
        return playerService;
    }
    // Retrieve the EnemyService instance
    EnemyService* ServiceLocator::GetEnemyService() const {
        return enemyService;
    }
    // Retrieve the BulletService instance
    BulletService* ServiceLocator::GetBulletService() const {
        return bulletService;
    }
    // Retrieve the ElementService instance
    ElementService* ServiceLocator::GetElementService() const {
        return elementService;
    }
    // Retrieve the PowerupService instance
    PowerupService* ServiceLocator::GetPowerupService() const {
        return powerupService;
    }
    // Retrieve the CollisionService instance
    CollisionService* ServiceLocator::GetCollisionService() const {
        return collisionService;
    }
    // Retrieve the UIService instance
    UIService* ServiceLocator::GetUIService() const {
        return uiService;
    }
    // Retrieve the SoundService instance
    SoundService* ServiceLocator::GetSoundService() const {
        return soundService;
    }

    void ServiceLocator::DeleteServiceLocator()
    {
        delete(this);
    }
}