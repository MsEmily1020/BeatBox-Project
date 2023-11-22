// made in : 김혜승

#pragma once

#include "Main.h"

class Select {
public :
	int nextAlbum = 1; // 현재 곡의 인덱스

	void run(RenderWindow& window);
	void nextSong(int song); // 이전 곡 / 다음 곡으로 전환하는 메소드
	void playSong(); // 음악 재생하는 메소드
	void stopSong(); // 음악 멈추는 메소드
};