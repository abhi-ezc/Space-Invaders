#pragma once
#include "./../../public/graphic/GraphicService.h"

namespace Graphic
{
#pragma region Life Cycle Functions

    GraphicService::GraphicService() {
        videoMode = nullptr; // initialize videoMode ptr with nullptr
        gameWindow = nullptr; // initialize gameWindow ptr with nullptr
    }

    void GraphicService::initialize() {
        createGameWindow();
    }

    void GraphicService::update() {
        gameWindow->clear(windowColor);
    }

    void GraphicService::render() {
        gameWindow->display();
    }

    // Destructor and OnDestroy
    GraphicService::~GraphicService() {
        onDestroy(); // invoking onDestroy when Object destructor invoked
    }

#pragma endregion

#pragma region Operations

    void GraphicService::setVideoMode() {
        // creating video mode and assigns the address to videoMode ptr
        videoMode = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel);
    }

    void GraphicService::createGameWindow() {
        setVideoMode();

        // create a RenderWindow Object and assigns the address to gameWindow ptr
        gameWindow = new sf::RenderWindow(*videoMode, windowTitle, sf::Style::Close);

        // setting up frame limit for the window
        gameWindow->setFramerateLimit(frameLimit);
    }

    void GraphicService::onDestroy() {
        delete videoMode; // freeing memory assigned to videoMode ptr
        delete gameWindow; // freeing memory assigned to gameWindow ptr
    }

    void GraphicService::draw(sf::Drawable& drawable) {
        gameWindow->draw(drawable);
    }

#pragma endregion

#pragma region Getter Functions

    sf::RenderWindow* GraphicService::getGameWindow() {
        return gameWindow;
    }

    void GraphicService::closeGameWindow() {
        gameWindow->close();
    }

    bool GraphicService::isGameWindowOpen() {
        return gameWindow->isOpen(); // return true if the game window is still open
    }

#pragma endregion
}


