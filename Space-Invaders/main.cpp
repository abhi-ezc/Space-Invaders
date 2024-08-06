#include<iostream>
#include "./public/main/GameService.h"

using namespace Main;

int main()
{
    auto gameService = new GameService();
    gameService->ignite();
    while (gameService->isRunning())
    {
        gameService->update();
        gameService->render();
    }
    delete gameService; // freeing up the GameService ptr
}
