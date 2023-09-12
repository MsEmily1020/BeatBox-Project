#include <SFML/Graphics.hpp>

using namespace sf;

const int WIDTH = 1200;
const int HEIGHT = 1000;

class Object {
public:
	int x_;
	int y_;
	RectangleShape sprite_;
};

int main() {
	RenderWindow  window(VideoMode(WIDTH, HEIGHT), "MusicTokTok");
	window.setFramerateLimit(15);
	
	Texture texture;
	if (!texture.loadFromFile("image/player.png"))
		return -1;
	
	Object player;
	player.sprite_.setFillColor(Color::White);
	player.sprite_.setPosition(200, 300);
	player.sprite_.setSize(Vector2f(100, 100));
	player.sprite_.setTexture(&texture);

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}


		window.clear();
		
		window.draw(player.sprite_);
		
		window.display();
	}
	return 0;
}