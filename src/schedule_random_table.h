#ifndef SCHEDULE_RANDOM_TABLE_H
#define SCHEDULE_RANDOM_TABLE_H

#include <vector>
#include "schedule_entry.h"

class ScheduleRandomTable
{
public:
	ScheduleRandomTable(int pId);
	void Initialize();
	ScheduleEntry operator() (int pIndex1, int pIndex2, int pIndex3);
	std::vector<std::vector<std::vector<ScheduleEntry>>> GetScheduleEntryArray() const;
	void SetScheduleEntryArray(std::vector<std::vector<std::vector<ScheduleEntry>>> pScheduleEntryArray)
	{ ScheduleEntryRandomArray = pScheduleEntryArray; }
	int GetId() { return m_id; }
private:
	int m_id;
	std::vector<int> GetRandomNumbers(int pMin, int pMax) const;
	std::vector<std::vector<std::vector<ScheduleEntry>>> ScheduleEntryRandomArray;
	std::vector<std::vector<ScheduleEntry>> GetRandomizedClassroomTable(std::vector<std::vector<ScheduleEntry>> lClassroomEntry);
};

#endif
