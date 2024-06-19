#include "../Header/ServiceLocator.h"

// Include relevant header files for the services
// #include "EventService.h"
// #include "GraphicService.h"

// Constructor for initializing the ServiceLocator.
ServiceLocator::ServiceLocator() {
    graphicService = nullptr; // Initialize graphicService to null
    eventService = nullptr; // Initialize eventService to null
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
}

// Deletes and deallocates memory for all services.
void ServiceLocator::ClearAllServices() {
    delete(graphicService); // Delete the graphicService instance
    delete(eventService); // Delete the eventService instance
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
}

// Updates all services.
void ServiceLocator::Update() {
    graphicService->Update(); // Update graphic service
    eventService->Update(); // Update event service
}

// Renders using the services.
void ServiceLocator::Render() {
    graphicService->Render(); // Render graphic service
    // no event service because nothing to render
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