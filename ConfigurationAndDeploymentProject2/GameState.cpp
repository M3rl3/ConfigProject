#include <pugixml/pugixml.hpp>
#include <iostream>
#include <vector>

#include "GameState.h"

void GameState::SaveState(char arr[][3]) {
	
	pugi::xml_document doc;
	if (!doc.load_file(filePath.c_str())) return;

	std::cout << "\nLoaded xml file." << std::endl;
	pugi::xml_object_range<pugi::xml_node_iterator> gameState = doc.child("gamestate").children();

	if (doc.empty()) {
		std::cerr << "Error: saved state is missing or does not exist.";
	}

	int index = 0;
	pugi::xml_node_iterator arrayIt;
	for (arrayIt = gameState.begin(); arrayIt != gameState.end(); arrayIt++) {
		pugi::xml_node arrayNode = *arrayIt;

		pugi::xml_attribute location = arrayNode.attribute("location");
		//std::cout << "\nLocation: " << location.value();
		pugi::xml_node_iterator locationIt;
		for (locationIt = arrayNode.children().begin(); locationIt != arrayNode.children().end(); locationIt++) {
			pugi::xml_node valueNode = *locationIt;

			//std::cout << "\n" << valueNode.name() << ": " << valueNode.child_value();

			pugi::char_t* value = new pugi::char_t[2];
			
			value[0] = arr[index / 3][index % 3];
			value[1] = '\0';
			valueNode.first_child().set_value(value);

			int test = 0;
		}
		index++;
	}
	doc.save_file("gamestate.xml");
	std::cout << "Saved current game state to file " << filePath << std::endl;
}

void GameState::LoadState(char arr[][3]) {
	
	pugi::xml_document doc;                 
	if (!doc.load_file(filePath.c_str())) return;

	std::cout << "\nLoading xml file " << filePath << "\n";
	pugi::xml_object_range<pugi::xml_node_iterator> gameState = doc.child("gamestate").children();

	if (doc.empty()) {
		std::cerr << "Error: saved state is missing or does not exist.";
	}
	std::vector<const pugi::char_t*> values;

	int index = 0;
	pugi::xml_node_iterator arrayIt;
	for (arrayIt = gameState.begin(); arrayIt != gameState.end(); arrayIt++) {
		pugi::xml_node arrayNode = *arrayIt;
		
		pugi::xml_attribute location = arrayNode.attribute("location");
		//std::cout << "\nLocation: " << location.value();

		pugi::xml_node_iterator locationIt;
		for (locationIt = arrayNode.children().begin(); locationIt != arrayNode.children().end(); locationIt++) {
			pugi::xml_node valueNode = *locationIt;
			
			//std::cout << "\n" << valueNode.name() << ": " << valueNode.child_value();
			
			const pugi::char_t* value = new pugi::char_t[2];
			value = valueNode.child_value();
			
			arr[index / 3][index % 3] = value[0];
		}
		index++;
	}
	std::cout << "Load Successful.";
}