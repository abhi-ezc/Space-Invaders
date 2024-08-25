#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>

namespace Bullet
{
    class BulletController;

    class BulletView
    {
        private:
            sf::String m_bullet_texture_path;
            sf::Texture m_bullet_texture;
            sf::Sprite m_bullet_sprite;
            BulletController* m_bullet_controller;

            void loadTexture();
            void initializeSprite();

        public:
            BulletView(BulletController* controller);
            ~BulletView();

            void initialize();
            void update();
            void render();
    };
}
