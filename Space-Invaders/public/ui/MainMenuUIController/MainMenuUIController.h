#pragma once
#include <SFML/Graphics.hpp>
#include "./../interface/IUIController.h"

namespace UI
{
    namespace MainMenu
    {
        class MainMenuUIController : public Interface::IUIController
        {
            private:
                sf::RenderWindow* m_game_window;

                // textures for ui elements
                sf::Texture m_tex_background_image;
                sf::Texture m_tex_play_button;
                sf::Texture m_tex_instruction_button;
                sf::Texture m_tex_quit_button;

                // sprites for drawing ui elements
                sf::Sprite m_spr_background_image;
                sf::Sprite m_spr_play_button;
                sf::Sprite m_spr_instruction_button;
                sf::Sprite m_spr_quit_button;

                // buttons size
                const float m_f_button_height = 140.f;
                const float m_f_button_width = 400.f;

                void initializeBackgroundImage();
                void initializeButtons();

                bool loadButtonTextures();
                void createButtonSprites();
                void scaleAllButtons();
                void scaleButton(sf::Sprite* spr_button);
                void setAllButtonsPosition();
                void setButtonPosition(sf::Sprite* spr_button, float y);

            public:
                MainMenuUIController();
                ~MainMenuUIController() override;

                void initialize() override;
                void update() override;
                void render() override;
                void show() override;

                void processButtonInteractions();
                bool isButtonClick(sf::Sprite* spr_button, sf::Vector2i mousePosition);
                void onPlayButtonClick();
                void onInstructionButtonClick();
                void onQuitButtonClick();
        };
    }
}
