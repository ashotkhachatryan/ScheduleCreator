#include "schedule_entry.h"

ScheduleEntry::ScheduleEntry(const Teacher* pTeacher, const Classroom* pClassroom, const Lecture* pLecture)
	: m_teacher(pTeacher)
	, m_classroom(pClassroom)
	, m_lecture(pLecture)
{
}
