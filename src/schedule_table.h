#ifndef SCHEDULE_TABLE_Y
#define SCHEDULE_TABLE_Y

#include "schedule_entry.h"

class ScheduleTable
{
public:
	ScheduleEntry operator() (int pIndex1, int pIndex2);
	static ScheduleTable* GetInstance();
private:
	ScheduleTable();
	void Initialize();
private:
	ScheduleEntry* ScheduleEntryArray[];
	static ScheduleTable* m_instance;
};

#endif
