#include "schedule_table.h"
#include "schedule_db.h"
#include <map>
#include <assert.h>
#include <iostream>

ScheduleTable* ScheduleTable::m_instance = nullptr;

ScheduleTable::ScheduleTable()
{
	ScheduleDb* lScheduleDb = ScheduleDb::GetInstance();
	assert(lScheduleDb != nullptr);

	ScheduleEntryArray.resize(lScheduleDb->GetClassroomsCount());
		for (int j = 0; j < lScheduleDb->GetClassroomsCount(); j++) {
			ScheduleEntryArray[j].resize(ScheduleDb::HourCount);
			for (int k = 0; k < ScheduleDb::HourCount; k++) {
				//ScheduleEntryArray[j][k].resize(ScheduleDb::DayCount);
			}
		}
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

std::vector<std::vector<ScheduleEntry>> 
ScheduleTable::operator() (int pIndex1)
{
	return ScheduleEntryArray[pIndex1];
}

std::vector<ScheduleEntry>
ScheduleTable::operator() (int pIndex1, int pIndex2)
{
	if (pIndex1 >= ScheduleEntryArray.size()) {
		throw 0;
	}
	if (pIndex2 >= ScheduleEntryArray[pIndex1].size()) {
		throw 0;
	}
	return ScheduleEntryArray[pIndex1][pIndex2];
}

ScheduleEntry
ScheduleTable::operator() (int pIndex1, int pIndex2, int pIndex3)
{
	if (pIndex1 >= ScheduleEntryArray.size()) {
		throw 0;
	}
	if (pIndex2 >= ScheduleEntryArray[pIndex1].size()) {
		throw 0;
	}
	if (pIndex3 >= ScheduleEntryArray[pIndex1][pIndex2].size()) {
		throw 0;
	}
	return ScheduleEntryArray[pIndex1][pIndex2][pIndex3];
}

int
ScheduleTable::GetLectureCountInClassroom(int pId, const Lecture* pLecture) const
{
	int lSum = 0;
	std::vector<std::vector<ScheduleEntry>> lClassroomTable = ScheduleEntryArray[pId];
	for (int i = 0; i < lClassroomTable.size(); i++) {
		for (int j = 0; j < lClassroomTable[i].size(); j++) {
			if (lClassroomTable[i][j].GetLecture() == pLecture) {
				lSum++;
			}
		}
	}
	return lSum;
}

int
ScheduleTable::GetEntryCountByClassroom(int pId) const 
{
	std::vector<std::vector<ScheduleEntry>> lClassroomTable = ScheduleEntryArray[pId];
	int lSum = 0;
	for (int i = 0; i < lClassroomTable.size(); i++) {
		lSum += lClassroomTable[i].size();
	}
	return lSum;
}

int
ScheduleTable::GetAllEntriesCount() const
{
	int lSum = 0;
	for (int i = 0; i < ScheduleEntryArray.size(); i++) {
		lSum += GetEntryCountByClassroom(i);
	}
	return lSum;
}

void
ScheduleTable::Initialize()
{
	ScheduleDb* lScheduleDb = ScheduleDb::GetInstance();	
	assert(lScheduleDb != nullptr);
	std::vector<Teacher*> lTeachers = lScheduleDb->GetTeachers();
	assert(lTeachers.size() != 0);

	int x[lScheduleDb->GetClassroomsCount()];
	for (int i = 0; i < lScheduleDb->GetClassroomsCount(); i++) {
		x[i] = 0;
	}

	for (int i = 0; i < lTeachers.size(); i++) {
		std::vector<TeacherEmployment*> lTeacherEmployment = lTeachers[i]->GetTeacherEmployment();
		for (int j = 0; j < lTeacherEmployment.size(); j++) {	
			for (int t = 0; t < lTeacherEmployment[j]->GetCount(); t++) {
				const Classroom* lClassroom = lTeacherEmployment[j]->GetClassroom();
				const Lecture* lLecture = lTeacherEmployment[j]->GetLecture();
				Teacher* lTeacher = lTeachers[i];
				int m = x[lClassroom->GetId()] / ScheduleDb::DayCount; 
				int n = x[lClassroom->GetId()] - (m * ScheduleDb::DayCount);
				ScheduleEntry lScheduleEntry(lTeacher, lClassroom, lLecture);
				ScheduleEntryArray[lClassroom->GetId()][m].push_back(lScheduleEntry);
				x[lClassroom->GetId()]++;
			}
		}
	}
}
