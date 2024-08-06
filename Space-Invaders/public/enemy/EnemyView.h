#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy
{
    class EnemyController;

    class EnemyView
    {
        private:
            sf::Texture m_tex_enemy;
            sf::Sprite m_spr_enemy;
            sf::String m_str_texture_path = "assets/textures/zapper.png";
            const float c_sprite_width = 100.f;
            const float c_sprite_height = 80.f;

            EnemyController* m_enemy_controller;

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
