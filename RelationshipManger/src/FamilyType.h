/*
 * FamilyType.h
 *
 *  Created on: May 14, 2015
 *      Author: Erons J
 */

#ifndef FAMILYTYPE_H_
#define FAMILYTYPE_H_
#include "FriendType.h"

/* INHERITANCE AND CLASESS (Concrete)*/

class FamilyType: public Relationshipprofile {
public:
	explicit FamilyType();
	explicit FamilyType(const std::string &);
	virtual ~FamilyType();
	virtual std::string getType()const override;
	virtual bool storerelationship() override;
	virtual void inputinfo() override;
};
#endif /* FAMILYTYPE_H_ */
