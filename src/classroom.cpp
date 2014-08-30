#include "classroom.h"

Classroom::Classroom(std::string pName, int pId)
	: m_name(pName)
	, m_id(pId)
{
}

int
Classroom::GetId() const
{
	return m_id;
}

std::string
Classroom::GetName() const
{
	return m_name;
}
