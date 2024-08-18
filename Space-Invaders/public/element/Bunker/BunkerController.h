#pragma once
#include "SFML/Graphics.hpp"

namespace Element
{
    namespace Bunker
    {
        struct BunkerData;
        class BunkerView;

        class BunkerController
        {
            private:
                BunkerData* m_bunker_data;
                BunkerView* m_bunker_view;
            public:
                BunkerController(sf::Vector2f position);
                ~BunkerController();

                void initialize();
                void update();
                void render();
                sf::Vector2f getPosition();
        };
    }
}
