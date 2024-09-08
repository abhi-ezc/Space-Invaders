#pragma once
#include "SFML/System/Vector2.hpp"
#include "./../collision/ColliderController.h"

namespace Entity
{
    enum class EntityType;
}

namespace Player
{
    class PlayerModel;
    class PlayerView;
    enum class PlayerState;

    class PlayerController : public Collision::ColliderController
    {
        private:
            PlayerModel* m_player_model;
            PlayerView* m_player_view;

            void processPlayerInputs();
            void moveLeft();
            void moveRight();
            void fireBullet(bool b_tripple_laser = false);
            void fireBullet(sf::Vector2f position);

            bool processBulletCollision(ICollider* other_collider);
            bool processPowerupCollision(ICollider* other_collider);
            bool processEnemyCollision(ICollider* other_collider);

            void updateFreezDuration();
            void freezPlayer();

            void disableShield();
            void disableRapidFire();
            void disableTrippleLaser();

        public:
            // constructors and destructors
            PlayerController();
            ~PlayerController() override;

            // life cycle methods
            void initialize();
            void update();
            void render();

            // getters
            sf::Vector2f getPlayerPosition();
            Entity::EntityType getEntityType() override;
            sf::Sprite& getColliderSprite() override;
            PlayerState getPlayerState();

            // others
            void onCollision(ICollider* otherCollider) override;

            void reset();

            void enableShield();
            void enableRapidFire();
            void enableTrippleLaser();
    };
}
