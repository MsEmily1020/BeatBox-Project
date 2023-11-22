#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

// 창 크기
const int WIDTH = 900;
const int HEIGHT = 600;

// 화면의 모든 Object
class Object {
public:
	int width_;
	int height_;
	RectangleShape sprite_;
	Texture texture;

	// object의 위치와 크기 및 이미지 지정
	Object(int x, int y, int width, int height, String path) {
		sprite_.setPosition(x, y);
		sprite_.setSize(Vector2f(width, height));
		sprite_.setTexture(setImage(path));
	}

	// 이미지를 로드하여 리턴시켜줌
	Texture* setImage(String path) {
		if (texture.loadFromFile("image/" + path)) return &texture;
	}
};

// Object를 상속받아 Button 구현
class Button : public Object {
public:
	Vector2i mousePos;
	int isNext = 0;

	// button 생성자
	Button(int x, int y, int width, int height, String path) : Object(x, y, width, height, path) {}

	// 클릭 시 메소드 구현
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

// 텍스트
class TextString {
public:
	Text text;
	Font font;

	// 텍스트의 위치, 사이즈, 넣을 값 등을 셋팅해줌
	TextString(int x, int y, int size, String content) {
		text.setPosition(Vector2f(x, y));
		text.setCharacterSize(size);
		text.setString(content);
		font.loadFromFile("C:\\windows\\Fonts\\Arial.ttf");
		text.setFont(font);
		text.setFillColor(Color::Black);

		// x가 0일 시 자동 가운데 정렬 되도록
		if (x == 0) {
			FloatRect textRect = text.getLocalBounds();
			text.setOrigin(textRect.left + textRect.width / 2.0f,
				textRect.top + textRect.height / 2.0f);
			text.setPosition(Vector2f(920 / 2.0f, y));
		}
	}

	// 생성자와 다른 점 -> 기존의 text에서 위치와 넣을 값만 변경하고 싶을 경우
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