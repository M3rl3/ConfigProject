#pragma once

#include <vector>
#include <string>

class GameState {

	char* array[9];
	std::string filePath = "gamestate.xml";

public:
	void SaveState(char arr[][3]);
	void LoadState(char arr[][3]);
};