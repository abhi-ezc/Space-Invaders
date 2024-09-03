#pragma once
#include "UIView.h"

namespace UI {
	namespace UIElement {

		enum class FontType {
			BUBBLE_BOBBLE,
			DS_DIGIB,
		};

		class TextView : public UIView {
		private:
			sf::Text  m_text;

		protected:

		public:
			static const FontType m_default_font_type = FontType::BUBBLE_BOBBLE;
			static const int m_default_font_size = 55;

			static sf::Font m_font_bubble_bobble;
			static sf::Font m_font_DS_DIGIB;

			TextView();
			~TextView() override;
			void setFont(FontType font);
			void setFontSize(int fontSize);
			void setPosition(sf::Vector2f position);
			void setColor(sf::Color color);

			static void loadFonts();

			void initialize(sf::String text,
				sf::Vector2f position,
				FontType fontType = m_default_font_type,
				int fontSize = m_default_font_size,
				sf::Color color = sf::Color::White);

			sf::Drawable& getDrawable() override;

		};
	}
}