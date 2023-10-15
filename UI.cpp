#include "UI.hpp"

UI::UI(){
	if(!font.loadFromFile("ka1.ttf")){
		cout<<"Error al cargar fuente de texto"<<endl;
	}
	
	scoreTextTitle.setFont(font);
	scoreTextTitle.setFillColor(Color::White);
	scoreTextTitle.setPosition(Vector2f(235,25));
	scoreTextTitle.setString("Score");
	
	maxScoreTextTitle.setFont(font);
	maxScoreTextTitle.setFillColor(Color::White);
	maxScoreTextTitle.setPosition(Vector2f(225,200));
	maxScoreTextTitle.setString("Max Score");
	maxScoreTextTitle.setCharacterSize(20);
	
	scoreText.setFont(font);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(Vector2f(250,70));
	
	maxScoreText.setFont(font);
	maxScoreText.setFillColor(Color::White);
	maxScoreText.setPosition(Vector2f(250,245));
	
	byText.setFont(font);
	byText.setFillColor(Color::White);
	byText.setPosition(Vector2f(260,370));
	byText.setString("by Dit");
	byText.setCharacterSize(20);

	gameOverText.setFont(font);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition(Vector2f(8,150));
	gameOverText.setString("Game Over");
	gameOverText.setCharacterSize(25);	
	
	newScoreText.setFont(font);
	newScoreText.setFillColor(Color::White);
	newScoreText.setPosition(Vector2f(8,150));
	newScoreText.setString("New Score");
	newScoreText.setCharacterSize(25);	
	
}

void UI::SetScore(int x){
	if(x<=9) scoreText.setString("000"+to_string(x));
	else if(x<=99) scoreText.setString("00"+to_string(x));
	else if(x<=999) scoreText.setString("000"+to_string(x));
	else if(x<=9999) scoreText.setString(to_string(x));
	else scoreText.setString("9999");
}


void UI::SetMaxScore(int x){
	if(x<=9) maxScoreText.setString("000"+to_string(x));
	else if(x<=99) maxScoreText.setString("00"+to_string(x));
	else if(x<=999) maxScoreText.setString("000"+to_string(x));
	else if(x<=9999) maxScoreText.setString(to_string(x));
	else maxScoreText.setString("9999");
}

void UI::GameOver(){
	gameOver=1;
}


void UI::NewScore(){
	newScore=1;
}

void UI::draw(RenderTarget &rt,RenderStates rs) const{
	rt.draw(scoreTextTitle,rs);
	rt.draw(scoreText,rs);
	rt.draw(maxScoreTextTitle,rs);
	rt.draw(maxScoreText,rs);
	rt.draw(byText,rs);
	if(gameOver) rt.draw(gameOverText,rs);
	if(newScore) rt.draw(newScoreText,rs);
}

