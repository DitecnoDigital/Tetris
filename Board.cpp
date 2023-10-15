#include "Board.hpp"

Board::Board(){
	memset(board,0,sizeof(board));
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 10; j++){
			boardShapes[i][j]=RectangleShape(Vector2f(20,20));
			boardShapes[i][j].setPosition(j*20,i*20);
			boardShapes[i][j].setFillColor(Color(50,50,50));
			boardShapes[i][j].setOutlineThickness(2);
			boardShapes[i][j].setOutlineColor(Color(0,0,0));
		}
	}
}

bool Board::InstallPart(){
	srand(time(NULL));
	indNewPart=rand()%7;
	
	vector<vector<bool>> part = parts.ConsultPart(indNewPart);
	
	int sz = (int)part.size();
	
	indY=0;
	indX=5-sz/2;
	
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			if(part[i][j]){
				if(board[i][j+indX]>0) return false;
				board[i][j+indX]=-1;
			}
		}
	}
	
	int color = 1+rand()%7;
	indColorNewPart=color;
	
	switch(color){
		case 1: newPartColor=Color(255,166,0);break;
		case 2: newPartColor=Color(245,152,245);break;
		case 3: newPartColor=Color(51,204,153);break;
		case 4: newPartColor=Color(255,110,110);break;
		case 5: newPartColor=Color(255,204,77);break;
		case 6: newPartColor=Color(166,166,255);break;
		case 7: newPartColor=Color(138,194,247);break;
	}
	return true;
}

bool Board::UpdateBoard(){
	bool limit = 0;
	int aux;
	
	if(timer>=limitTimer){
		aux=0;
		for(int i = 18; i>=0; i--){
			for(int j = 0; j < 10; j++){
				if(board[i][j]==-1){
					if(board[i+1][j]<=0) aux++;
				}
			}
		}
		
		if(aux==4){
			indY++;
			for(int i = 18; i>=0; i--){
				for(int j = 0; j < 10; j++){
					if(board[i][j]==-1){
						board[i][j]=0;
						board[i+1][j]=-1;
					}
				}
			}			
		}else{
			for(int i = 19; i>=0; i--){
				for(int j = 0; j < 10; j++){
					if(board[i][j]==-1) board[i][j]=indColorNewPart;
				}
			}
			limit = 1;	
		}
		
		timer=0;
	}
	
	timer++;
	return limit;
}

void Board::UpdateBoardColors(){
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 10; j++){
			switch(board[i][j]){
				case 0: boardShapes[i][j].setFillColor(Color(50,50,50));break;
				case 1: boardShapes[i][j].setFillColor(Color(255,166,0));break;
				case 2: boardShapes[i][j].setFillColor(Color(245,152,245));break;
				case 3: boardShapes[i][j].setFillColor(Color(51,204,153));break;
				case 4: boardShapes[i][j].setFillColor(Color(255,110,110));break;
				case 5: boardShapes[i][j].setFillColor(Color(255,204,77));break;
				case 6: boardShapes[i][j].setFillColor(Color(166,166,255));break;
				case 7: boardShapes[i][j].setFillColor(Color(138,194,247));break;
				default:
					boardShapes[i][j].setFillColor(newPartColor);
				break;
			}
		}
	}
}

void Board::UpdateLimitTimer(int l){
	limitTimer=l;
}

void Board::RotatePart(){
	parts.RotatePart(indNewPart);
	vector<vector<bool>> part = parts.ConsultPart(indNewPart);
	
	int sz = (int)part.size();
	
	for(int i = 0; i  < sz; i++){
		for(int j = 0; j < sz; j++){
			if(part[i][j]){
				if(indY+i<0||indY+i>=20||indX+j<0||indX+j>=10||board[indY+i][indX+j]>0){
					parts.DerotatePart(indNewPart);
					return;
				}
			}
		}
	}
	
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 10; j++){
			if(board[i][j]==-1) board[i][j]=0;
		}
	}
	
	for(int i = 0; i  < sz; i++){
		for(int j = 0; j < sz; j++){
			if(part[i][j]){
				board[i+indY][j+indX]=-1;
			}
		}
	}
}

void Board::Right(){
	int aux = 0;
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 9; j++){
			if(board[i][j]==-1){
				if(board[i][j+1]<=0){
					aux++;
				}
			}
		}
	}
	
	if(aux==4){
		indX++;
		for(int i = 0; i < 20; i++){
			for(int j = 9; j >=0; j--){
				if(board[i][j]==-1) board[i][j]=0,board[i][j+1]=-1; 
			}
		}
	}
}

void Board::Left(){
	int aux = 0;
	for(int i = 0; i < 20; i++){
		for(int j = 1; j < 10; j++){
			if(board[i][j]==-1){
				if(board[i][j-1]<=0){
					aux++;
				}
			}
		}
	}
	
	if(aux==4){
		indX--;
		for(int i = 0; i < 20; i++){
			for(int j = 0; j < 10; j++){
				if(board[i][j]==-1) board[i][j]=0,board[i][j-1]=-1; 
			}
		}
	}
}


int Board::CheckLine(){
	int aux=0,lines=0;
	
	for(int i = 19; i >=0; i--){
		aux=0;
		for(int j = 0; j < 10; j++){
			if(board[i][j]>0) aux++;
			if(lines>0) board[i+lines][j]=board[i][j],board[i][j]=0;
		}
		if(aux==10){
			for(int j = 0; j < 10; j++) board[i][j]=0;
			lines++;
		}
	}
	
	return lines;
}

void Board::ClearBoard(){
	memset(board,0,sizeof(board));
}

void Board::draw(RenderTarget &rt,RenderStates rs) const{
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 10; j++){
			rt.draw(boardShapes[i][j],rs);
		}
	}
}

