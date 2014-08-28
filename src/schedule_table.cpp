#include "schedule_table.h"
#include "schedule_db.h"
#include <map>

ScheduleTable* ScheduleTable::m_instance = nullptr;

ScheduleTable::ScheduleTable()
{
	Initialize();
}

ScheduleTable*
ScheduleTable::GetInstance()
{
	if (m_instance == nullptr) {
		m_instance = new ScheduleTable();
	}	
	return m_instance;
}

ScheduleEntry
ScheduleTable::operator() (int pIndex1, int pIndex2)
{
	return ScheduleEntryArray[pIndex1][pIndex2];
}

void
ScheduleTable::Initialize()
{
	ScheduleDb* lScheduleDb = ScheduleDb::GetInstance();	
	int n = lScheduleDb->GetClassroomsCount();
	
	for (int i = 0; i < n; i++) {
		std::map<Teacher*, Lecture*> lTeacherLecture = 
		lScheduleDb->GetTeacherLectureMapByClassroom(lScheduleDb->GetClassrooms()[i]);
	}
}
