#pragma once
#include <SFML/Graphics.hpp>

namespace Element
{
    namespace Bunker
    {
        class BunkerController;

        class BunkerView
        {
            private:
                sf::Texture m_bunker_texture;
                sf::Sprite m_bunker_sprite;
                float m_sprite_height = 80.f;
                float m_sprite_width = 80.f;


                void initializeSprite();
                void adjustSpritePosition(sf::Vector2f position);

            public:
                BunkerView();
                ~BunkerView();

                void initialize(BunkerController*);
                void update();
                void render();
        };
    }
}
