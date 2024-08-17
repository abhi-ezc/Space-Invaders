#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyController;
    enum class EnemyType;

    class EnemyView
    {
        private:
            const sf::String m_subzero_texture_path = "assets/textures/subzero.png";
            const sf::String m_zapper_texture_path = "assets/textures/zapper.png";
            const sf::String m_thunder_snake_texture_path = "assets/textures/thunder_snake.png";
            const sf::String m_ufo_texture_path = "assets/textures/ufo.png";

            sf::Texture m_tex_enemy;
            sf::Sprite m_spr_enemy;
            sf::String m_str_texture_path = "assets/textures/";
            const float c_sprite_width = 60.f;
            const float c_sprite_height = 60.f;

            EnemyController* m_enemy_controller;
            void initializeEnemySprite();
            void createEnemySprite();
            void scaleSprite();
            void updateSpritePosition();

        public:
            EnemyView();
            ~EnemyView();

            void initialize(EnemyController* enemyController);
            void update();
            void render();
    };
}
