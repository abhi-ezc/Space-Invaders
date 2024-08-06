#include "../../public/main/GameService.h"
#include "../../public/global/ServiceLocator.h"
#include "../../public/graphic/GraphicService.h"

namespace Main
{
    using namespace Global;

    GameState GameService::m_game_state = GameState::BOOT;

    #pragma region Life Cycle Functions

    // constructors initializing pointers
    GameService::GameService()
    {
        m_service_locator = nullptr;
        m_game_window = nullptr;
    }

    // destructors calls the destroy function for cleaning up the resources
    GameService::~GameService() { destroy(); }

    void GameService::initialize()
    {
        m_service_locator->initialize();
        initializeVariables();
        setGameState(GameState::MAIN_MENU); // show mainmenu
    }

    void GameService::initializeVariables() { m_game_window = m_service_locator->getGraphicService()->getGameWindow(); }

    void GameService::ignite()
    {
        m_service_locator = ServiceLocator::getInstance();
        initialize();
    }

    void GameService::update() { m_service_locator->update(); }

    void GameService::render() { m_service_locator->render(); }

    #pragma endregion


    #pragma region Operations
    void GameService::destroy() { }
    void GameService::setGameState(GameState state) { m_game_state = state; }
    #pragma endregion


    #pragma region Getters
    bool GameService::isRunning()
    {
        if (m_game_window != nullptr) { return m_game_window->isOpen(); }
        return false;
    }

    GameState GameService::getGameState() { return m_game_state; }
    #pragma endregion

    #pragma region TestCodes

    #pragma endregion
}
