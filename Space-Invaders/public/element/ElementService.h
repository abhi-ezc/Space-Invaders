#pragma once
#include <vector>

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
        public:
            ElementService();
            ~ElementService();

            void initialize();
            void update();
            void render();
    };
}
