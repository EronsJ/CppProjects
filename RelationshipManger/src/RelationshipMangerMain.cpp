//============================================================================
// Name        : RelationshipManger.cpp
// Author      : Eronmonsele Omiyi
// Version     : 1.0
// Copyright   : Property of Eronmonsele Matthew Omiyi
// Description : A program that manages a person relationship Network by storing infromation about the person  in C++11, Ansi-style
//============================================================================

#include <iostream>
#include "ProgramMenus.h"
#include "RelationshipFeatures.h"

using namespace std;

int main() {
	emo::ProgramMenus menu;
	emo::RelationshipFeatures options(menu);

	/*	Welcome Message To User */
	cout << menu.relationshipMainMenu() << flush;

	bool runprogram = menu.getUserInput();

	cout << endl;

	/*Program Loop */
	while (runprogram) {
		cout << menu.relationshipMenu() << flush;
		runprogram = menu.getUserInput();

		/* ADD NEW RELATIONSHIP MODE*/
		if (menu.getCurrentInputNum() == 1) {
			options.newRelationshipMode(); //Create New relationship File
			continue;
		}

		/*READ RELATIONSHIP FILE MODE*/
		if (menu.getCurrentInputNum() == 2) {
			options.readrelationshipfile(); // Read from an exisiting relationship file
		}

		/*EXIT MODE*/
		if (menu.getCurrentInputNum() == 3) {
			break;
		}

	}

	/*Closing the program*/
	options.closerelationship();

	return 0;
}
