#include "./../../public/element/ElementService.h"
#include "./../../public/element/Bunker/BunkerController.h"

namespace Element
{
    using namespace Bunker;

    ElementService::ElementService() { }

    ElementService::~ElementService() { }

    void ElementService::initialize()
    {
        for (const sf::Vector2f position : m_bunker_positions)
        {
            auto bunkerController = new BunkerController(position);
            bunkerController->initialize();
            m_bunkers_list.push_back(bunkerController);
        }
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

    void ElementService::destroyAllBunkers()
    {
        for (auto bunker : m_bunkers_list)
        {
            delete bunker;
        }
        m_bunkers_list.clear();
    }
}
