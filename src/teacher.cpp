#include "teacher.h"

Teacher::Teacher(std::string pName, int pId)
	: m_name(pName)
	, m_id(pId)
{
}

void
Teacher::SetClassrooms(const std::map<Classroom*, int>& pClassrooms)
{
	m_classrooms = pClassrooms;
}

void
Teacher::SetLectures(const std::map<Lecture*, int>& pLectures)
{
	m_lectures = pLectures;
}
