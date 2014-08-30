#ifndef SCHEDULE_TABLE_Y
#define SCHEDULE_TABLE_Y

#include "schedule_entry.h"

class ScheduleTable
{
public:
	std::vector<std::vector<ScheduleEntry>> operator() (int pIndex1);
	std::vector<ScheduleEntry> operator() (int pIndex1, int pIndex2);
	ScheduleEntry operator() (int pIndex1, int pIndex2, int pIndex3);
	static ScheduleTable* GetInstance();
	int GetEntryCountByClassroom(int pId);
private:
	ScheduleTable();
	void Initialize();
private:
	std::vector<std::vector<std::vector<ScheduleEntry>>> ScheduleEntryArray;
	static ScheduleTable* m_instance;
};

#endif
