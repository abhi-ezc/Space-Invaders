#include "../../public/event/EventService.h"
#include "../../public/global/ServiceLocator.h"
#include "../../public/graphic/GraphicService.h"

namespace Event
{
    using namespace Global;
    // constructor
    EventService::EventService() { 
        gameWindow = nullptr;
    }

    EventService::~EventService() = default;

    void EventService::initialize() {
        gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    }

    void EventService::update() {
        processEvents();
    }

    void EventService::processEvents() { 
        if( isGameWindowOpen() )
        {
            while( gameWindow->pollEvent(gameEvent) )
            {
                if( gameWindowWasClosed() || hasQuitGame() )
                {
                    ServiceLocator::getInstance()->getGraphicService()->closeGameWindow();
                }
            }
        }
    }

    bool EventService::pressedEscapeKey() {
        return gameEvent.key.code == sf::Keyboard::Escape;
    }

    bool EventService::isKeyboardEvent() {
        return gameEvent.type == sf::Event::KeyPressed;
    }

    bool EventService::isLeftKeyPressed() {
        return sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    }

    bool EventService::isRightKeyPressed() {
        return sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    }

    bool EventService::isLeftMouseButtonPressed() {
        return  gameEvent.type == sf::Event::MouseButtonPressed && gameEvent.mouseButton.button == sf::Mouse::Left;
    }

    bool EventService::isRightMouseButtonPressed() {
        return  gameEvent.type == sf::Event::MouseButtonPressed && gameEvent.mouseButton.button == sf::Mouse::Right;
    }

    bool EventService::isGameWindowOpen() {
        return gameWindow->isOpen();
    }

    bool EventService::gameWindowWasClosed() {
        return gameEvent.type == sf::Event::Closed;
    }

    bool EventService::hasQuitGame() {
        return isKeyboardEvent() && pressedEscapeKey();
    }
}