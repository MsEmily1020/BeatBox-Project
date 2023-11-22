#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

const int WIDTH = 900;
const int HEIGHT = 600;

class Object {
public:
	int width_;
	int height_;
	RectangleShape sprite_;
	Texture texture;

	Object(int x, int y, int width, int height, String path) {
		sprite_.setPosition(x, y);
		sprite_.setSize(Vector2f(width, height));
		sprite_.setTexture(setImage(path));
	}

	Texture* setImage(String path) {
		if (texture.loadFromFile("image/" + path)) return &texture;
	}
};

class Button : public Object {
public:
	Vector2i mousePos;
	int isNext = 0;

	Button(int x, int y, int width, int height, String path) : Object(x, y, width, height, path) {}

	void clickBtn(String str) {
		if (sprite_.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (str == "start") isNext = 1;
				else if (str == "explain") isNext = 2;
				else if (str == "left") isNext = 3;
				else if (str == "right") isNext = 4;
				else if (str == "game") isNext = 5;
				else if (str == "main") isNext = 6;
			}
		}
	}

	void setNext(int next) { isNext = next; }

	int getNext() { return isNext; }
};

class TextString {
public:
	Text text;
	Font font;

	TextString(int x, int y, int size, String content) {
		text.setPosition(Vector2f(x, y));
		text.setCharacterSize(size);
		text.setString(content);
		font.loadFromFile("C:\\windows\\Fonts\\Arial.ttf");
		text.setFont(font);
		text.setFillColor(Color::Black);

		if (x == 0) {
			FloatRect textRect = text.getLocalBounds();
			text.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			text.setPosition(Vector2f(920 / 2.0f, y));
		}
	}

	void setText(int x, int y, String content) {
		text.setString(content);

		text.setPosition(Vector2f(x, y));

		if (x == 0) {
			FloatRect textRect = text.getLocalBounds();
			text.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			text.setPosition(Vector2f(920 / 2.0f, y));
		}
	}
};

class Main {
public:
	void run(RenderWindow& window);
};