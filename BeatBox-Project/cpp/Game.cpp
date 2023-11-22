#include "Game.h"
#include "LevelUp.h"
#include "Select.h"
#include "HappyEnding.h"

void Game::run(RenderWindow& window)
{
	window.create(VideoMode(WIDTH, HEIGHT), "game");
	window.setFramerateLimit(30);

	// object
	TextString scoreText = TextString(10, 10, 24, "Score: ");
	scoreText.text.setFillColor(Color::White);
	// 윈도우 초기화
	TextString healthText = TextString(WIDTH - 150, 10, 24, "Health: ");
	healthText.text.setFillColor(Color::White);
	// 게임 매니저 객체 생성
	GameManager* pGameMgr = new GameManager();
	pGameMgr->Init();

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
			
			if (e.type == Event::KeyPressed)
				pGameMgr->CheckKey();
		}

		pGameMgr->Move();
		// 게임 점수 체크
		if (pGameMgr->GetScore() >= 10)
		{
			window.close();
			Select().stopSong();
			LevelUp().run(window);
		}

		window.clear(Color::Black);
		pGameMgr->Draw(window);
		// 점수 및 체력 표시
		healthText.text.setString("Health: " + to_string(pGameMgr->GetHealth()));
		window.draw(healthText.text);

		scoreText.text.setString("Score: " + to_string(pGameMgr->GetScore()));
		window.draw(scoreText.text);
		window.display();
		// 게임 오버 여부 확인
		pGameMgr->CheckGameOver();
	}
	// 게임 매니저 객체 해제
	delete(pGameMgr);
}