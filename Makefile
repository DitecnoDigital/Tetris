all:
	g++ main.cpp Board.cpp Parts.cpp UI.cpp Sounds.cpp -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -o Game
