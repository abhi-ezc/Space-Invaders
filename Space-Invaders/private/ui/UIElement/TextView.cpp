#include "./../../public/ui/UIElement/TextView.h"
#include "./../../public/global/Config.h"


namespace UI {
	namespace UIElement {
		using namespace Global;

		sf::Font TextView::m_font_bubble_bobble;
		sf::Font TextView::m_font_DS_DIGIB;

		TextView::TextView() = default;

		TextView::~TextView() = default;

		void TextView::initialize(sf::String text, sf::Vector2f position, FontType fontType, int fontSize, sf::Color color) {
			UIView::initialize();

			m_text.setString(text);
			setPosition(position);
			setFont(fontType);
			setFontSize(fontSize);
			setColor(color);
		}

		sf::Drawable& TextView::getDrawable() {
			return m_text;
		}

		void TextView::setFont(FontType font) {
			switch (font) {
			case FontType::BUBBLE_BOBBLE:
				m_text.setFont(TextView::m_font_bubble_bobble);
				break;
			case FontType::DS_DIGIB:
				m_text.setFont(TextView::m_font_DS_DIGIB);
				break;
			}
		}

		void TextView::loadFonts() {
			m_font_bubble_bobble.loadFromFile(Config::bubble_bobble_font_path);
			m_font_DS_DIGIB.loadFromFile(Config::DS_DIGIB_font_path);
		}

		void TextView::setFontSize(int fontSize) {
			m_text.setCharacterSize(fontSize);
		}

		void TextView::setPosition(sf::Vector2f position) {
			m_text.setPosition(position);
		}

		void TextView::setColor(sf::Color color) {
			m_text.setFillColor(color);
		}
	}
}