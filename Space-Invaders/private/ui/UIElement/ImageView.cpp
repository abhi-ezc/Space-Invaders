#include "./../../public/ui/UIElement/ImageView.h"
namespace UI {
	namespace UIElement {
		ImageView::ImageView() = default;

		ImageView::~ImageView() = default;

		void ImageView::initialize(sf::String texturePath, float width, float height, sf::Vector2f position) {
			UIView::initialize();
			if (setTexture(texturePath)) {
				setScale(width, height);
				setPosition(position);
			}
		}

		void ImageView::update() {
			UIView::update();
		}

		void ImageView::render() {
			UIView::render();
		}

		sf::Drawable& ImageView::getDrawable() {
			return m_sprite;
		}

		bool ImageView::setTexture(sf::String texturePath) {
			if (!m_texture.loadFromFile(texturePath)) {
				return false;
			}

			m_sprite.setTexture(m_texture);
		}

		void ImageView::setScale(float width, float height) {
			auto size = m_sprite.getTexture()->getSize();
			float x = width / size.x;
			float y = height / size.y;
			m_sprite.setScale(x, y);
		}

		void ImageView::setPosition(sf::Vector2f position) {
			m_sprite.setPosition(position);
		}

		void ImageView::setRotation(float angle) {
			m_sprite.setRotation(angle);
		}

		void ImageView::setOriginAtCentre() {
			sf::FloatRect bounds = m_sprite.getLocalBounds();
			m_sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		}

		void ImageView::setCentreAligned() {
			sf::Vector2f size = static_cast<sf::Vector2f>(m_game_window->getSize());
			float y = m_sprite.getGlobalBounds().getPosition().y;
			m_sprite.setPosition(size.x / 2, y);
		}

		void ImageView::setImageAlpha(float alpha) {
			sf::Color color = m_sprite.getColor();
			color.a = alpha;
			m_sprite.setColor(color);
		}
		sf::FloatRect ImageView::getLocalBounds() {
			return m_sprite.getLocalBounds();
		}
	}
}