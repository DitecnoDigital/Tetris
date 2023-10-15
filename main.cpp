#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "UI.hpp"
#include "Sounds.hpp"
#include <fstream>

using namespace std;
using namespace sf;

int main(){
	Board board;
	UI ui;
	Sounds sounds;
	
	RenderWindow window(VideoMode(400,400),"Tetris");
	window.setFramerateLimit(60);
	
	board.InstallPart();
	
	int right=0,left=0,up=0;
	
	int score = 0;
	int maxScore = 0;
	
	ifstream in("maxScore.txt");
	in>>maxScore;
	ui.SetMaxScore(maxScore);
	ui.SetScore(score);
	
	bool live = 1;
	
	sounds.PlayMusic();
	
	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type==Event::Closed) window.close();
		}
		
		if(live){
			if(Keyboard::isKeyPressed(Keyboard::Up)&&!up) board.RotatePart(), up=1;
			else if(!Keyboard::isKeyPressed(Keyboard::Up)){
				up=0;
			}
			
			if(Keyboard::isKeyPressed(Keyboard::Down)) board.UpdateLimitTimer(5);
			else board.UpdateLimitTimer(30);
			
			if(Keyboard::isKeyPressed(Keyboard::Right)&&!right){
				board.Right();
				right=1;
			}else if(!Keyboard::isKeyPressed(Keyboard::Right)){
				right=0;
			}else if(Keyboard::isKeyPressed(Keyboard::Right)&&right){
				right++;
				if(right==6) right=0;
			}
			
			if(Keyboard::isKeyPressed(Keyboard::Left)&&!left){
				board.Left();
				left=1;
			}else if(!Keyboard::isKeyPressed(Keyboard::Left)){
				left=0;
			}else if(Keyboard::isKeyPressed(Keyboard::Left)&&left){
				left++;
				if(left==6) left=0;
			}
			
			if(board.UpdateBoard()){
				if(!board.InstallPart()){
					live=0;
					board.ClearBoard();
					sounds.PauseMusic();
					if(score>maxScore){
						ui.NewScore();
						ofstream out("maxScore.txt");
						out<<score;
						sounds.PlayNewScore();
					}else{
						ui.GameOver();
						sounds.PlayGameOver();
					}
				}
			}
			board.UpdateBoardColors();
			
			int newScore = board.CheckLine()*5;
			score+=newScore;
			ui.SetScore(score);
			if(newScore>0) sounds.PlayLine();
		}
		
		
		window.clear(Color(20,20,20));
		window.draw(board);
		window.draw(ui);
		window.display();
	}
	return 0;
}
