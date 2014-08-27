#ifndef TEACHER_H
#define TEACHER_H

#include "lecture.h"
#include "classroom.h"
#include <map>
#include <string>

class Teacher
{
public:
	Teacher(std::string pName, int pId);
	void SetLectures(const std::map<Lecture*, int>& pLecture);
	void SetClassrooms(const std::map<Classroom*, int>& pLecture);
private:
	std::string m_name;
	int m_id;
	std::map<Lecture*, int> 	m_lectures;
	std::map<Classroom*, int> m_classrooms;
};

#endif
