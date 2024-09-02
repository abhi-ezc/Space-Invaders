#pragma once
#include "UIView.h"
#include "SFML/Graphics.hpp"

namespace UI {
	namespace UIElement {
		class ImageView : public UIView {

		private:
			bool setTexture(sf::String texturePath);
			void setScale(float width, float height);

		protected:
			//image related variables like texture and sprite
			sf::Texture m_texture;
			sf::Sprite m_sprite;

		public:
			ImageView();
			virtual ~ImageView();

			virtual void initialize(sf::String texturePath, float width, float height, sf::Vector2f position);
			virtual void update() override;
			virtual void render() override;
			virtual sf::Drawable& getDrawable() override;

			void setPosition(sf::Vector2f position);
			void setRotation(float angle);
			void setOriginAtCentre();
			void setCentreAligned();
			void setImageAlpha(float alpha);
			sf::FloatRect getLocalBounds();

		};
	}
}