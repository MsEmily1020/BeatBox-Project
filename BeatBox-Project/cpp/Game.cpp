#include "Game.h"

const int WIDTH = 900;
const int HEIGHT = 600;

void Game::run(RenderWindow& window) {
	window.create(VideoMode(WIDTH, HEIGHT), "game");

	Object background = Object(0, 0, WIDTH, HEIGHT, "game_background.jpg");

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		window.clear();

		window.draw(background.sprite_);

		window.display();
	}
}