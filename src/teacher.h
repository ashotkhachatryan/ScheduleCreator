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
	int GetCount() const;
	const Classroom* GetClassroom() const;
	const Lecture* GetLecture() const;
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
	std::vector<TeacherEmployment*> GetTeacherEmployment() const;
private:
	std::string m_name;
	int m_id;
	std::vector<TeacherEmployment*> m_teacherEmployment;
};

#endif
