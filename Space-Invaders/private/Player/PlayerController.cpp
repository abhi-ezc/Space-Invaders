#include "./../../public/player/PlayerController.h"
#include "./../../public/global/ServiceLocator.h"
#include "./../../public/time/TimeService.h"
#include "./../../public/player/PlayerView.h"
#include "./../../public/player/PlayerModel.h"
#include "./../../public/event/EventService.h"
#include "./../../public/bullet/BulletService.h"
#include "./../../public/bullet/BulletConfig.h"
#include "./../../public/projectile/ProjectileConfig.h"
#include "./../../public/entity/EntityConfig.h"
#include "./../../public/collision/CollisionService.h"

namespace Player
{
    using namespace Global;
    using namespace Event;

    #pragma region Life Cycle methods
    PlayerController::PlayerController()
    {
        m_player_model = new PlayerModel();
        m_player_view = new PlayerView();
    }

    PlayerController::~PlayerController()
    {
        delete m_player_model;
        delete m_player_view;
        ServiceLocator::getInstance()->getCollisionService()->removeCollider(this);
    }

    void PlayerController::initialize()
    {
        m_player_model->initialize();
        m_player_view->initialize(this);
        ServiceLocator::getInstance()->getCollisionService()->addCollider(this);
    }

    void PlayerController::update()
    {
        processPlayerInputs();
        m_player_model->update();
        m_player_view->update();
    }

    void PlayerController::render()
    {
        m_player_model->render();
        m_player_view->render();
    }

    #pragma endregion

    #pragma region Operations
    void PlayerController::processPlayerInputs()
    {
        EventService* eventService = ServiceLocator::getInstance()->getEventService();

        if (eventService->isLeftKeyPressed() || eventService->isAKeyPressed())
        {
            moveLeft();
        }
        else if (eventService->isRightKeyPressed() || eventService->isDKeyPressed())
        {
            moveRight();
        }
        else if (eventService->isLeftMouseButtonPressed())
        {
            fireBullet();
        }
        else { }
    }

    void PlayerController::moveLeft()
    {
        sf::Vector2f currentPosition = m_player_model->getPlayerPosition();
        currentPosition.x -= m_player_model->m_movement_speed * ServiceLocator::getInstance()->getTimeService()->
                                                                                               getDeltaTime();
        currentPosition.x = std::max(currentPosition.x, m_player_model->m_left_most_position);
        m_player_model->setPlayerPosition(currentPosition);
    }

    void PlayerController::moveRight()
    {
        sf::Vector2f currentPosition = m_player_model->getPlayerPosition();
        currentPosition.x += m_player_model->m_movement_speed * ServiceLocator::getInstance()->getTimeService()->
                                                                                               getDeltaTime();

        currentPosition.x = std::min(currentPosition.x, m_player_model->m_right_most_position);
        m_player_model->setPlayerPosition(currentPosition);
    }

    void PlayerController::fireBullet(bool bIsTrippleLaser)
    {
        auto bulletPos = getPlayerPosition();
        auto playerSpriteBounds = m_player_view->getLocalBounds();

        auto muzzleOffset = m_player_model->getMuzzleOffset();

        bulletPos.x += muzzleOffset.x;
        bulletPos.y += muzzleOffset.y;

        ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::LASER, bulletPos,
            Projectile::ProjectileDirection::UP, Entity::EntityType::PLAYER);
    }

    void PlayerController::onCollision(ICollider* otherCollider)
    {
        printf("\n PlayerDestroyed\n");
        //ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
    }

    #pragma endregion

    #pragma region Getters
    sf::Vector2f PlayerController::getPlayerPosition()
    {
        return m_player_model->getPlayerPosition();
    }

    Entity::EntityType PlayerController::getEntityType()
    {
        return m_player_model->getEntityType();
    }

    sf::Sprite& PlayerController::getColliderSprite()
    {
        return m_player_view->getSprite();
    }

    PlayerState PlayerController::getPlayerState()
    {
        return m_player_model->getPlayerState();
    }
    #pragma endregion
}
