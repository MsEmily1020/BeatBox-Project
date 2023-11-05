#include "Menu.h"

const int WIDTH = 900;
const int HEIGHT = 600;

void Menu::run(RenderWindow& window) {
	window.create(VideoMode(WIDTH, HEIGHT), "menu");

	Button startBtn = Button(120, 370, 300, 260, "startbtn.png");

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			startBtn.mousePos = Mouse::getPosition(window);

			startBtn.clickBtn("start");
			if (startBtn.getNext() == 1) {
				Main().run(window);
			}
		}

		window.clear();

		window.draw(startBtn.sprite_);

		window.display();
	}
}