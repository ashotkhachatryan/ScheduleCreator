#include "hour_info.h"

HourInfo::HourInfo(const Teacher* pTeacher, const Classroom* pClassroom, const Lecture* pLecture)
	: m_teacher(pTeacher)
	, m_classroom(pClassroom)
	, m_lecture(pLecture)
{
}
