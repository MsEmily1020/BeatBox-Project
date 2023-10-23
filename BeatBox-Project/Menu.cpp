#include "Main.h"
#include "Menu.h"

const int WIDTH = 900;
const int HEIGHT = 600;

void Menu::run(RenderWindow& window) {
	window.create(VideoMode(WIDTH, HEIGHT), "menu");
	window.setFramerateLimit(15);

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();

		window.display();
	}
}