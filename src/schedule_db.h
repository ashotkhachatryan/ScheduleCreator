#ifndef SCHEDULE_DB_H
#define SCHEDULE_DB_H

#include "teacher.h"
#include "classroom.h"
#include "lecture.h"
#include <vector>
#include <map>

class ScheduleDb
{
public:
	void Initialize();
	static ScheduleDb* GetInstance();
	int GetClassroomsCount() const;
	int GetTeachersCount() const;
	const std::vector<Teacher*> GetTeachers() const;
	const std::vector<Classroom*> GetClassrooms() const;
	const std::vector<Lecture*> GetLectures() const;
	static int DayCount;
	static int HourCount;
private:
	ScheduleDb();
private:
	std::vector<Teacher*> 	m_teachers;
	std::vector<Classroom*> m_classrooms;
	std::vector<Lecture*> 	m_lectures;
	static ScheduleDb* m_instance;
private:
	void TeacherInitialize();
	void ClassroomInitialize();
	void LectureInitialize();
	void SetRelation();
};

#endif
