// made in : 김혜승

#include "Select.h"
#include "Menu.h"
#include "LevelUp.h"

Music music;

int LevelUp::level = 0;

void Main::run(RenderWindow& window) {
	window.create(VideoMode(WIDTH, HEIGHT), "MusicTokTok");

	// object
	Object background = Object(0, 0, WIDTH, HEIGHT, "main_background.jpg");
	Object logo = Object(150, 100, 600, 300, "logo.png");

	Button startBtn = Button(120, 370, 300, 260, "startbtn.png");
	Button explainBtn = Button(500, 370, 300, 260, "explainbtn.png");

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			// 게임 시작(노래 선택 화면으로 전환) 및 게임 설명 버튼 클릭 구현 시 필요한 변수에 값 얻어오기
			startBtn.mousePos = Mouse::getPosition(window);
			explainBtn.mousePos = Mouse::getPosition(window);

			startBtn.clickBtn("start");
			explainBtn.clickBtn("explain");

			// 노래 선택 화면으로
			if (startBtn.getNext() == 1) {
				music.stop();
				Select().run(window);
			}
			
			// 게임 설명 화면으로
			else if (explainBtn.getNext() == 2) Menu().run(window);
		}

		window.clear();

		window.draw(background.sprite_);
		window.draw(logo.sprite_);
		window.draw(startBtn.sprite_);
		window.draw(explainBtn.sprite_);

		window.display();
	}
}

int main() {
	RenderWindow window;

	// 배경 음악 실행
	music.openFromFile("audio/happy.wav");
	music.play();

	Main().run(window);

	return 0;
}