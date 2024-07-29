#pragma once
#include "./player/PlayerController.h"

class PlayerService
{
    private:

    PlayerController* playerController;

    public:
        PlayerService();
        ~PlayerService();
     
        void initialize();
        void update();
        void render();
};
