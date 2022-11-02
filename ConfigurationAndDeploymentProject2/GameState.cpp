#include <pugixml/pugixml.hpp>

#include <iostream>

#include "GameState.h"

void GameState::SaveState(char arr[][3]) {
	
	pugi::xml_document doc;
	if (!doc.load_file(filePath0.c_str())) return;

	if (value) {
		std::cout << "\nLoaded xml file " << filePath0 << std::endl;
	}
	else {
		std::cout << "\nFichier xml charge " << filePath0 << std::endl;
	}

	pugi::xml_object_range<pugi::xml_node_iterator> gameState = doc.child("gamestate").children();

	if (doc.empty()) return;

	int index = 0;
	pugi::xml_node_iterator arrayIt;

	for (arrayIt = gameState.begin(); arrayIt != gameState.end(); arrayIt++) {
		
		pugi::xml_node arrayNode = *arrayIt;
		pugi::xml_attribute location = arrayNode.attribute("location");

		//std::cout << "\nLocation: " << location.value();
		
		pugi::xml_node_iterator locationIt;

		for (locationIt = arrayNode.children().begin(); locationIt != arrayNode.children().end(); locationIt++) {
			
			pugi::xml_node valueNode = *locationIt;
			pugi::char_t* value = new pugi::char_t[2];
			
			//std::cout << "\n" << valueNode.name() << ": " << valueNode.child_value();

			value[0] = arr[index / 3][index % 3];
			value[1] = '\0';
			valueNode.first_child().set_value(value);

			int test = 0;
		}
		index++;
	}
	doc.save_file("gamestate.xml");
	if (value) {
		std::cout << "Saved current game state." << std::endl;
	}
	else {
		std::cout << "Etat du jeu actuel enregistre." << std::endl;
	}
}

void GameState::LoadState(char arr[][3]) {
	
	pugi::xml_document doc;                 
	if (!doc.load_file(filePath0.c_str())) return;

	if (value) {
		std::cout << "\nLoading xml file " << filePath0 << "\n";
	}
	else {
		std::cout << "\nChargement du fichier xml " << filePath0 << "\n";
	}
	
	pugi::xml_object_range<pugi::xml_node_iterator> gameState = doc.child("gamestate").children();

	if (doc.empty()) return;

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
	if (value) {
		std::cout << "Load Successful." << std::endl;
	}
	else {
		std::cout << "Chargement reussi." << std::endl;
	}
}

void GameState::GameLocale() {

	system("CLS");
	pugi::xml_document doc;
	if (!doc.load_file(filePath1.c_str())) return;
	pugi::xml_object_range<pugi::xml_node_iterator> locale = doc.child("locale").children();

	if (doc.empty()) return;

	pugi::xml_node_iterator languageIt;
	std::string text0, text1, text2, text3, text4, text5, text6;
	value = !value;

	for (languageIt = locale.begin(); languageIt != locale.end(); languageIt++) {
		pugi::xml_node languageNode = *languageIt;

		if (languageNode.attribute("value0") && value == true) {
			std::cout << "\n\tCurrent language: " << languageNode.first_attribute().as_string() << std::endl;
			text0 = languageNode.child("text0").child_value();
			text1 = languageNode.child("text1").child_value();
			text2 = languageNode.child("text2").child_value();
			text3 = languageNode.child("text3").child_value();
			text4 = languageNode.child("text4").child_value();
			text5 = languageNode.child("text5").child_value();
			text6 = languageNode.child("text6").child_value();
		}

		else if (languageNode.attribute("value1") && value == false) {
			std::cout << "\n\tLangue courante: " << languageNode.last_attribute().as_string() << std::endl;
			text0 = languageNode.child("text0").child_value();
			text1 = languageNode.child("text1").child_value();
			text2 = languageNode.child("text2").child_value();
			text3 = languageNode.child("text3").child_value();
			text4 = languageNode.child("text4").child_value();
			text5 = languageNode.child("text5").child_value();
			text6 = languageNode.child("text6").child_value();
		}
	}

	std::cout << "\n\t" << text0 << "\n";
	std::cout << "\n\t" << text1;
	std::cout << "\n\t" << text2;
	std::cout << "\n\t" << text3;
	std::cout << "\n\t" << text4 << std::endl;
	std::cout << "\n" << text5 << std::endl;
	std::cout << "\n" << text6 << std::endl;
}