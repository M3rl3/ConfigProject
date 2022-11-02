#include <pugixml/pugixml.hpp>

#include <iostream>

#include "Game.h"

int main(int argc, char** argv) {
	
	std::string filePath0 = "locale.xml";

	pugi::xml_document doc;
	if (!doc.load_file(filePath0.c_str())) return 1;
	pugi::xml_object_range<pugi::xml_node_iterator> locale = doc.child("locale").children();
	if (doc.empty()) return 1;

	pugi::xml_node_iterator languageIt;
	std::string text0, text1, text2, text3, text4, text5, text6;

	for (languageIt = locale.begin(); languageIt != locale.end(); languageIt++) {
		pugi::xml_node languageNode = *languageIt;

		if (languageNode.attribute("value0")) {
			std::cout << "\n\tCurrent language: " << languageNode.first_attribute().as_string() << std::endl;
			text0 = languageNode.child("text0").child_value();
			text1 = languageNode.child("text1").child_value();
			text2 = languageNode.child("text2").child_value();
			text3 = languageNode.child("text3").child_value();
			text4 = languageNode.child("text4").child_value();
			text5 = languageNode.child("text5").child_value();
			text6 = languageNode.child("text6").child_value();
		}
	}

	Game game;

    std::cout << "\n\t" << text0 << "\n";
    std::cout << "\n\t" << text1;
    std::cout << "\n\t" << text2;
	std::cout << "\n\t" << text3;
    std::cout << "\n\t" << text4 << std::endl;
    std::cout << "\n" << text5 << std::endl;
	game.printArray();
    std::cout << "\n" << text6 << std::endl;

    game.turn = 'X';

    while (game.gameOver()) {
        game.handleTurns();
    }

    return 0;
}