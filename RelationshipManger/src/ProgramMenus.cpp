/*
 * ProgramMenus.cpp
 *
 *  Created on: Jan 14, 2016
 *      Author: Erons J
 */

#include "ProgramMenus.h"
#include <iostream>
#include <sstream>

namespace emo {

ProgramMenus::ProgramMenus() :
		userinputstr(""), userinputnum(0), condition(0) {
	std::cout << "*******************************************************"
			<< std::endl;
	std::cout << "                WELCOME TO RELATIONSHIP MANAGER          "
			<< std::endl;
	std::cout << "*******************************************************"
			<< std::endl;

}

ProgramMenus::~ProgramMenus() {
	// TODO Auto-generated destructor stub
}

bool ProgramMenus::conditionOptions() {
	switch (condition) {
	case 0:
		if ((userinputnum != -1 and userinputnum != 1)) {
			std::cout << "\nSelect a valid option" << '\n' << std::endl;
			std::cout << "What will you like to do [1(Menu)|-1(Quit)]: "
					<< std::flush;
			return true;
		}
		return false;
	case 1:
		if ((userinputnum == 1 or userinputnum == 2)) {
			std::cout << "Awesome" << std::endl;
			return false;
		} else if (userinputnum == 3) {
			std::cout << "Bye Bye!!!" << std::endl;
			return false;
		} else {
			std::cout << "\nSelect a valid option" << '\n' << std::endl;
			std::cout
					<< "What will you like to do [1(ADD NEW RELATIONSHIP)|2(READ RELATIONSHIP FILE)|3(QUIT)]: "
					<< std::flush;
			return true;
		}

	case 2:
		if ((userinputnum != 1 and userinputnum != 2 and userinputnum != 3)) {
			std::cout
					<< "Invalid Input! What kind of relationship will you like to have: "
					<< std::flush;
			return true;
		}
		std::cout << "\nNice one " << std::endl;
		return false;

	case 3:
		if ((userinputstr == "s" or userinputstr == "v" or userinputstr == "e")) {
			return false;
		}
		return true;

	}
	return true;
}
void ProgramMenus::setCondition() {
	condition++;
}
std::string ProgramMenus::getcurrentinputstr() {
	return userinputstr;
}


std::string ProgramMenus::relationshipAddModeMenu(Relationshipprofile *selectptr){
	return  (std::string)"\n*********************************************************************\n"
			+  (std::string)"                            ADD MODE OPTIONS                         \n"
	        + "*********************************************************************\n"
			+ "----------------------------------------------------------------------\n"
			+ "NOTE IF YOU DO NOT STORE " + selectptr->getName()
			+ "'s profile all the information will be LOST!!!!!!!!!\n"
			+ "-----------------------------------------------------------------------\n"
			+"store(s) " + selectptr->getName() + "'s profile"
			+ "\nview(v) " + selectptr->getName() + "'s profile"
			+ "\nend(e) add mode\n"
			+ "**********************************************************************\n"
			+ "What will  you like to: ";

}
short ProgramMenus::getCurrentInputNum() {
	return userinputnum;
}
bool ProgramMenus::getUserInput() {
	bool value;
	do {
		getline(std::cin, userinputstr); //Gets users input from menu
		std::stringstream stream(userinputstr);
		stream >> userinputnum;
		value = conditionOptions();
	} while (value);
	return (!value);
}

std::string ProgramMenus::relationshipTypeMenu() {
	condition = 2;
	return (std::string)"*******************************************************" + '\n'
			+ (std::string) "             RELATIONSHIP TYPES		        		" + '\n'
			+ "*******************************************************" + '\n'
			+ "1: Friend" + '\n' + "2: Family" + '\n' + "3: QUIT" + '\n' + '\n'
			+ "Please Select a valid option" + '\n'
			+ "What kind of relationship will you like to have: ";
}

std::string ProgramMenus::relationshipMainMenu() {
	condition = 0;
	return (std::string) "Press 1 to go to the menu or -1 to exit" + '\n'
			+ (std::string) "*******************************************************"
			+ '\n' + " 1: MENU" + '\n' + "-1: EXIT" + '\n'
			+ "*******************************************************" + '\n'
			+ "Please Select a valid option" + '\n'
			+ "What will you like to do: ";
}

std::string ProgramMenus::relationshipMenu() {
	condition = 1;
	return (std::string) "*******************************************************"
			+ '\n'
			+ (std::string) "               RELATIONSHIP MANAGER MENU		        "
			+ '\n' + "*******************************************************"
			+ '\n' + "1: ADD NEW RELATIONSHIP" + '\n'
			+ "2: READ RELATIONSHIP FILE" + '\n' + "3: QUIT" + '\n'
			+ "*******************************************************" + '\n'
			+ "Please Select a valid option" + '\n'
			+ "What will you like to do: ";
}

} /* namespace emo */
