#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

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

	Texture* setImage(string path) {
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
				else isNext = 2;
			}
		}
	}

	int getNext() { return isNext; }
};

class Main {
public: 
	void run(RenderWindow& window);
};