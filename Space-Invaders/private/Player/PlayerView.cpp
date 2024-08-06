#include "./../../public/player/PlayerView.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/player/PlayerController.h"
#include "./../../public/graphic/GraphicService.h"

namespace Player
{
    using namespace Global;

    PlayerView::PlayerView()
    {
        m_game_window = nullptr;
        m_player_controller = nullptr;
    }

    PlayerView::~PlayerView() = default;

    void PlayerView::initialize(PlayerController* controller)
    {
        m_player_controller = controller;
        m_game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
        createPlayerSprite();
    }

    void PlayerView::update()
    {
        // setting the updated sprite position from playercontroller
        m_sprite.setPosition(m_player_controller->getPlayerPosition());
    }

    void PlayerView::render() { ServiceLocator::getInstance()->getGraphicService()->draw(m_sprite); }

    void PlayerView::setPlayerScale()
    {
        float x = static_cast<float>(m_sprite_width / m_sprite.getTexture()->getSize().x);
        float y = static_cast<float>(m_sprite_height / m_sprite.getTexture()->getSize().y);

        //sprite.setScale(x, y);
    }

    void PlayerView::createPlayerSprite()
    {
        if (m_texture.loadFromFile(m_texture_path))
        {
            m_sprite.setTexture(m_texture);
            setPlayerScale();
            m_sprite.setPosition(m_player_controller->getPlayerPosition());
        }
    }

    sf::Sprite PlayerView::getPlayerSprite() { return m_sprite; }
}
