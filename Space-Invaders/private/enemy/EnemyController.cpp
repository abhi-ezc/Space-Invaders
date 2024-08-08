#include "./../../public/enemy/EnemyController.h"

#include "../../public/time/TimeService.h"
#include "./../../public/enemy/EnemyModel.h"
#include "./../../public/enemy/EnemyView.h"
#include "./../../public/global/ServiceLocator.h"

namespace Enemy
{
    using namespace Global;

    EnemyController::EnemyController()
    {
        m_enemy_model = new EnemyModel();
        m_enemy_view = new EnemyView();
    }

    EnemyController::~EnemyController()
    {
        delete m_enemy_model;
        delete m_enemy_view;
    };

    void EnemyController::initialize()
    {
        m_enemy_model->initialize();
        m_enemy_view->initialize(this);
    }

    void EnemyController::update()
    {
        move();
        m_enemy_model->update();
        m_enemy_view->update();
    }

    void EnemyController::render()
    {
        m_enemy_model->render();
        m_enemy_view->render();
    }

    void EnemyController::move()
    {
        switch (m_enemy_model->getMovementDirection())
        {
            case MovementDirection::LEFT:
                moveLeft();
                break;

            case MovementDirection::RIGHT:
                moveRight();
                break;
            case MovementDirection::DOWN:
                moveDown();
        }
    }

    void EnemyController::moveLeft()
    {
        float x = static_cast<float>(m_enemy_model->getMovementSpeed()) *
            ServiceLocator::getInstance()->getTimeService()->getDeltaTime() *
            -1;

        const sf::Vector2f newPosition = m_enemy_model->getCurrentPosition() + sf::Vector2f(x, 0);
        if (newPosition.x >= m_enemy_model->getLeftMostPosition().x) { m_enemy_model->setCurrentPosition(newPosition); }
        else
        {
            m_enemy_model->setReferencePosition(m_enemy_model->getCurrentPosition());
            m_enemy_model->setPreviousDirection(MovementDirection::LEFT);
            m_enemy_model->setMovementDirection(MovementDirection::DOWN);
        }
    }

    void EnemyController::moveRight()
    {
        float x = static_cast<float>(m_enemy_model->getMovementSpeed()) *
            ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

        const sf::Vector2f newPosition = m_enemy_model->getCurrentPosition() + sf::Vector2f(x, 0);
        if (newPosition.x <= m_enemy_model->getRightMostPosition().x)
        {
            m_enemy_model->setCurrentPosition(newPosition);
        }
        else
        {
            m_enemy_model->setReferencePosition(m_enemy_model->getCurrentPosition());
            m_enemy_model->setPreviousDirection(MovementDirection::RIGHT);
            m_enemy_model->setMovementDirection(MovementDirection::DOWN);
        }
    }


    void EnemyController::moveDown()
    {
        const float offset = static_cast<float>(m_enemy_model->getMovementSpeed()) *
            ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

        const sf::Vector2f newPosition = m_enemy_model->getCurrentPosition() + sf::Vector2f(0, offset);
        const float expectedYPosition = m_enemy_model->getDownMostPositionY();

        if (newPosition.y >= expectedYPosition)
        {
            if (m_enemy_model->getPreviousDirection() == MovementDirection::RIGHT)
            {
                m_enemy_model->setMovementDirection(MovementDirection::LEFT);
            }
            else { m_enemy_model->setMovementDirection(MovementDirection::RIGHT); }
        }
        else { m_enemy_model->setCurrentPosition(newPosition); }
    }

    sf::Vector2f EnemyController::getPosition() { return m_enemy_model->getCurrentPosition(); }
}
