#include "./../../public/gameplay/GameplayService.h"
#include "./../../public/gameplay/GameplayController.h"

namespace Gameplay
{
    GameplayService::GameplayService()
    {
        m_gameplay_controller = new GameplayController();
    }

    GameplayService::~GameplayService()
    {
        delete m_gameplay_controller;
    }

    void GameplayService::initialize()
    {
        m_gameplay_controller->initialize();
    }

    void GameplayService::update()
    {
        m_gameplay_controller->update();
    }

    void GameplayService::render()
    {
        m_gameplay_controller->render();
    }
}
