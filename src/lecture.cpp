#include "lecture.h"

Lecture::Lecture(std::string pName, int pId)
	: m_name(pName)
	, m_id(pId)
{
}

std::string
Lecture::GetName() const
{
	return m_name;
}
