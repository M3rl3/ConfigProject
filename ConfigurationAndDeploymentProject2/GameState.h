#pragma once

#include <string>

class GameState {

	char* array[9];

	std::string filePath0 = "gamestate.xml";
	std::string filePath1 = "locale.xml";

	bool value = true;

public:
	void SaveState(char arr[][3]);
	void LoadState(char arr[][3]);
	void GameLocale();
};