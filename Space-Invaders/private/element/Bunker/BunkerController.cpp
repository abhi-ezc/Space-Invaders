#include "./../../../public/element/Bunker/BunkerController.h"
#include "./../../../public/element/Bunker/BunkerModel.h"
#include "./../../../public/element/Bunker/BunkerView.h"

namespace Element
{
    namespace Bunker
    {
        BunkerController::BunkerController(sf::Vector2f position)
        {
            m_bunker_data = new BunkerData(position);
            m_bunker_view = new BunkerView();
        }

        BunkerController::~BunkerController() {}

        void BunkerController::initialize()
        {
            m_bunker_view->initialize(this);
        }

        void BunkerController::update()
        {
            m_bunker_view->update();
        }

        void BunkerController::render()
        {
            m_bunker_view->render();
        }

        sf::Vector2f BunkerController::getPosition()
        {
            return m_bunker_data->m_position;
        }
    }
}
