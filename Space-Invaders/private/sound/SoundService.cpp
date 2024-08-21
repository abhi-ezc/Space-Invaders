#include "./../../public/sound/SoundService.h"
#include "./../../public/global/Config.h"

namespace Sound
{
    using namespace Global;

    void SoundService::initialize()
    {
        m_background_music.openFromFile(Config::background_music_path);
    }

    void SoundService::loadBackgroundMusic() { }

    void SoundService::playBackgroundMusic()
    {
        if (m_background_music.getStatus() != sf::SoundSource::Playing)
        {
            m_background_music.play();
        }
    }

    void SoundService::loadOtherSFX() { }

    void SoundService::playSound(SoundType type) { }
}
