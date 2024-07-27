#include "../public/EventService.h"
#include "../public/ServiceLocator.h"


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

bool EventService::isGameWindowOpen() {
    return gameWindow->isOpen();
}

bool EventService::gameWindowWasClosed() {
    return gameEvent.type == sf::Event::Closed;
}

bool EventService::hasQuitGame() {
    return isKeyboardEvent() && pressedEscapeKey();
}