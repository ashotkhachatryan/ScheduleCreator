#include "teacher.h"

TeacherEmployment::TeacherEmployment(Classroom* pClassroom, Lecture* pLecture, int pCount)
	: m_classroom(pClassroom)
	, m_lecture(pLecture)
	, m_count(pCount)
{
}

Teacher::Teacher(std::string pName, int pId)
	: m_name(pName)
	, m_id(pId)
{
}

void
Teacher::SetTeacherEmployment(const std::vector<TeacherEmployment*> pTeacherEmployment)
{
	m_teacherEmployment = pTeacherEmployment;
}
