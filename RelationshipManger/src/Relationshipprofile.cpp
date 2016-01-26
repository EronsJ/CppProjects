/*
 * Relationshipprofile.cpp
 *
 *  Created on: May 13, 2015
 *      Author: Erons J
 */

#include "Relationshipprofile.h"
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;

std::default_random_engine engine1(static_cast<unsigned int>(time(0)));
std::uniform_int_distribution<unsigned int> randomInt1(1, 5);

std::ostream &operator<<(std::ostream &output,  Relationshipprofile *per){
	cout <<"Number of information entered: " << per->info.size() << endl;

	output << "************************************************" << endl;
	output << "You are viewing " << per->getName() << "'s profile" << endl;
	output << "************************************************" << endl;

	for (auto element : per->info) {
		output << "Field: " << element.first << '\n' << "Value: "
				<< element.second << '\n';
	}
	output << "************************************************" << endl;
	return output;

}
							/*Non-member Function*/
						/*Operator Overloading*/
/*USES DATA STRUCTURE QUEUE BASED ON LINKED LIST*/
std::istream &operator>>(std::istream &input, Relationshipprofile *fri){
	std::string name,type, dummy, size, result;
	getline(input, name);
	getline(input, size);

	fri->readinfo.push(type);
	fri->readinfo.push(name);
	fri->readinfo.push(size);

	while( !input.eof()){
		input >> dummy;
		input.ignore();
		getline(input, result);
		fri->readinfo.push(result);
	}

	return input;
}


						/*Member Function*/
/*USES DATA STRUCTURE*/

void Relationshipprofile::displayinputFile(){

	readinfo.front(); readinfo.pop();
	cout << "****************************************************" <<endl;
	cout << "Name: "<< readinfo.front()<< endl; readinfo.pop();
	cout << "Number of information: " << readinfo.front() << endl; readinfo.pop();
	cout << "****************************************************" <<endl;
	cout << "****************************************************" <<endl;
	cout <<left<<setw(30)<< "Fields" <<setw(30)<<left<< "Value" <<endl;

	short i = 0;
	while(!readinfo.empty()){
		if (i == 0){
			cout <<left<<setw(30) <<readinfo.front() <<":"<<flush;
			readinfo.pop();
			i = 1;
		}
		else{
			cout <<left<<setw(30)<< readinfo.front() << endl;
			readinfo.pop();
			i = 0;
		}
		if (readinfo.size() <= 1) break;
	}
}

bool Relationshipprofile::storerelationship() {
	std::string Filename = getName() + ".contact";
	cout << "Storing " << getName() << " info in a file called " << Filename
			<< endl;

	ofstream outFile(Filename);

	if (!outFile) {
		cout << "Cannot write to file :(" << endl;
		return false;
	}
	outFile << getType()<< "Type" <<'\n';
	outFile << getName() << '\n';
	outFile << info.size() << '\n';
	for (auto item : info) {
		outFile << "Field " << item.first << "\n" <<"Value " << item.second	<< '\n';
	}

	cout << getName() << " has been stored" << endl;

	return true;
}

void Relationshipprofile::setName(){
	string name;
	while (!getline(cin, name)){ cin.clear(); cin.ignore();}
	if (name == " "){
	cout << "I'm sorry I messed the name up"<<endl;
	cout << "Please spell it out for me: " <<endl;
	this->m_name = name;
	}
	else
		this->m_name = name;
}


string Relationshipprofile::getName() const{
	return m_name;
}


Relationshipprofile::Relationshipprofile(const std::string &newname ): m_name(newname == " "? " " : newname ){
	if(newname == " "){
		do{
			setName();
		}while(newname == " ");
		cout << "Thank you"<< endl;
	}
}

std::string Relationshipprofile::greetings(){
		switch (randomInt1(engine1)) {
		case 1:
			return "That's such a beautiful name\n";
		case 2:
			return "I am going to learn how to pronounce it\n";
		case 3:
			return "Is that native to where you are originally from\n";
		case 4:
			return "Interesting Name\n";
		case 5:
			return "I am never going to forget that\n";
		default:
			return "";
		}
}

Relationshipprofile::Relationshipprofile(){

}

Relationshipprofile::~Relationshipprofile() {

}

