/*
 * RelationshipFeatures.h
 *
 *  Created on: Jan 20, 2016
 *      Author: Erons J
 */

#ifndef RELATIONSHIPFEATURES_H_
#define RELATIONSHIPFEATURES_H_

#include "Relationshipprofile.h"
#include "ProgramMenus.h"
namespace emo {

class RelationshipFeatures {
public:
	RelationshipFeatures(ProgramMenus &);
	void readrelationshipfile();
	void newRelationshipMode();
	void closerelationship();
	virtual ~RelationshipFeatures();
private:
	std::string displayGreetings();
	void readFileHelper(std::ifstream&);
private:
	ProgramMenus m_menu;
};

} /* namespace emo */

#endif /* RELATIONSHIPFEATURES_H_ */
