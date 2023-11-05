#include <iostream>
#include "Select.h"
#include "Main.h"

int nextAlbum = 1;

const int WIDTH = 900;
const int HEIGHT = 600;

void Select::run(RenderWindow& window) {
	window.create(VideoMode(WIDTH, HEIGHT), "Choose Level");
	window.setFramerateLimit(1000);

	Object background = Object(0, 0, WIDTH, HEIGHT, "select_background.jpg");
	Button leftBtn = Button(50, 170, 200, 200, "left.png");
	Button rightBtn = Button(650, 170, 200, 200, "right.png");

	Object album = Object(320, 160, 280, 280, "1.png");

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			leftBtn.mousePos = Mouse::getPosition(window);
			rightBtn.mousePos = Mouse::getPosition(window);

			leftBtn.clickBtn("left");
			rightBtn.clickBtn("right");

			if (leftBtn.getNext() == 3) {
				nextAlbum -= 1;
				if (nextAlbum < 1) nextAlbum = 1;
				album.sprite_.setTexture(album.setImage(to_string(nextAlbum) + ".png"));
				leftBtn.setNext(0);
			}

			else if (rightBtn.getNext() == 4) {
				nextAlbum += 1;
				if (nextAlbum > 7) nextAlbum = 7;
				album.sprite_.setTexture(album.setImage(to_string(nextAlbum) + ".png"));
				rightBtn.setNext(0);
			}
		}

		window.clear();


		window.draw(background.sprite_);
		window.draw(leftBtn.sprite_);
		window.draw(rightBtn.sprite_);
		window.draw(album.sprite_);

		window.display();
	}
}