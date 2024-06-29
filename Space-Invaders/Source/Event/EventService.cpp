#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Event {
    using namespace Global;
    EventService::EventService() { gameWindow = nullptr; }

    EventService::~EventService() = default; //calls the default destructor

    void EventService::Initialize()
    {
        gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
    }

    void EventService::Update()
    {
        ProcessEvents();
    }

    void EventService::ProcessEvents()
    {
        if (IsGameWindowOpen()) {
            while (gameWindow->pollEvent(gameEvent)) {
                // Check for window closure
                if (GameWindowWasClosed() || HasQuitGame())
                {
                    gameWindow->close();
                }
            }
        }
    }

    bool EventService::HasQuitGame() const { return (IsKeyboardEvent() && PressedEscapeKey()); } // only true if the ESC key is pressed and a keyboard event has been registered

    //checks for if a keyboard key has been pressed
    bool EventService::IsKeyboardEvent() const { return gameEvent.type == sf::Event::KeyPressed; }

    //control click on the SFML functions to see what they do internally
    bool EventService::PressedEscapeKey() const { return gameEvent.key.code == sf::Keyboard::Escape; }

    bool EventService::IsGameWindowOpen() const { return gameWindow != nullptr; }

    bool EventService::GameWindowWasClosed() const { return gameEvent.type == sf::Event::Closed; }

    bool EventService::PressedLeftKey() const { return gameEvent.key.code == sf::Keyboard::Left; }

    bool EventService::PressedRightKey() const { return gameEvent.key.code == sf::Keyboard::Right; }

    bool EventService::PressedLeftMouseButton() const
    {
        // check if a mouse button was pressed and which mouse button it was
        return gameEvent.type == sf::Event::MouseButtonPressed && gameEvent.mouseButton.button == sf::Mouse::Left;
    }

    bool EventService::PressedRightMouseButton() const
    {
        /*
        // same as above for the right button, if we want to we can move the mouse button
        // press check to another function altogether.
        */
        return gameEvent.type == sf::Event::MouseButtonPressed && gameEvent.mouseButton.button == sf::Mouse::Right;
    }
}