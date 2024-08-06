#include "./../../public/enemy/EnemyController.h"
#include "./../../public/enemy/EnemyModel.h"
#include "./../../public/enemy/EnemyView.h"

namespace Enemy
{
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
        m_enemy_model->update();
        m_enemy_view->update();
    }

    void EnemyController::render()
    {
        m_enemy_model->render();
        m_enemy_view->render();
    }

    sf::Vector2f EnemyController::getPosition() { return m_enemy_model->getPlayerPosition(); }
}
