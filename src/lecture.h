#ifndef LECTURE_H
#define LECTURE_H

#include <string>

class Lecture
{
public:
	Lecture(std::string pName, int pId);
	std::string GetName() const;
private:
	std::string m_name;
	int m_id;
};

#endif 
