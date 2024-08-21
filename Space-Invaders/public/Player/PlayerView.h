#pragma once
#include "SFML/System/String.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Player
{
    class PlayerController;

    class PlayerView
    {
        private:
            sf::Texture m_texture;
            sf::Sprite m_sprite;

            const int m_sprite_height = 60;
            const int m_sprite_width = 60;

            sf::RenderWindow* m_game_window;
            PlayerController* m_player_controller;

            void setPlayerScale();

        public:
            // Constructors and Destructors
            PlayerView();
            ~PlayerView();

            // Lifecycle methods
            void initialize(PlayerController* controller);
            void update();
            void render();

            // Operations
            void createPlayerSprite();

            // Getters
            sf::Sprite getPlayerSprite();

            // Setters
    };
}
