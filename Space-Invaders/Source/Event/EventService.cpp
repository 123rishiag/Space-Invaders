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
        UpdateMouseButtonsState(leftMouseButtonState, sf::Mouse::Left);
        UpdateMouseButtonsState(rightMouseButtonState, sf::Mouse::Right);
        UpdateKeyboardButtonsState(leftArrowButtonState, sf::Keyboard::Left);
        UpdateKeyboardButtonsState(rightArrowButtonState, sf::Keyboard::Right);
        UpdateKeyboardButtonsState(aButtonState, sf::Keyboard::A);
        UpdateKeyboardButtonsState(dButtonState, sf::Keyboard::D);
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

    void EventService::UpdateMouseButtonsState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton)
    {
        if (sf::Mouse::isButtonPressed(mouseButton))
        {
            switch (currentButtonState)
            {
            case ButtonState::RELEASED:
                currentButtonState = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                currentButtonState = ButtonState::HELD;
                break;
            }
        }
        else
        {
            currentButtonState = ButtonState::RELEASED;
        }
    }

    void EventService::UpdateKeyboardButtonsState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton)
    {
        if (sf::Keyboard::isKeyPressed(keyboardButton))
        {
            switch (currentButtonState)
            {
            case ButtonState::RELEASED:
                currentButtonState = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                currentButtonState = ButtonState::HELD;
                break;
            }
        }
        else
        {
            currentButtonState = ButtonState::RELEASED;
        }
    }

    bool EventService::HasQuitGame() const { return (IsKeyboardEvent() && PressedEscapeKey()); } // only true if the ESC key is pressed and a keyboard event has been registered

    //checks for if a keyboard key has been pressed
    bool EventService::IsKeyboardEvent() const { return gameEvent.type == sf::Event::KeyPressed; }

    //control click on the SFML functions to see what they do internally
    bool EventService::PressedEscapeKey() const { return gameEvent.key.code == sf::Keyboard::Escape; }

    bool EventService::IsGameWindowOpen() const { return gameWindow != nullptr; }

    bool EventService::GameWindowWasClosed() const { return gameEvent.type == sf::Event::Closed; }

    bool EventService::PressedLeftKey() const { return leftArrowButtonState == ButtonState::HELD; }

    bool EventService::PressedRightKey() const { return rightArrowButtonState == ButtonState::HELD; }

    bool EventService::PressedAKey() const { return aButtonState == ButtonState::HELD; }

    bool EventService::PressedDKey() const { return dButtonState == ButtonState::HELD; }


    bool EventService::PressedLeftMouseButton() const { return leftMouseButtonState == ButtonState::PRESSED; }

    bool EventService::PressedRightMouseButton() const { return rightMouseButtonState == ButtonState::PRESSED; }
}