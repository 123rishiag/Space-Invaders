#pragma once

// ServiceLocator Class Summary: This class manages access to various services in the application.
// include relevant headers files

class ServiceLocator
{
private:
    // Private Attributes:
    // - eventService: Manages event-related functionalities.
    // - graphicService: Handles graphics-related tasks.
    // ..........................
    // ..........................

    // Static instance of the ServiceLocator
    static ServiceLocator* instance;

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
    //EventService* GetEventService();   // Retrieve the EventService instance
    //GraphicService* GetGraphicService();   // Retrieve the GraphicService instance

};