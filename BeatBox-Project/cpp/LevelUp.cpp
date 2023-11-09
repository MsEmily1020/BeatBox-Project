#include "LevelUp.h"
#include "Game.h"

void LevelUp::run(RenderWindow& window) {
	window.create(VideoMode(WIDTH, HEIGHT), "levelup");

	Object background = Object(0, 0, WIDTH, HEIGHT, "levelup.png");
	Button nextBtn = Button(430, 550, 250, 210, "nextbtn.png");

	Music music;
	music.openFromFile("audio/levelup.wav");
	music.play();

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			nextBtn.mousePos = Mouse::getPosition(window);
			nextBtn.clickBtn("game");

			if (nextBtn.getNext() == 5) Game().run(window);
		}

		window.clear();

		window.draw(background.sprite_);
		window.draw(nextBtn.sprite_);

		window.display();
	}
}