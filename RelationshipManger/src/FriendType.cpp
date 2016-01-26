/*
 * FriendType.cpp
 *
 *  Created on: May 13, 2015
 *      Author: Erons J
 */

#include "FriendType.h"

#include <iostream>
#include <iomanip>


using std::cout;
using std::cin;
using std::endl;
using std::flush;
using std::ofstream;
using std::ifstream;



					/*Member Function */
FriendType::FriendType(){
	this->Typeinfo = "Friends";
	cout << endl;
}


FriendType::FriendType(const std::string &newname):
		Relationshipprofile(newname){
	this->Typeinfo = "Friends";

}




FriendType::~FriendType() {
}


					/*Virtual Functions*/
std::string FriendType::getType()const{
	return Typeinfo;
}


						/*USES STANDARD LIBRARY CONTAINERS*/
						/*FILE PROCESSING: WRITING TO A FILE*/
void FriendType::inputinfo() {
	cout << Relationshipprofile::greetings() << endl;
	cout << "\nThis is really FUN" << endl;
	cout
			<< "***********************************************************"
			<< endl;
	cout    << "When placing "<< getType()<<"'s data place the information type then the information"
			<< endl;
	cout    << "Enter \'end\' in each field if you do not want to enter anymore information"
			<< endl;
	cout    << "********************************************************************"
			<< endl;
	std::string key;
	std::string value;

	bool done = false;
	do {
		cout << "What type of information do you want to enter: " << flush;
		while (!getline(cin, key)){ cin.clear(); cin.ignore(); break;}
		cout << "What is the information: " << flush;
		while (!getline(cin, value)){ cin.clear(); cin.ignore(); break;}
		cout << "---------------------------------------------------------------------------------------"<< endl;
		if (key == "end" and value == "end")
			done = true;
		else
			this->info[key] = value; //Using Containers Maps
	} while (!done);

	cout <<"Number of information entered: " << this->info.size() << endl;
	cout << "\nAwesome! We are done Entering " << getName() << " info" << endl;

}



bool FriendType::storerelationship() {
	cout << "Friends always make things more beautiful" << endl;
	return (Relationshipprofile::storerelationship());
}



