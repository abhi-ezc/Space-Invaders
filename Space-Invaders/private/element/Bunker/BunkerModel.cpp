#include "./../../../public/element/Bunker/BunkerModel.h"

namespace Element
{
    namespace Bunker
    {
        BunkerData::BunkerData() { }

        BunkerData::BunkerData(sf::Vector2f position)
        {
            m_position = position;
        }
    }
}
