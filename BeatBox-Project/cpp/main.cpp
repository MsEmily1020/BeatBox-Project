#include <iostream>
#include <SFML/Graphics.hpp>

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

	Texture* setImage(string path) {
		if (texture.loadFromFile("image/" + path)) return &texture;
	}
};

class Button : public Object {
public:
	Vector2i mouse_pos;

	void clickBtn() {
		if (sprite_.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				cout << "1" << endl;
			}
		}
	}
};

int main() {
	RenderWindow  window(VideoMode(WIDTH, HEIGHT), "MusicTokTok");
	window.setFramerateLimit(15);

	Object background;
	background.sprite_.setPosition(0, 0);
	background.sprite_.setSize(Vector2f(WIDTH, HEIGHT));
	background.sprite_.setTexture(background.setImage("main_background.jpg"));

	Button startBtn;
	startBtn.sprite_.setPosition(120, 370);
	startBtn.sprite_.setSize(Vector2f(300, 260));
	startBtn.sprite_.setTexture(startBtn.setImage("startbtn.png"));
	
	Button explainBtn;
	explainBtn.sprite_.setPosition(500, 370);
	explainBtn.sprite_.setSize(Vector2f(300, 260));
	explainBtn.sprite_.setTexture(explainBtn.setImage("explainbtn.png"));

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			startBtn.mouse_pos = Mouse::getPosition(window);
			explainBtn.mouse_pos = Mouse::getPosition(window);

			startBtn.clickBtn();
			explainBtn.clickBtn();
		}

		window.clear();

		window.draw(background.sprite_);
		window.draw(startBtn.sprite_);
		window.draw(explainBtn.sprite_);

		window.display();
	}
	return 0;
}