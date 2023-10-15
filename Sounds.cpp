#include "Sounds.hpp"

Sounds::Sounds(){
	music.openFromFile("music.ogg");
	music.setLoop(true);
	music.setVolume(20);
	
	if(!lineSoundBuffer.loadFromFile("line.ogg")){
		cout<<"Error al cargar sonido"<<endl;
	}
	
	if(!newScoreSoundBuffer.loadFromFile("newScore.ogg")){
		cout<<"Error al cargar sonido"<<endl;
	}
	
	if(!gameOverSoundBuffer.loadFromFile("gameOver.ogg")){
		cout<<"Error al cargar sonido"<<endl;
	}
	
	lineSound.setBuffer(lineSoundBuffer);
	newScoreSound.setBuffer(newScoreSoundBuffer);
	gameOverSound.setBuffer(gameOverSoundBuffer);
}

void Sounds::PlayMusic(){
	music.play();
}

void Sounds::PauseMusic(){
	music.pause();
}

void Sounds::PlayLine(){
	lineSound.play();
}

void Sounds::PlayNewScore(){
	newScoreSound.play();
}
void Sounds::PlayGameOver(){
	gameOverSound.play();
}
