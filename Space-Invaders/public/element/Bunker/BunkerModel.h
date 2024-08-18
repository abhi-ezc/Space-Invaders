#pragma once
#include <SFML/System/Vector2.hpp>

namespace Element
{
    namespace Bunker
    {
        struct BunkerData
        {
            sf::Vector2f m_position;
            BunkerData(sf::Vector2f position);
            BunkerData();
        };
    }
}
