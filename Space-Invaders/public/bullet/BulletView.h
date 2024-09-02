#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/String.hpp>

namespace UI {
	namespace UIElement {
		class ImageView;
	}
}


namespace Bullet {
	class BulletController;

	class BulletView {
	private:
		sf::String m_bullet_texture_path;
		UI::UIElement::ImageView* m_bullet_image;

		BulletController* m_bullet_controller;

		float m_sprite_height = 18.f;
		float m_sprite_width = 18.f;

		void loadTexture();
		void initializeSprite();

	public:
		BulletView(BulletController* controller);
		~BulletView();

		void initialize();
		void update();
		void render();
	};
}
