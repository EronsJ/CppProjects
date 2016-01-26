/*
 * ProgramMenus.h
 *
 *  Created on: Jan 14, 2016
 *      Author: Erons J
 */

#ifndef PROGRAMMENUS_H_
#define PROGRAMMENUS_H_
#include "Relationshipprofile.h"
namespace emo {

class ProgramMenus {
private:
	std::string userinputstr;
	short userinputnum;
	short condition;
private:
	bool conditionOptions();
public:
	ProgramMenus();
	std::string relationshipTypeMenu();
	std::string relationshipMainMenu();
	std::string relationshipMenu();
	std::string relationshipAddModeMenu(Relationshipprofile*);
	bool getUserInput();
	std::string getcurrentinputstr();
	short getCurrentInputNum();
	void setCondition();
	virtual ~ProgramMenus();
};

} /* namespace emo */

#endif /* PROGRAMMENUS_H_ */
