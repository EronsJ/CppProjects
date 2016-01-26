/*
 * FamilyType.cpp
 *
 *  Created on: May 14, 2015
 *      Author: Erons J
 */

#include "FamilyType.h"
#include <random>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::ofstream;
using std::ifstream;

							/*Member Function */
/*Virtual Functions*/
bool FamilyType::storerelationship(){
	cout << "We are Family" << endl;
	return (Relationshipprofile::storerelationship());

}

void FamilyType::inputinfo(){
	cout << "We are Family" << endl;

	cout << "\nThis is really FUN" << endl;
	cout
			<< "*****************************************************************************************"
			<< endl;
	cout << "When placing " << getType()
			<< "'s data place the information type then the information"
			<< endl;
	cout
			<< "Enter \'end\' in each field if you do not want to enter anymore information"
			<< endl;
	cout
			<< "*****************************************************************************************"
			<< endl;
	std::string key;
	std::string value;

	bool done = false;
	do {
		cout << "What type of information do you want to enter: " << flush;
		while (!getline(cin, key)){ cin.clear(); cin.ignore(); break;}
		cout << "What is the information: " << flush;
		while (!getline(cin, value)){ cin.clear(); cin.ignore(); break;}
		cout
				<< "---------------------------------------------------------------------------------------"
				<< endl;
		if (key == "end" and value == "end")
			done = true;
		else
			this->info[key] = value; //Using Containers Maps
	} while (!done);

	cout << "\nAwesome! We are done Entering " << getName() << " info" << endl;

}

std::string FamilyType::getType()const{
	return Typeinfo;
}


FamilyType::FamilyType() {
	this->Typeinfo = "Family";
	cout << endl;
}


FamilyType::FamilyType(const std::string &newname): Relationshipprofile(newname){
	this->Typeinfo = "Family";
}

FamilyType::~FamilyType(){

}
