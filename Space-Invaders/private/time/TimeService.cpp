#include "../../public/time/TimeService.h"

namespace Time
{
    void TimeService::initialize() {
        previousTime = std::chrono::steady_clock::now();
        deltaTime = 0;
    }

    void TimeService::update() {
        updateDeltaTime();
    }

    float TimeService::getDeltaTime() {
        return deltaTime;
    }

    void TimeService::updateDeltaTime() {
        deltaTime = calculateDeltaTime();
        updatePreviousTime();

        std::cout << "\nclock elapsed : " << clock.getElapsedTime().asSeconds() << std::endl;
        clock.restart();
        std::cout << "\nchrono elapsed : " << deltaTime;
        std::cout << "\n----------------------------\n";
    }

    float TimeService::calculateDeltaTime() {
        // Calculate time difference in microseconds between the current and previous frame.
        int delta = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now() - previousTime ).count();

        // The cast is used to convert delta time from microseconds into seconds.
        // We will learn aboit how this works in detail later.
        return static_cast<float>( delta ) / static_cast<float>( 1000000 );
    }

    // Update previous_time to the current time
    void TimeService::updatePreviousTime() {
        previousTime = std::chrono::steady_clock::now();
    }

}
