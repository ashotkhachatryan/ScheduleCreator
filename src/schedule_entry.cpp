#include "schedule_entry.h"

ScheduleEntry::ScheduleEntry(const Teacher* pTeacher, const Classroom* pClassroom, const Lecture* pLecture)
	: m_teacher(pTeacher)
	, m_classroom(pClassroom)
	, m_lecture(pLecture)
{
}

ScheduleEntry::ScheduleEntry()
{
}

const Teacher*
ScheduleEntry::GetTeacher() const
{
	return m_teacher;
}

const Classroom*
ScheduleEntry::GetClassroom() const
{
	return m_classroom;
}

const Lecture*
ScheduleEntry::GetLecture() const
{
	return m_lecture;
}
