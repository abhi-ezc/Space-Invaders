#pragma once
namespace Element
{
    namespace Bunker
    {
        class BunkerController
        {
            private:
            public:
                BunkerController();
                ~BunkerController();

                void initialize();
                void update();
                void render();
        };
    }
}
