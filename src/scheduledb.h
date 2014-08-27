#ifndef SCHEDULEDB_H
#define SCHEDULEDB_H

#include "teacher.h"
#include "classroom.h"
#include "lecture.h"
#include <vector>

class ScheduleDb
{
public:
	ScheduleDb();
	void Initialize();
private:
	std::vector<Teacher*> 	m_teachers;
	std::vector<Classroom*> m_classrooms;
	std::vector<Lecture*> 	m_lectures;
private:
	void TeacherInitialize();
	void ClassroomInitialize();
	void LectureInitialize();
	void SetRelation();
};

#endif
