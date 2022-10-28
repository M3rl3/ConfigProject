#pragma once

class Game {
	char arr[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

	bool draw = false;
	int row, column;
	
public:	
	char turn;

	void printArray();
	void handleTurns();
	bool gameOver();
};
