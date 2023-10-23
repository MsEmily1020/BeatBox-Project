#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Select.h"
#include "Main.h"
#include "Menu.h"

using namespace std;
using namespace sf;

const int WIDTH = 900;
const int HEIGHT = 600;
int isNext = 0;

void Button::clickBtn(String str) {
	if (sprite_.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (str == "start") isNext = 1;
			else isNext = 2;
		}
	}
}

int main() {
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "MusicTokTok");
	window.setFramerateLimit(15);

	Object background = Object(0, 0, WIDTH, HEIGHT, "main_background.jpg");
	Object logo = Object(150, 100, 600, 300, "logo.png");
	
	Button startBtn = Button(120, 370, 300, 260, "startbtn.png");
	Button explainBtn = Button(500, 370, 300, 260, "explainbtn.png");
	
	Music music;
	music.openFromFile("audio/happy.wav");
	music.play();

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

			if (isNext == 1) Select().run(window);
			else if (isNext == 2) Menu().run(window);
		}

		window.clear();

		window.draw(background.sprite_);
		window.draw(logo.sprite_);
		window.draw(startBtn.sprite_);
		window.draw(explainBtn.sprite_);

		window.display();
	}

	return 0;
}