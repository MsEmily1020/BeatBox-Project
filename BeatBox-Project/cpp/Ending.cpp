#include "Select.h"
#include "Menu.h"

Music music;

const int WIDTH = 900;
const int HEIGHT = 600;

void Main::run(RenderWindow& window) {
	window.create(VideoMode(WIDTH, HEIGHT), "MusicTokTok");

	Object background = Object(0, 0, WIDTH, HEIGHT, "main_background.jpg");
	Object logo = Object(150, 100, 600, 300, "logo.png");

	Button startBtn = Button(120, 370, 300, 260, "startbtn.png");
	Button explainBtn = Button(500, 370, 300, 260, "explainbtn.png");

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			startBtn.mousePos = Mouse::getPosition(window);
			explainBtn.mousePos = Mouse::getPosition(window);

			startBtn.clickBtn("start");
			explainBtn.clickBtn("explain");

			if (startBtn.getNext() == 1) {
				music.stop();
				Select().run(window);
			}
			else if (explainBtn.getNext() == 2) Menu().run(window);
		}

		window.clear();

		window.draw(background.sprite_);
		window.draw(logo.sprite_);
		window.draw(startBtn.sprite_);
		window.draw(explainBtn.sprite_);

		window.display();
	}
}

int main() {
	RenderWindow window;
	
	music.openFromFile("audio/happy.wav");
	music.play();
	
	Main().run(window);

	return 0;
}