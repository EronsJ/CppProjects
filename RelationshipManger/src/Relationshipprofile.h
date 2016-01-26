/*
 * Relationshipprofile.h
 *
 *  Created on: May 13, 2015
 *      Author: Erons J
 */

#ifndef RELATIONSHIPPROFILE_H_
#define RELATIONSHIPPROFILE_H_
#include <queue>
#include <map>

class Relationshipprofile {
	friend std::istream &operator>>(std::istream &, Relationshipprofile *);
	friend std::ostream &operator<<(std::ostream &, Relationshipprofile *);
public:
	Relationshipprofile();
	Relationshipprofile(const std::string &);
	virtual ~Relationshipprofile();
	void setName();
	std::string greetings();
	std::string getName() const;
	void displayinputFile();
	virtual std::string getType()const = 0;
	virtual bool storerelationship();
	virtual void inputinfo() = 0;

private:
	std::string m_name;
	std::queue<std::string> readinfo;

protected:
	std::map <std::string, std::string > info;
	std::string Typeinfo;
};

#endif /* RELATIONSHIPPROFILE_H_ */
