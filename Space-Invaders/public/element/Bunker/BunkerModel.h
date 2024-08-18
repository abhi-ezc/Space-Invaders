#pragma once
namespace Element
{
    namespace Bunker
    {
        class BunkerModel
        {
            private:
            public:
                BunkerModel();
                ~BunkerModel();

                void initialize();
                void update();
                void render();
        };
    }
}
