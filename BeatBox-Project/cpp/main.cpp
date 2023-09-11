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

	Object player;


	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}
	return 0;
}