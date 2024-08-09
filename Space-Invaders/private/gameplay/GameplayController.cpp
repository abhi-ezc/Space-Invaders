#include "./../../public/gameplay/GameplayController.h"
#include "./../../public/gameplay/GameplayView.h"

namespace Gameplay
{
    GameplayController::GameplayController()
    {
        m_gameplay_view = new GameplayView();
    }

    GameplayController::~GameplayController()
    {
        delete m_gameplay_view;
    }

    void GameplayController::initialize()
    {
        m_gameplay_view->initialize();
    }

    void GameplayController::update()
    {
        m_gameplay_view->update();
    }

    void GameplayController::render()
    {
        m_gameplay_view->render();
    }
}
