#pragma once
#include <SFML/Graphics.hpp>

namespace UI {
	namespace UIElement {
		class ImageView;
	}
}
namespace Enemy {
	class EnemyController;
	enum class EnemyType;

	class EnemyView {
	private:
		sf::String m_str_texture_path;
		UI::UIElement::ImageView* m_enemy_image;
		const float c_sprite_width = 60.f;
		const float c_sprite_height = 60.f;

		EnemyController* m_enemy_controller;
		void initializeEnemySprite();
		void createEnemySprite();
		void updateSpritePosition();

	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* enemyController);
		void update();
		void render();

		sf::Vector2f getSpriteSize();
	};
}
