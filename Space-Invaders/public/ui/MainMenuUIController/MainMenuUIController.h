#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
    namespace MainMenu
    {
        class MainMenuUIController
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
                ~MainMenuUIController();

                void initialize();
                void update();
                void render();

                void processButtonInteractions();
                bool isButtonClick(sf::Sprite* spr_button, sf::Vector2i mousePosition);
                void onPlayButtonClick();
                void onInstructionButtonClick();
                void onQuitButtonClick();
        };
    }
}
