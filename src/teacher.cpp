#include "teacher.h"

TeacherEmployment::TeacherEmployment(Classroom* pClassroom, Lecture* pLecture, int pCount)
	: m_classroom(pClassroom)
	, m_lecture(pLecture)
	, m_count(pCount)
{
}

int
TeacherEmployment::GetCount() const
{
	return m_count;
}

const Classroom* 
TeacherEmployment::GetClassroom() const
{
	return m_classroom;
}

const Lecture* 
TeacherEmployment::GetLecture() const
{
	return m_lecture;
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

std::vector<TeacherEmployment*>
Teacher::GetTeacherEmployment() const
{
	return m_teacherEmployment;
}

std::string
Teacher::GetName() const
{
	return m_name;
}
