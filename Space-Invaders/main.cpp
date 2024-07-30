#include<iostream>
#include "./public/main/GameService.h"

int main() {
	GameService* gameService = new GameService();
	gameService->ignite();
	while( gameService->isRunning() )
	{
		gameService->update();
		gameService->render();
	}
	delete gameService; // freeing up the GameService ptr
}