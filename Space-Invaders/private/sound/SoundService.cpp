#include "./../../public/sound/SoundService.h"
#include "./../../public/global/Config.h"

namespace Sound
{
    using namespace Global;

    void SoundService::initialize()
    {
        loadBackgroundMusic();
        loadOtherSFX();
    }

    void SoundService::loadBackgroundMusic()
    {
        if (!m_background_music.openFromFile(Config::background_music_path))
        {
            printf("Error loading background music");
        }
        else
        {
            playBackgroundMusic();
        }
    }

    void SoundService::playBackgroundMusic()
    {
        if (m_background_music.getStatus() != sf::SoundSource::Playing)
        {
            m_background_music.setLoop(true);
            m_background_music.setVolume(m_background_volume);
            m_background_music.play();
        }
    }

    void SoundService::loadOtherSFX()
    {
        if (!m_buffer_button_click.loadFromFile(Config::button_click_sound_path))
        {
            printf("Error loading button click sound");
        }
    }

    void SoundService::playSound(SoundType type)
    {
        switch (type)
        {
            case SoundType::BUTTON_CLICK:
                m_sfx.setBuffer(m_buffer_button_click);
                break;
            default:
                printf("Invalid sound type");
                return;
        }
        m_sfx.play();
    }
}
