#pragma once
class PlayerController;

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
