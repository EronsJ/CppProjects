/*
 * RelationshipFeatures.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: Erons J
 */

#include "RelationshipFeatures.h"
#include "FriendType.h"   //CHILD OF RELATIONSHIP PROFILE
#include "FamilyType.h"   //CHILD OF FRIEND TYPE
#include "ProgramMenus.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <random>
#include <vector>

std::default_random_engine engine(static_cast<unsigned int>(time(0)));
std::uniform_int_distribution<unsigned int> randomInt(1, 5);
namespace emo {

RelationshipFeatures::RelationshipFeatures(ProgramMenus & menu): m_menu(menu){
}

std::string RelationshipFeatures::displayGreetings() {
	switch (randomInt(engine)) {
	case 1:
		return "YAY!!!!!!!! We met a new person this is so Exciting";
	case 2:
		return "I'm so excited to build a relationship with you";
	case 3:
		return "I will never forget you my RM will make sure of that";
	case 4:
		return "Let's put this information down and plan the next fun thing";
	case 5:
		return "Another unique individual in my network :)";
	default:
		return "";
	}
}

void RelationshipFeatures::newRelationshipMode() {

	/* --------------------- Welcoming Message -------------------*/
	std::cout << displayGreetings() << std::endl;
	std::cout << std::endl;

	/*----------------------Prints the relationship menu -----------*/
	std::string input;
	short relationshipType;
	std::cout << m_menu.relationshipTypeMenu() << std::flush;

	m_menu.getUserInput();

	relationshipType = m_menu.getCurrentInputNum();

	if (relationshipType != 3) {
		displayGreetings();
		std::cout << std::endl;
		std::cout << "******************************************************"
				<< std::endl;
		std::cout << "Please give me a name: " << std::flush;

		std::string name;
		while (!getline(std::cin, name)) {
			std::cin.clear();
			std::cin.ignore();
			return;
		}
		std::cout << std::endl;
		std::cout << "******************************************************"
				<< std::endl;

		/* POLYMORPHISM */
		std::vector<Relationshipprofile *> RelationshipType { new FriendType(
				name), new FamilyType(name) };
		Relationshipprofile *selectptr;

		if (relationshipType == 1) {
			selectptr = RelationshipType[0];
		}

		if (relationshipType == 2) {
			selectptr = RelationshipType[1];
		}

		selectptr->inputinfo(); //Virtual Function
		m_menu.setCondition();
		std::string instruction;

		do {
			std::cout << m_menu.relationshipAddModeMenu(selectptr) << std::flush;
			m_menu.getUserInput();
			std::cout<< "******************************************************"
					<< std::endl;
			instruction = m_menu.getcurrentinputstr();
			if (instruction == "s")
				selectptr->storerelationship(); //Virtual Function
			else if (instruction == "v"){
				std::cout << selectptr; //operator overloading
			}
		} while (instruction != "e");

		delete selectptr;

	}
}

void RelationshipFeatures::readrelationshipfile() {
	std::string input;
	std::cout
			<< "What is the name of the relationship file you will like to read: "
			<< std::flush;
	while (!getline(std::cin, input)) {
		std::cin.clear();
		std::cin.ignore();
		return;
	}

	std::ifstream readFile(input, std::ios::in);

	if (!readFile) {
		do {
			std::cout << "Oh no :(!!!!" << std::endl;
			std::cout << "There is a problem reading this file." << std::endl;
			std::cout << "Check that the file exist in the program directory"
					<< std::endl;
			std::cout
					<< "If you have checked type the name of the file or type \'end\' to quit: "
					<< std::flush;

			while (!getline(std::cin, input)) {
				std::cin.clear();
				std::cin.ignore();
				return;
			}

			readFile.open(input, std::ios::in);

		} while (!readFile or input == "end");
	}
	readFileHelper(readFile);

	readFile.close();
	//Finish function
}

/*FILE PROCESSING: READING TO A FILE *//*POLYMORPHISM*/
void RelationshipFeatures::readFileHelper(std::ifstream& readFile) {
	FriendType friobject;
	FamilyType famobject;
	std::string type;
	getline(readFile, type);

	Relationshipprofile *genericptr;

	if (type == "FriendType")
		genericptr = &friobject;
	if (type == "FamilyType")
		genericptr = &famobject;

	readFile >> genericptr;

	std::cout << "*******************************************************"
			<< std::endl;
	std::cout << "The file has been read" << std::endl;
	std::cout << "displaying File..." << std::endl;
	std::cout << "*******************************************************"
			<< std::endl;
	std::cout << "///////////////////////////////////////////////////////"
			<< std::endl;
	genericptr->displayinputFile();
	std::cout << "///////////////////////////////////////////////////////"
			<< std::endl;
}

void RelationshipFeatures::closerelationship() {
	std::string input;
	std::cout << std::endl;
	std::cout << std::endl;
	short exit;
	std::cout << "*******************************************************"
			<< std::endl;
	std::cout << "Yayy!!!! You are done Using Relationship Manger(RM)"
			<< std::endl;
	std::cout << "*******************************************************"
			<< std::endl;
	std::cout << "Enter -1 to close the program: ";

	do {
		getline(std::cin, input);
		std::stringstream stream(input);
		if (!(stream >> exit) or input.length() != 2 or -1 != exit) {
			std::cout << "Entry Invalid! Enter -1 to close the program: ";
		}
	} while (-1 != exit);

	std::cout << "Bye!! Can't wait till you make a new relationship"
			<< std::endl;
}

RelationshipFeatures::~RelationshipFeatures() {
	// TODO Auto-generated destructor stub
}

} /* namespace emo */
