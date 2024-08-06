#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Drawable.hpp"

namespace Graphic
{
    class GraphicService
    {
        private:
            sf::String m_window_title = "Space Invaders"; // window title
            const int m_game_window_width = 1920; // Game Window Width
            const int m_game_window_height = 1080; // Game Window Height
            const sf::Color m_window_color = sf::Color::Black; // Color to clear GameWindow with
            const int m_frame_limit = 60;

            sf::VideoMode* m_video_mode; // video mode pointer
            sf::RenderWindow* m_game_window; // game window pointer

            void setVideoMode(); // method for setting our video mode
            void createGameWindow(); // method for creating new GameWindow
            void onDestroy(); // invoke while window is getting destroyed

        public:
            GraphicService(); // GraphicService Constructor
            ~GraphicService(); // Destructor

            void initialize(); // init Graphic Service: creating game window
            void update(); // update: trigger each frame clearing game window
            void render(); // render: render the latest drawn images to the frame
            bool isGameWindowOpen(); // return true if the game window is open
            sf::RenderWindow* getGameWindow(); // return game window
            void closeGameWindow();
            void draw(sf::Drawable& drawable);
    };
}
