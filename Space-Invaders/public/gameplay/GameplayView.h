#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>

namespace Gameplay
{
    class GameplayView
    {
        private:
            const sf::String m_background_texture_path = "assets/textures/space_invaders_bg.png";
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
