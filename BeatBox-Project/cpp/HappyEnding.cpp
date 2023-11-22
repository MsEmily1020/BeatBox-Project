// made in : ±è¹Î¼­

#include "HappyEnding.h"

void HappyEnding::run(RenderWindow& window) {
	window.create(VideoMode(WIDTH, HEIGHT), "HappyEnding");

	// object
	Object background = Object(0, 0, WIDTH, HEIGHT, "happyending.png");

	// À½¾Ç
	Music music;
	music.openFromFile("audio/happyending.wav");
	music.play();

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