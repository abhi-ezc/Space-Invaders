#include "./../../../public/element/Bunker/BunkerView.h"
#include "../../../public/graphic/GraphicService.h"
#include "./../../../public/global/ServiceLocator.h"
#include "./../../../public/global/Config.h"
#include "./../../../public/element/Bunker/BunkerController.h"
#include "./../../../public/ui/UIElement/ImageView.h"

namespace Element {
	namespace Bunker {
		using namespace Global;

		BunkerView::BunkerView() {
			m_bunker_image = nullptr;
		}

		BunkerView::~BunkerView() {
			delete m_bunker_image;
		}

		void BunkerView::initialize(BunkerController* controller) {
			initializeSprite(controller->getPosition());
		}

		void BunkerView::update() {
			m_bunker_image->update();
		}

		void BunkerView::render() {
			m_bunker_image->render();
		}

		void BunkerView::initializeSprite(sf::Vector2f position) {
			m_bunker_image = new UI::UIElement::ImageView();
			m_bunker_image->initialize(Config::bunker_texture_path, m_sprite_width, m_sprite_height, position);
		}

	}
}
