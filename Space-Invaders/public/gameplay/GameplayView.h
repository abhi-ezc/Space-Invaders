#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>

namespace Gameplay
{
    class GameplayView
    {
        private:
            sf::Texture m_background_texture;
            sf::Sprite m_background_sprite;


        public:
            GameplayView();
            ~GameplayView();

            void initialize();
            void update();
            void render();

            void initializeBackgroundImage();
    };
}
