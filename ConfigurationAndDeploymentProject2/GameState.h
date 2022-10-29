#pragma once
#include <vector>

class GameState {

	char* array[9];

public:
	void SaveState(char arr[][3]);
	void LoadState(char arr[][3]);
};