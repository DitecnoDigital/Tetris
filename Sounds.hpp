#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class Sounds{
	private:
		Music music;
		Sound lineSound;
		Sound newScoreSound;
		Sound gameOverSound;
		SoundBuffer lineSoundBuffer;
		SoundBuffer newScoreSoundBuffer;
		SoundBuffer gameOverSoundBuffer;
	public:
		Sounds();
		void PlayMusic();
		void PauseMusic();
		void PlayLine();
		void PlayGameOver();
		void PlayNewScore();
};
