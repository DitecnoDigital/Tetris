#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <time.h>
#include "Parts.hpp"

using namespace sf;
using namespace std;

class Board : public Drawable {
	private:
		Parts parts;
		
		int indNewPart,indColorNewPart;
		Color newPartColor;
		
		int indX,indY;
		
		int timer=0;
		int limitTimer=30;
		
		int board[20][10];
		RectangleShape boardShapes[20][10];
	public:
		Board();
		bool InstallPart();
		bool UpdateBoard();
		void UpdateBoardColors();
		void UpdateLimitTimer(int l);
		void RotatePart();
		void Right();
		void Left();
		int CheckLine();
		void ClearBoard();
		virtual void draw(RenderTarget&,RenderStates) const;
};
