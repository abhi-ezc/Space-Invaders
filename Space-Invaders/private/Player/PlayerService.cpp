#pragma once
#include "./../../public/player/PlayerController.h"
#include "./../../public/player/PlayerService.h"
#include "./../../public/main/GameService.h"

namespace Player
{
    #pragma region Life Cycle Functions

    PlayerService::PlayerService() { m_player_controller = new PlayerController(); }

    PlayerService::~PlayerService() { delete m_player_controller; };

    void PlayerService::initialize() { m_player_controller->initialize(); }


    void PlayerService::update()
    {
        if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY) { m_player_controller->update(); }
    }

    void PlayerService::render()
    {
        if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY) { m_player_controller->render(); }
    }

    #pragma endregion
}
