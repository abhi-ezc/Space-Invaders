#include "../../../public/enemy/controllers/ThunderSnakeController.h"
#include "../../../public/enemy/EnemyModel.h"
#include "../../../public/global/ServiceLocator.h"
#include "../../../public/time/TimeService.h"
#include "./../../public/enemy/EnemyConfig.h"

namespace Enemy
{
    namespace Controllers
    {
        using namespace Global;

        ThunderSnakeController::ThunderSnakeController(): EnemyController(EnemyType::THUNDER_SNAKE) { }

        ThunderSnakeController::~ThunderSnakeController() { }

        void ThunderSnakeController::initialize()
        {
            EnemyController::initialize();
            m_enemy_model->setMovementDirection(getRandomSideDirection());
        }

        void ThunderSnakeController::move()
        {
            switch (m_enemy_model->getMovementDirection())
            {
                case MovementDirection::LEFT:
                    moveLeft();
                    break;
                case MovementDirection::RIGHT:
                    moveRight();
                    break;
                default:
                    break;
            }
        }

        void ThunderSnakeController::moveLeft()
        {
            sf::Vector2f position = getPosition();

            position.x -= m_enemy_model->getMovementSpeed() * ServiceLocator::getInstance()
                                                              ->getTimeService()
                                                              ->getDeltaTime();
            if (position.x < m_enemy_model->getLeftMostPosition().x)
            {
                m_enemy_model->setMovementDirection(MovementDirection::RIGHT);
            }
            else
            {
                position.y += m_vertical_travel_speed * ServiceLocator::getInstance()
                                                        ->getTimeService()
                                                        ->getDeltaTime();
                m_enemy_model->setCurrentPosition(position);
            }
        }

        void ThunderSnakeController::moveRight()
        {
            sf::Vector2f position = getPosition();

            position.x += m_enemy_model->getMovementSpeed() * ServiceLocator::getInstance()
                                                              ->getTimeService()
                                                              ->getDeltaTime();
            if (position.x > m_enemy_model->getRightMostPosition().x)
            {
                m_enemy_model->setMovementDirection(MovementDirection::LEFT);
            }
            else
            {
                position.y += m_vertical_travel_speed * ServiceLocator::getInstance()
                                                        ->getTimeService()
                                                        ->getDeltaTime();
                m_enemy_model->setCurrentPosition(position);
            }
        }

        MovementDirection ThunderSnakeController::getRandomSideDirection()
        {
            return static_cast<MovementDirection>(rand() % 2);
        }
    }
}
