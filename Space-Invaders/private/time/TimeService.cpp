#include "../../public/time/TimeService.h"

namespace Time
{
    void TimeService::initialize()
    {
        m_previous_time = std::chrono::steady_clock::now();
        m_delta_time = 0;
    }

    void TimeService::update() { updateDeltaTime(); }

    float TimeService::getDeltaTime() { return m_delta_time; }

    void TimeService::updateDeltaTime()
    {
        m_delta_time = calculateDeltaTime();
        updatePreviousTime();
        m_clock.restart();
    }

    float TimeService::calculateDeltaTime()
    {
        // Calculate time difference in microseconds between the current and previous frame.
        const long long int delta = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::steady_clock::now() - m_previous_time).count();

        // The cast is used to convert delta time from microseconds into seconds.
        // We will learn about how this works in detail later.
        return static_cast<float>(delta) / static_cast<float>(1000000);
    }

    // Update previous_time to the current time
    void TimeService::updatePreviousTime() { m_previous_time = std::chrono::steady_clock::now(); }
}
