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
	m_teachers[0]->SetTeacherEmployment({
																			new TeacherEmployment(m_classrooms[0], m_lectures[0], 6), 
																			new TeacherEmployment(m_classrooms[1], m_lectures[0], 3), 
																			new TeacherEmployment(m_classrooms[2], m_lectures[0], 5), 
																			new TeacherEmployment(m_classrooms[4], m_lectures[0], 1), 
																			});

	m_teachers[1]->SetTeacherEmployment({
																			new TeacherEmployment(m_classrooms[0], m_lectures[1], 3), 
																			new TeacherEmployment(m_classrooms[2], m_lectures[1], 2), 
																			new TeacherEmployment(m_classrooms[1], m_lectures[1], 5), 
																			});

	m_teachers[2]->SetTeacherEmployment({
																			new TeacherEmployment(m_classrooms[2], m_lectures[2], 6), 
																			new TeacherEmployment(m_classrooms[1], m_lectures[2], 4), 
																			new TeacherEmployment(m_classrooms[3], m_lectures[2], 5), 
																			new TeacherEmployment(m_classrooms[4], m_lectures[2], 3), 
																			});

	m_teachers[3]->SetTeacherEmployment({
																			new TeacherEmployment(m_classrooms[0], m_lectures[3], 3), 
																			new TeacherEmployment(m_classrooms[4], m_lectures[3], 4), 
																			});

	m_teachers[4]->SetTeacherEmployment({
																			new TeacherEmployment(m_classrooms[2], m_lectures[4], 4), 
																			new TeacherEmployment(m_classrooms[1], m_lectures[4], 5), 
																			new TeacherEmployment(m_classrooms[3], m_lectures[4], 5), 
																			});

	m_teachers[5]->SetTeacherEmployment({
																			new TeacherEmployment(m_classrooms[3], m_lectures[5], 6), 
																			new TeacherEmployment(m_classrooms[4], m_lectures[5], 4), 
																			new TeacherEmployment(m_classrooms[0], m_lectures[5], 3), 
																			new TeacherEmployment(m_classrooms[2], m_lectures[5], 5), 
																			});

	m_teachers[6]->SetTeacherEmployment({
																			new TeacherEmployment(m_classrooms[0], m_lectures[6], 3), 
																			new TeacherEmployment(m_classrooms[4], m_lectures[6], 4), 
																			new TeacherEmployment(m_classrooms[1], m_lectures[6], 6), 
																			});

	m_teachers[7]->SetTeacherEmployment({
																			new TeacherEmployment(m_classrooms[0], m_lectures[7], 2), 
																			new TeacherEmployment(m_classrooms[3], m_lectures[7], 4), 
																			});

	m_teachers[8]->SetTeacherEmployment({
																			new TeacherEmployment(m_classrooms[4], m_lectures[8], 6), 
																			new TeacherEmployment(m_classrooms[3], m_lectures[8], 3), 
																			new TeacherEmployment(m_classrooms[0], m_lectures[8], 5), 
																			});

	m_teachers[9]->SetTeacherEmployment({
																			new TeacherEmployment(m_classrooms[4], m_lectures[9], 5), 
																			new TeacherEmployment(m_classrooms[3], m_lectures[9], 5), 
																			});
}
