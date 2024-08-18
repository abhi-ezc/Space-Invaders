#include "./../../public/element/ElementService.h"
#include "./../../public/element/Bunker/BunkerController.h"

namespace Element
{
    using namespace Bunker;

    ElementService::ElementService() { }

    ElementService::~ElementService() { }

    void ElementService::initialize()
    {
        auto position = sf::Vector2f(100, 500);
        auto bunkerController = new BunkerController(position);
        bunkerController->initialize();
        m_bunkers_list.push_back(bunkerController);
    }

    void ElementService::update()
    {
        for (auto bunker : m_bunkers_list)
        {
            bunker->update();
        }
    }

    void ElementService::render()
    {
        for (auto bunker : m_bunkers_list)
        {
            bunker->render();
        }
    }
}
