#include "Menu.h"

void Menu::run(RenderWindow& window) {
	window.create(VideoMode(WIDTH, HEIGHT), "menu");

	// object
	Object background = Object(0, 0, WIDTH, HEIGHT, "menu_background.png");
	Button mainBtn = Button(330, 410, 250, 200, "startbtn.png");

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			// 메인으로 돌아가는 버튼 클릭 구현 시 필요한 변수에 값 얻어오기
			mainBtn.mousePos = Mouse::getPosition(window);

			mainBtn.clickBtn("main");

			// 메인 화면으로 돌아가기
			if (mainBtn.getNext() == 6) {
				Main().run(window);
			}
		}

		window.clear();

		window.draw(background.sprite_);
		window.draw(mainBtn.sprite_);

		window.display();
	}
}