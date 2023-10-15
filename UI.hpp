#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class UI : public Drawable{
	private:
		Font font;
		Text scoreTextTitle;
		Text scoreText;
		Text maxScoreTextTitle;
		Text maxScoreText;
		Text byText;
		Text gameOverText;
		Text newScoreText;
		bool newScore=0;
		bool gameOver=0;
	public:
		UI();
		void SetScore(int);
		void SetMaxScore(int);
		void GameOver();
		void NewScore();
		virtual void draw(RenderTarget&,RenderStates) const;
};
