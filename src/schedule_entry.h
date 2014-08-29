#ifndef SCHEDULE_ENTRY_H
#define SCHEDULE_ENTRY_H

#include "teacher.h"
#include "classroom.h"
#include "lecture.h"

class ScheduleEntry
{
public:
	ScheduleEntry();
	ScheduleEntry(const Teacher* pTeacher, const Classroom* pClassroom, const Lecture* pLecture);
private:
	const Teacher* 		m_teacher;
	const Classroom* 	m_classroom;
	const Lecture* 		m_lecture;
};

#endif
