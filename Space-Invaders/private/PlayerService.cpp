#pragma once
#include "./../public/PlayerService.h"

#pragma region Life Cycle Functions

PlayerService::PlayerService()
{
    playerController = new PlayerController();
}

PlayerService::~PlayerService() { 
    delete playerController;
};

void PlayerService::initialize()
{
    playerController->initialize();
}


void PlayerService::update()
{
    playerController->update();
}

void PlayerService::render() {  
    playerController->render();
}

#pragma endregion
