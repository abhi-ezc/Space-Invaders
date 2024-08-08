#pragma once
#include "./../../public/graphic/GraphicService.h"

namespace Graphic
{
    #pragma region Life Cycle Functions

    GraphicService::GraphicService()
    {
        m_video_mode = nullptr; // initialize videoMode ptr with nullptr
        m_game_window = nullptr; // initialize gameWindow ptr with nullptr
    }

    void GraphicService::initialize()
    {
        createGameWindow();
    }

    void GraphicService::update()
    {
        m_game_window->clear(m_window_color);
    }

    void GraphicService::render()
    {
        m_game_window->display();
    }

    // Destructor and OnDestroy
    GraphicService::~GraphicService()
    {
        onDestroy(); // invoking onDestroy when Object destructor invoked
    }

    #pragma endregion

    #pragma region Operations

    void GraphicService::setVideoMode()
    {
        // creating video mode and assigns the address to videoMode ptr
        m_video_mode = new sf::VideoMode(m_game_window_width, m_game_window_height,
            sf::VideoMode::getDesktopMode().bitsPerPixel);
    }

    void GraphicService::createGameWindow()
    {
        setVideoMode();

        // create a RenderWindow Object and assigns the address to gameWindow ptr
        m_game_window = new sf::RenderWindow(*m_video_mode, m_window_title, sf::Style::Fullscreen);

        // setting up frame limit for the window
        m_game_window->setFramerateLimit(m_frame_limit);
    }

    void GraphicService::onDestroy()
    {
        delete m_video_mode; // freeing memory assigned to videoMode ptr
        delete m_game_window; // freeing memory assigned to gameWindow ptr
    }

    void GraphicService::draw(sf::Drawable& drawable)
    {
        m_game_window->draw(drawable);
    }

    #pragma endregion

    #pragma region Getter Functions

    sf::RenderWindow* GraphicService::getGameWindow()
    {
        return m_game_window;
    }

    void GraphicService::closeGameWindow()
    {
        m_game_window->close();
    }

    bool GraphicService::isGameWindowOpen()
    {
        return m_game_window->isOpen(); // return true if the game window is still open
    }

    #pragma endregion
}
