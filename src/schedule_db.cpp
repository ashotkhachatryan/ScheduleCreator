#include "schedule_db.h"

ScheduleDb* ScheduleDb::m_instance = nullptr;

ScheduleDb::ScheduleDb()
{
}

ScheduleDb*
ScheduleDb::GetInstance()
{
	if (m_instance == nullptr) {
		m_instance = new ScheduleDb();
	}
	return m_instance;
}

/**
 * The function initializes schedule data.      
 * For now all data will be defined inside function,
 * but then datas should be taken from file.
 */
void
ScheduleDb::Initialize()
{
	ClassroomInitialize();
	LectureInitialize();
	TeacherInitialize();
	SetRelation();
}

void
ScheduleDb::ClassroomInitialize()
{
	m_classrooms.push_back(new Classroom("X", 		0));
	m_classrooms.push_back(new Classroom("IX", 		1));
	m_classrooms.push_back(new Classroom("VIII", 	2));
	m_classrooms.push_back(new Classroom("VII", 	3));
	m_classrooms.push_back(new Classroom("VI", 		4));
}

void
ScheduleDb::LectureInitialize()
{
  m_lectures.push_back(new Lecture("Հայոց Լեզու", 0));
  m_lectures.push_back(new Lecture("Ֆիզիկա", 1));
  m_lectures.push_back(new Lecture("Մաթեմատիկա", 2));
  m_lectures.push_back(new Lecture("Կենսաբանություն", 3));
  m_lectures.push_back(new Lecture("Աշխարհագրություն", 4));
  m_lectures.push_back(new Lecture("Պատմություն", 5));
  m_lectures.push_back(new Lecture("Ֆիզկուլտուրա", 6));
  m_lectures.push_back(new Lecture("Գրականություն", 7));
  m_lectures.push_back(new Lecture("Ռուսաց լեզու", 8));
	m_lectures.push_back(new Lecture("Անգլերեն", 9));

}

void
ScheduleDb::TeacherInitialize()
{
  m_teachers.push_back(new Teacher("Կիրակոսյան", 0));
  m_teachers.push_back(new Teacher("Մարտիրոսյան", 1));
  m_teachers.push_back(new Teacher("Համբարձումյան", 2));
  m_teachers.push_back(new Teacher("Մարգարյան", 3));
	m_teachers.push_back(new Teacher("Հովհաննիսյան", 4));
  m_teachers.push_back(new Teacher("Զաքարյան", 5));
  m_teachers.push_back(new Teacher("Գրիգորյան", 6));
  m_teachers.push_back(new Teacher("Պողոսյան", 7));
  m_teachers.push_back(new Teacher("Սիմոնյան", 8));
  m_teachers.push_back(new Teacher("Վիրաբյան", 9));
}

void
ScheduleDb::SetRelation()
{
  m_teachers[0]->SetClassrooms({{m_classrooms[0], 6}, 
																{m_classrooms[1], 3}, 
																{m_classrooms[2], 5}, 
																{m_classrooms[4], 1}});
  m_teachers[0]->SetLectures({{m_lectures[0], 15}});

  m_teachers[1]->SetClassrooms({{m_classrooms[0], 3}, 
																{m_classrooms[2], 2}, 
																{m_classrooms[1], 5}});
  m_teachers[1]->SetLectures({{m_lectures[1], 10}});

  m_teachers[2]->SetClassrooms({{m_classrooms[2], 6}, 
																{m_classrooms[1], 4}, 
																{m_classrooms[3], 5}, 
																{m_classrooms[4], 3}});
  m_teachers[2]->SetLectures({{m_lectures[2], 18}});

  m_teachers[3]->SetClassrooms({{m_classrooms[0], 3}, 
																{m_classrooms[4], 4}});
  m_teachers[3]->SetLectures({{m_lectures[3], 7}});

  m_teachers[4]->SetClassrooms({{m_classrooms[2], 4}, 
														{m_classrooms[1], 5}, 
														{m_classrooms[3], 5}});
  m_teachers[4]->SetLectures({{m_lectures[4], 14}});

  m_teachers[5]->SetClassrooms({{m_classrooms[3], 6}, 
														{m_classrooms[4], 4}, 
														{m_classrooms[0], 3}, 
														{m_classrooms[2], 5}});
  m_teachers[5]->SetLectures({{m_lectures[5], 18}});

  m_teachers[6]->SetClassrooms({{m_classrooms[0], 3}, 
														{m_classrooms[4], 4}, 
														{m_classrooms[1], 6}});
  m_teachers[6]->SetLectures({{m_lectures[6], 13}});

  m_teachers[7]->SetClassrooms({{m_classrooms[0], 2}, 
														{m_classrooms[3], 4}});
  m_teachers[7]->SetLectures({{m_lectures[7], 6}});

  m_teachers[8]->SetClassrooms({{m_classrooms[4], 6}, 
														{m_classrooms[3], 3}, 
														{m_classrooms[0], 5}});
  m_teachers[8]->SetLectures({{m_lectures[8], 14}});

  m_teachers[9]->SetClassrooms({{m_classrooms[4], 5}, 
														{m_classrooms[3], 5}});
  m_teachers[9]->SetLectures({{m_lectures[9], 10}});
}
