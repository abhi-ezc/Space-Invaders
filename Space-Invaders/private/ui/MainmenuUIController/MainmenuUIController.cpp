#include "../../../public/sound/SoundService.h"
#include "./../../../public/ui/MainMenuUIController/MainMenuUIController.h"
#include "./../../../public/global/ServiceLocator.h"
#include "./../../../public/graphic/GraphicService.h"
#include "./../../../public/event/EventService.h"
#include "./../../../public/main/GameService.h"
#include "./../../public/global/Config.h"


namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Graphic;
        using namespace Event;
        using namespace Main;

        MainMenuUIController::MainMenuUIController()
        {
            m_game_window = nullptr;
        }

        MainMenuUIController::~MainMenuUIController() = default;

        void MainMenuUIController::initialize()
        {
            m_game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeBackgroundImage();
            initializeButtons();
        }

        void MainMenuUIController::initializeBackgroundImage()
        {
            m_tex_background_image.loadFromFile(Config::background_texture_path);
            m_spr_background_image.setTexture(m_tex_background_image);

            float sizeX = m_game_window->getView().getSize().x / static_cast<float>(m_spr_background_image.getTexture()
                                                                                                          ->getSize()
                                                                                                          .x);

            float sizeY = m_game_window->getView().getSize().y / static_cast<float>(m_spr_background_image.getTexture()
                                                                                                          ->getSize().
                                                                                                          y);

            m_spr_background_image.setScale(sizeX, sizeY);
        }

        void MainMenuUIController::initializeButtons()
        {
            if (loadButtonTextures())
            {
                createButtonSprites();
                scaleAllButtons();
                setAllButtonsPosition();
            }
        }

        bool MainMenuUIController::loadButtonTextures()
        {
            return m_tex_play_button.loadFromFile(Config::play_button_texture_path) && m_tex_instruction_button.
                loadFromFile(Config::instructions_button_texture_path) && m_tex_quit_button.loadFromFile(
                    Config::quit_button_texture_path);
        }

        void MainMenuUIController::createButtonSprites()
        {
            m_spr_play_button.setTexture(m_tex_play_button);
            m_spr_instruction_button.setTexture(m_tex_instruction_button);
            m_spr_quit_button.setTexture(m_tex_quit_button);
        }

        void MainMenuUIController::scaleAllButtons()
        {
            scaleButton(&m_spr_play_button);
            scaleButton(&m_spr_instruction_button);
            scaleButton(&m_spr_quit_button);
        }

        void MainMenuUIController::scaleButton(sf::Sprite* spr_button)
        {
            float x = m_f_button_width / static_cast<float>(spr_button->getTexture()->getSize().x);
            float y = m_f_button_height / static_cast<float>(spr_button->getTexture()->getSize().y);
            spr_button->setScale(x, y);
        }

        void MainMenuUIController::setAllButtonsPosition()
        {
            setButtonPosition(&m_spr_play_button, 250.f);
            setButtonPosition(&m_spr_instruction_button, 500);
            setButtonPosition(&m_spr_quit_button, 750.f);
        }

        void MainMenuUIController::setButtonPosition(sf::Sprite* spr_button, float yOffset)
        {
            // calculate button sizes from the original size and the sprite scale
            float buttonSizeX = static_cast<float>(spr_button->getTexture()->getSize().x) * spr_button->getScale().x;
            float buttonSizeY = static_cast<float>(spr_button->getTexture()->getSize().y) * spr_button->getScale().y;

            // calculate positions based on the screen center and given yOffset
            float x = m_game_window->getView().getCenter().x - (buttonSizeX / 2);
            float y = yOffset - (buttonSizeY / 2);

            // apply calculated positions
            spr_button->setPosition(x, y);
        }

        void MainMenuUIController::update()
        {
            processButtonInteractions();
        }

        void MainMenuUIController::render()
        {
            ServiceLocator::getInstance()->getGraphicService()->draw(m_spr_background_image);
            ServiceLocator::getInstance()->getGraphicService()->draw(m_spr_play_button);
            ServiceLocator::getInstance()->getGraphicService()->draw(m_spr_instruction_button);
            ServiceLocator::getInstance()->getGraphicService()->draw(m_spr_quit_button);
        }

        void MainMenuUIController::processButtonInteractions()
        {
            if (ServiceLocator::getInstance()->getEventService()->isLeftMouseButtonPressed())
            {
                if (isButtonClick(&m_spr_play_button, sf::Mouse::getPosition()))
                {
                    ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
                    onPlayButtonClick();
                }
                else if (isButtonClick(&m_spr_instruction_button, sf::Mouse::getPosition()))
                {
                    ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
                    onInstructionButtonClick();
                }
                else if (isButtonClick(&m_spr_quit_button, sf::Mouse::getPosition()))
                {
                    ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
                    onQuitButtonClick();
                }
                else { }
            }
        }

        bool MainMenuUIController::isButtonClick(sf::Sprite* spr_button, sf::Vector2i mousePosition)
        {
            return spr_button->getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition().x),
                static_cast<float>(sf::Mouse::getPosition().y));
        }

        void MainMenuUIController::onPlayButtonClick()
        {
            GameService::setGameState(GameState::GAMEPLAY);
        }

        void MainMenuUIController::onInstructionButtonClick() { }

        void MainMenuUIController::onQuitButtonClick()
        {
            ServiceLocator::getInstance()->getGraphicService()->closeGameWindow();
        }
    }
}
