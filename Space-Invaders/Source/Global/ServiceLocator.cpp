#include "../../Header/Global/ServiceLocator.h"

namespace Global {
    using namespace Graphic;
    using namespace Event;
    using namespace Player;
    using namespace Time;
    // Constructor for initializing the ServiceLocator.
    ServiceLocator::ServiceLocator() {
        graphicService = nullptr; // Initialize graphicService to null
        eventService = nullptr; // Initialize eventService to null
        playerService = nullptr; // Initialize playerService to null
        timeService = nullptr; // Initialize timeService to null
        CreateServices(); // Call CreateServices to instantiate services
    }

    // Destructor for cleaning up resources upon object deletion.
    ServiceLocator::~ServiceLocator() {
        ClearAllServices(); // Call ClearAllServices to delete any allocated services	
    }

    // Creates instances of all services.
    void ServiceLocator::CreateServices() {
        graphicService = new GraphicService(); // Dynamically create a GraphicService instance
        eventService = new EventService(); // Dynamically create a EventService instance
        playerService = new PlayerService(); // Dynamically create a PlayerService instance
        timeService = new TimeService(); // Dynamically create a TimeService instance
    }

    // Deletes and deallocates memory for all services.
    void ServiceLocator::ClearAllServices() {
        delete(graphicService); // Delete the graphicService instance
        delete(eventService); // Delete the eventService instance
        delete(playerService); // Delete the playerService instance
        delete(timeService); // Delete the timeService instance
    }

    // Provides a method to access the unique ServiceLocator instance (object).
    ServiceLocator* ServiceLocator::GetInstance() {
        static ServiceLocator instance; // we will discuss what 'static' means at a later time.
        return &instance; // Return address of the instance
    }

    // Initializes the ServiceLocator.
    void ServiceLocator::Initialize() {
        graphicService->Initialize(); // Initialize graphic service
        eventService->Initialize(); // Initialize event service
        playerService->Initialize(); // Initialize player service
        timeService->Initialize(); // Initialize time service
    }

    // Updates all services.
    void ServiceLocator::Update() {
        graphicService->Update(); // Update graphic service
        eventService->Update(); // Update event service
        playerService->Update(); // Update player service
        timeService->Update(); // Update time service
    }

    // Renders using the services.
    void ServiceLocator::Render() {
        graphicService->Render(); // Render graphic service
        // no event service because nothing to render
        playerService->Render(); // Render player service
        // no time service because nothing to render
    }

    // Methods to Get Specific Services:

    // Retrieve the GraphicService instance
    GraphicService* ServiceLocator::GetGraphicService() const {
        return graphicService;
    }
    // Retrieve the EventService instance
    EventService* ServiceLocator::GetEventService() const {
        return eventService;
    }
    // Retrieve the PlayerService instance
    PlayerService* ServiceLocator::GetPlayerService() const {
        return playerService;
    }
    // Retrieve the TimeService instance
    TimeService* ServiceLocator::GetTimeService() const {
        return timeService;
    }
}