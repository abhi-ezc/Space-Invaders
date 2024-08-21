#include "./../../../public/element/Bunker/BunkerView.h"
#include "../../../public/graphic/GraphicService.h"
#include "./../../../public/global/ServiceLocator.h"
#include "./../../../public/global/Config.h"
#include "./../../../public/element/Bunker/BunkerController.h"

namespace Element
{
    namespace Bunker
    {
        using namespace Global;

        BunkerView::BunkerView() { }

        BunkerView::~BunkerView() {}

        void BunkerView::initialize(BunkerController* controller)
        {
            initializeSprite();
            adjustSpritePosition(controller->getPosition());
        }

        void BunkerView::update() {}

        void BunkerView::render()
        {
            ServiceLocator::getInstance()->getGraphicService()->draw(m_bunker_sprite);
        }

        void BunkerView::initializeSprite()
        {
            if (m_bunker_texture.loadFromFile(Config::bunker_texture_path))
            {
                m_bunker_sprite.setTexture(m_bunker_texture);
                sf::Vector2u textureSize = m_bunker_sprite.getTexture()->getSize();
                m_bunker_sprite.setScale(m_sprite_width / textureSize.x, m_sprite_height / textureSize.y);
            }
        }

        void BunkerView::adjustSpritePosition(sf::Vector2f position)
        {
            m_bunker_sprite.setPosition(position);
        }
    }
}
