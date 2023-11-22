// made in : 김민서

#include "Ending.h"

void Ending::run(RenderWindow& window) {
	window.create(VideoMode(WIDTH, HEIGHT), "end");

	// object
	Object background = Object(0, 0, WIDTH, HEIGHT, "ending_background.jpg");
	Button restartBtn = Button(430, 550, 250, 210, "restartbtn.png");

	// 음악 재생
	Music music;
	music.openFromFile("audio/gameover.wav");
	music.play(); 

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed) {
				window.close();

			}

			// 다시 시작 버튼 클릭 구현 시 필요한 변수에 값 얻어오기
			restartBtn.mousePos = Mouse::getPosition(window);
			restartBtn.clickBtn("main");

			// 다시 메인으로 돌아가기
			if (restartBtn.getNext() == 6) Main().run(window);

		}

		window.clear();

		window.draw(background.sprite_);
		window.draw(restartBtn.sprite_);

		window.display();
	}
}