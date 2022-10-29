#include <pugixml/pugixml.hpp>
#include <iostream>
#include <vector>

#include "GameState.h"

void GameState::SaveState(char arr[][3]) {
	pugi::xml_document doc;
	if (!doc.load_file("gamestate.xml")) return;

	std::cout << "\nLoaded xml file\n";
	pugi::xml_object_range<pugi::xml_node_iterator> gameState = doc.child("gamestate").children();

	if (doc.empty()) {
		std::cerr << "Error: saved state is missing or does not exist.";
	}

	pugi::xml_node_iterator arrayIt;
	for (arrayIt = gameState.begin(); arrayIt != gameState.end(); arrayIt++) {
		pugi::xml_node arrayNode = *arrayIt;

		pugi::xml_attribute location = arrayNode.attribute("location");
		std::cout << "\nLocation: " << location.value();
		pugi::xml_node_iterator locationIt;
		for (locationIt = arrayNode.children().begin(); locationIt != arrayNode.children().end(); locationIt++) {
			pugi::xml_node valueNode = *locationIt;
			
			std::cout << "\n" << valueNode.name() << ": " << valueNode.child_value();
			
			
			if (valueNode.name() == "arr[0][0]") {
				valueNode.child("value").set_value((pugi::char_t*)arr[0][0]);
			}
		}
	}
	doc.save_file("gamestate.xml");
}

void GameState::LoadState(char arr[][3]) {
	pugi::xml_document doc;
	if (!doc.load_file("gamestate.xml")) return;

	std::cout << "\nLoaded xml file\n";
	pugi::xml_object_range<pugi::xml_node_iterator> gameState = doc.child("gamestate").children();

	if (doc.empty()) {
		std::cerr << "Error: saved state is missing or does not exist.";
	}
	std::vector<char*> values;

	pugi::xml_node_iterator arrayIt;
	for (arrayIt = gameState.begin(); arrayIt != gameState.end(); arrayIt++) {
		pugi::xml_node arrayNode = *arrayIt;
		
		pugi::xml_attribute location = arrayNode.attribute("location");
		std::cout << "\nLocation: " << location.value();

		pugi::xml_node_iterator locationIt;
		for (locationIt = arrayNode.children().begin(); locationIt != arrayNode.children().end(); locationIt++) {
			pugi::xml_node cellNode = *locationIt;
			
			std::cout << "\n" << cellNode.name() << ": " << cellNode.child_value();
			
			/*for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					arr[i][j] = (char)cellNode.child_value();
				}
			}*/
			
			char* yes = (char*)cellNode.child_value();
			values.push_back(yes);
			
			/*for (int i = 0; i < 9; i++) {
				array[i] = (char *)cellNode.child_value();
			}*/
		}
	}
	{
		arr[0][0] = (char)values[0];
		arr[0][1] = (char)values[1];
		arr[0][2] = (char)values[2];
		arr[1][0] = (char)values[3];
		arr[1][1] = (char)values[4];
		arr[1][2] = (char)values[5];
		arr[2][0] = (char)values[6];
		arr[2][1] = (char)values[7];
		arr[2][2] = (char)values[8];
		
		/*
		arr[0][0] = (char)array[0];
		arr[0][1] = (char)array[1];
		arr[0][2] = (char)array[2];
		arr[1][0] = (char)array[3];
		arr[1][1] = (char)array[4];
		arr[1][2] = (char)array[5];
		arr[2][0] = (char)array[6];
		arr[2][1] = (char)array[7];
		arr[2][2] = (char)array[8];
		*/
	}
	std::cout << "\n";
	for (int i = 0; i < values.size(); i++) {
		std::cout << values[i];
	}
}