#pragma once
#include "SFML/Graphics.hpp"

namespace Entity
{
    enum class EntityType;
}

namespace Player
{
    // player state enum
    enum class PlayerState
    {
        ALIVE,
        DEAD,
        LIMBO
    };

    // player model class
    class PlayerModel
    {
        private:
            const sf::Vector2f m_initial_player_position = sf::Vector2f(950.f, 950.f);
            sf::Vector2f m_current_player_position;
            PlayerState m_player_state;
            int m_player_score;

            sf::Vector2f m_muzzle_offset = sf::Vector2f(0, -40.f);
            Entity::EntityType m_entity_type;

            bool b_shield;
            bool b_rapid_fire;
            bool b_tripple_laser;

            const float shiled_powerup_duration = 10.f;
            const float rapid_fire_powerup_duration = 10.f;
            const float tripple_laser_powerup_duration = 10.f;

            const float freeze_duration = 2.f;

            const float fire_cooldown_duration = 0.2f;
            const float rapid_fire_cooldown_duration = 0.05f;
            const float tripple_laser_position_offset = 30.f;

            float elapsed_shield_duration;
            float elapsed_rapid_fire_duration;
            float elapsed_tripple_laser_duration;

            float elapsed_fire_duration;
            float elapsed_freeze_duration;

        public:
            const float m_movement_speed = 350.0f;
            const float m_left_most_position = 50.f;
            const float m_right_most_position = 1800.f;

            // constructor & destructor
            PlayerModel();
            ~PlayerModel();

            // lifecycle methods
            void initialize();
            void update();
            void render();

            // operator functions
            void reset();

            // getters
            sf::Vector2f getPlayerPosition();
            bool isPlayerAlive();
            PlayerState getPlayerState();
            int getPlayerScore();
            sf::Vector2f getMuzzleOffset();
            Entity::EntityType getEntityType();
            bool isShieldEnabled();
            bool isRapidFireEnabled();
            bool isTrippleLaserEnabled();

            // setters
            void setPlayerState(PlayerState newPlayerState);
            void setPlayerScore(int score);
            void setPlayerPosition(sf::Vector2f position);

            void setShieldState(bool value);
            void setRapidFireState(bool value);
            void setTrippleFireState(bool value);
    };
}
