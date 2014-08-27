#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <string>

class Classroom 
{
public:
	Classroom(std::string pName, int pId);
private:
	std::string m_name;
	int m_id;
};

#endif
