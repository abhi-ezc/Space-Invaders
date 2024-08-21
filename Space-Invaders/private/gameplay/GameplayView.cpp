#include "./../../public/gameplay/GameplayView.h"
#include "../../public/graphic/GraphicService.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/global/Config.h"


namespace Gameplay
{
    using namespace Global;

    GameplayView::GameplayView() = default;

    GameplayView::~GameplayView() = default;

    void GameplayView::initialize()
    {
        initializeBackgroundImage();
    }

    void GameplayView::update() { }

    void GameplayView::render()
    {
        Global::ServiceLocator::getInstance()->getGraphicService()->draw(m_background_sprite);
    }

    void GameplayView::initializeBackgroundImage()
    {
        if (m_background_texture.loadFromFile(Config::background_texture_path))
        {
            m_background_sprite.setTexture(m_background_texture);
            const sf::RenderWindow* gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->
                                                                                        getGameWindow();
            const sf::Vector2f windowSize = gameWindow->getView().getSize();
            const sf::Vector2u spriteSize = m_background_sprite.getTexture()->getSize();

            m_background_sprite.setScale(windowSize.x / static_cast<float>(spriteSize.x),
                windowSize.y / static_cast<float>(spriteSize.y));
        }
    }
}
