#ifndef HOUR_INFO_H
#define HOUR_INFO_H

#include "teacher.h"
#include "classroom.h"
#include "lecture.h"

class HourInfo
{
public:
	HourInfo(const Teacher* pTeacher, const Classroom* pClassroom, const Lecture* pLecture);
private:
	const Teacher* 		m_teacher;
	const Classroom* 	m_classroom;
	const Lecture* 		m_lecture;
};

#endif
