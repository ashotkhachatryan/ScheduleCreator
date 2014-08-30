#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <string>

class Classroom 
{
public:
	Classroom(std::string pName, int pId);
	int GetId() const;
	std::string GetName() const;
private:
	std::string m_name;
	int m_id;
};

#endif
