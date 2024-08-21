#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
    enum class SoundType
    {
        BUTTON_CLICK
    };

    class SoundService
    {
        private:
            const float m_background_volume = 100.f;
            sf::Music m_background_music;
            sf::Sound m_sfx;
            sf::SoundBuffer m_sound_buffer;

            void loadBackgroundMusic();
            void loadOtherSFX();

        public:
            void playSound(SoundType type);
            void playBackgroundMusic();
            void initialize();
    };
}
