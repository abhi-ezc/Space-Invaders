#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"

namespace Element
{
    namespace Bunker
    {
        class BunkerController;
    }

    class ElementService
    {
        private:
            std::vector<Bunker::BunkerController*> m_bunkers_list;
            const std::vector<sf::Vector2f> m_bunker_positions = {
                sf::Vector2f(130.f, 800.f),
                sf::Vector2f(430.0f, 800.f),
                sf::Vector2f(730.0f, 800.f),
                sf::Vector2f(1130.0f, 800.f),
                sf::Vector2f(1430.0f, 800.f),
                sf::Vector2f(1730.0f, 800.f)
            };
        public:
            ElementService();
            ~ElementService();

            void initialize();
            void update();
            void render();

            void destroyAllBunkers();
    };
}
