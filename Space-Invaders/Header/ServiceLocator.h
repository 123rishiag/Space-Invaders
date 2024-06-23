#pragma once

#include "GraphicService.h"
#include "EventService.h"
#include "PlayerService.h"
#include "TimeService.h"

// ServiceLocator Class Summary: This class manages access to various services in the application.
// include relevant headers files

class ServiceLocator
{
private:
    // Private Attributes:
    GraphicService* graphicService;
    EventService* eventService;
    PlayerService* playerService;
    TimeService* timeService;
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
    GraphicService* GetGraphicService() const;   // Retrieve the GraphicService instance
    EventService* GetEventService() const;   // Retrieve the EventService instance
    PlayerService* GetPlayerService() const;   // Retrieve the PlayerService instance
    TimeService* GetTimeService() const;   // Retrieve the TimeService instance
};