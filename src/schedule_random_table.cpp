#include "schedule_random_table.h"
#include "schedule_db.h"
#include "schedule_table.h"
#include <algorithm>

ScheduleRandomTable::ScheduleRandomTable(int pId)
	: m_id(pId)
{
	Initialize();
}

std::vector<std::vector<std::vector<ScheduleEntry>>>
ScheduleRandomTable::GetScheduleEntryArray() const
{
	return ScheduleEntryRandomArray;
}

std::vector<int>
ScheduleRandomTable::GetRandomNumbers(int pMin, int pMax) const
{
  std::vector<int> lVector;
  for (int i = pMin; i <= pMax; i++) {
    int lRandom;
    while(true) {
      lRandom = pMin + rand() % ((pMax - pMin) + 1);
      if (std::find(lVector.begin(), lVector.end(), lRandom) == lVector.end()) {
        break;
      }
    }
    lVector.push_back(lRandom);
  }
  return lVector;
}

std::vector<std::vector<ScheduleEntry>>
ScheduleRandomTable::GetRandomizedClassroomTable(std::vector<std::vector<ScheduleEntry>> lClassroomTable)
{
	int lSum = 0;
	for (int i = 0; i < lClassroomTable.size(); i++) {
		lSum += lClassroomTable[i].size();
	}
	std::vector<int> lRandomNumbers = GetRandomNumbers(0, lSum - 1);
	for (int i = 0; i < lRandomNumbers.size(); i++) {
		int m1 = i / ScheduleDb::DayCount; 
		int n1 = i - (m1 * ScheduleDb::DayCount);

		int m2 = lRandomNumbers[i] / ScheduleDb::DayCount; 
		int n2 = lRandomNumbers[i] - (m2 * ScheduleDb::DayCount);

		std::swap(lClassroomTable[m1][n1], lClassroomTable[m2][n2]);
	}
	return lClassroomTable;
}

void
ScheduleRandomTable::Initialize()
{
	ScheduleDb* lScheduleDb = ScheduleDb::GetInstance();
	ScheduleTable* lScheduleTable = ScheduleTable::GetInstance();

	for (int i = 0; i < lScheduleDb->GetClassroomsCount(); i++) {
		lScheduleTable->GetEntryCountByClassroom(i);
		std::vector<std::vector<ScheduleEntry>> lScheduleEntry = GetRandomizedClassroomTable((*lScheduleTable)(i));
		ScheduleEntryRandomArray.push_back(lScheduleEntry);
	}
}

ScheduleEntry
ScheduleRandomTable::operator() (int pIndex1, int pIndex2, int pIndex3)
{
	if (pIndex1 >= ScheduleEntryRandomArray.size()) {
		throw 0;
	}
	if (pIndex2 >= ScheduleEntryRandomArray[pIndex1].size()) {
		throw 0;
	}
	if (pIndex3 >= ScheduleEntryRandomArray[pIndex1][pIndex2].size()) {
		throw 0;
	}
	return ScheduleEntryRandomArray[pIndex1][pIndex2][pIndex3];
}

