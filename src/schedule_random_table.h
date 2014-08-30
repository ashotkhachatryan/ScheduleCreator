#ifndef SCHEDULE_RANDOM_TABLE_H
#define SCHEDULE_RANDOM_TABLE_H

#include <vector>
#include "schedule_entry.h"

class ScheduleRandomTable
{
public:
	ScheduleRandomTable();
	void Initialize();
	ScheduleEntry operator() (int pIndex1, int pIndex2, int pIndex3);
private:
	std::vector<int> GetRandomNumbers(int pMin, int pMax) const;
	std::vector<std::vector<std::vector<ScheduleEntry>>> ScheduleEntryRandomArray;
	std::vector<std::vector<ScheduleEntry>> GetRandomizedClassroomTable(std::vector<std::vector<ScheduleEntry>> lClassroomEntry);
};

#endif
