#ifndef TEACHER_H
#define TEACHER_H

#include "lecture.h"
#include "classroom.h"
#include <vector>
#include <string>

struct TeacherEmployment
{
public:
	TeacherEmployment(Classroom* pClassroom, Lecture* pLecture, int pCount);
private:
	Classroom* m_classroom;
	Lecture* m_lecture;
	int m_count;
};

class Teacher
{
public:
	Teacher(std::string pName, int pId);
	void SetTeacherEmployment(const std::vector<TeacherEmployment*> pTeacherEmployment);
private:
	std::string m_name;
	int m_id;
	std::vector<TeacherEmployment*> m_teacherEmployment;
};

#endif
