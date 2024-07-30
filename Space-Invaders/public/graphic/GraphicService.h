#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Drawable.hpp"
class GraphicService {

	private:
	sf::String windowTitle = "Space Invaders"; // window title
	const int gameWindowWidth =800; // Game Window Width
	const int gameWindowHeight = 640; // Game Window Height
	const sf::Color windowColor = sf::Color::Blue; // Color to clear GameWindow with
	const int frameLimit = 60;

	sf::VideoMode* videoMode; // video mode pointer
	sf::RenderWindow* gameWindow; // game window pointer

	void setVideoMode(); // method for setting our video mode
	void createGameWindow(); // method for creating new GameWindow
	void onDestroy(); // invoke while window is getting destroyed

	public:
	GraphicService(); // GraphicService Constructor
	~GraphicService();// Destructor

	void initialize(); // init Graphic Service: creating game window
	void update(); // update: trigger each frame clearing game window
	void render(); // render: render the latest drawn images to the frame
	bool isGameWindowOpen(); // return true if the game window is open
	sf::RenderWindow* getGameWindow(); // return game window
	void closeGameWindow();
	void draw(sf::Drawable &drawable);

};