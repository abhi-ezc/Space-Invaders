#pragma once

namespace Player
{
    class PlayerController;

    class PlayerService
    {
        private:
            PlayerController* m_player_controller;

        public:
            PlayerService();
            ~PlayerService();

            void initialize();
            void update();
            void render();

            void enableShield();
            void enableRapidFire();
            void enableTrippleLaser();

            void reset();
    };
}
