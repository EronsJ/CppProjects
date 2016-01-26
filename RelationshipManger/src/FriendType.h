/*
 * FriendType.h
 *
 *  Created on: May 13, 2015
 *      Author: Erons J
 */

#ifndef FRIENDTYPE_H_
#define FRIENDTYPE_H_

#include "Relationshipprofile.h"


/* INHERITANCE AND CLASESS (Concrete)*/
class FriendType: public Relationshipprofile {
public:
	explicit FriendType();
	explicit FriendType(const std::string &);
	virtual ~FriendType();
	void greetings();
	virtual std::string getType()const override;
	virtual bool storerelationship() override;
	virtual void inputinfo() override;

};

#endif /* FRIENDTYPE_H_ */
