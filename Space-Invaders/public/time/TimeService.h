#pragma once
#include <chrono>
#include "SFML/System/Clock.hpp"
#include <iostream>

namespace Time
{
    class TimeService
    {
        private:
            // A point in time which indicates the starting time of previous frame.
            std::chrono::time_point<std::chrono::steady_clock> m_previous_time;

            float m_delta_time = 0.f; //to store the delta time
            sf::Clock m_clock;

            void updateDeltaTime(); // method to update time
            float calculateDeltaTime(); // calculate time by subtracting the previous time from the current time
            void updatePreviousTime(); // finally update the current time to be previous time
        public:
            // lifecycle methods
            void initialize();
            void update();

            // getter
            float getDeltaTime();
    };
}
