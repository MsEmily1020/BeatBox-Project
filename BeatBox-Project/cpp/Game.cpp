#include "Game.h"

void Game::run(RenderWindow& window)
{
	window.create(VideoMode(WIDTH, HEIGHT), "game");
	window.setFramerateLimit(30);

	TextString scoreText = TextString(10, 10, 24, "Score: ");
	scoreText.text.setFillColor(Color::White);

	TextString healthText = TextString(WIDTH - 150, 10, 24, "Health: ");
	healthText.text.setFillColor(Color::White);

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

		window.clear(Color::Black);
		pGameMgr->Draw(window);
		healthText.text.setString("Health: " + to_string(pGameMgr->GetHealth()));
		window.draw(healthText.text);

		scoreText.text.setString("Score: " + to_string(pGameMgr->GetScore()));
		window.draw(scoreText.text);
		window.display();

		pGameMgr->CheckGameOver();
	}
	 
	delete(pGameMgr);
}