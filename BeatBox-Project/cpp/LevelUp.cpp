// made in : 김혜승

#include "LevelUp.h"
#include "Select.h"
#include "Game.h"
#include "HappyEnding.h"

void LevelUp::run(RenderWindow& window) {
	window.create(VideoMode(WIDTH, HEIGHT), "levelup");

	// object
	Object background = Object(0, 0, WIDTH, HEIGHT, "levelup.png");
	Button nextBtn = Button(310, 370, 300, 260, "nextbtn.png");

	// 음악 재생
	Music music;
	music.openFromFile("audio/levelup.wav");
	music.play();

	LevelUp::levelUp();
	if (getLevelUp() == 3) HappyEnding().run(window);

	if (level == 2) Arrow().setSpeed(0.8f);
	else Arrow().setSpeed(0.9f);

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();


			// 다음 게임으로 넘어가는 버튼 클릭 구현 시 필요한 변수에 값 얻어오기
			nextBtn.mousePos = Mouse::getPosition(window);
			nextBtn.clickBtn("start");

			// 노래 선택 화면으로 전환
			if (nextBtn.getNext() == 1) Select().run(window);
		}

		window.clear();

		window.draw(background.sprite_);
		window.draw(nextBtn.sprite_);

		window.display();
	}
}
