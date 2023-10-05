#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

const int WIDTH = 900;
const int HEIGHT = 600;

class Button {
public:
	int width_;
	int height_;
	RectangleShape sprite_;
	Vector2i mouse_pos;
	Texture texture;

	void clickBtn() {
		if (sprite_.getGlobalBounds().contains(mouse_pos.x, mouse_pos.y)) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				cout << "1" << endl;
			}
		}
	}

	Texture* setImage(string path) {
		if (texture.loadFromFile("image/" + path + ".png")) return &texture;
	}
};

int main() {
	RenderWindow  window(VideoMode(WIDTH, HEIGHT), "MusicTokTok");
	window.setFramerateLimit(15);

	Button startBtn;
	startBtn.sprite_.setPosition(130, 370);
	startBtn.sprite_.setSize(Vector2f(300, 250));
	startBtn.sprite_.setTexture(startBtn.setImage("startbtn"));
	
	Button explainBtn;
	explainBtn.sprite_.setTexture(explainBtn.setImage("explainbtn"));
	explainBtn.sprite_.setPosition(550, 450);
	explainBtn.sprite_.setSize(Vector2f(200, 80));

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

		window.draw(startBtn.sprite_);
		window.draw(explainBtn.sprite_);

		window.display();
	}
	return 0;
}