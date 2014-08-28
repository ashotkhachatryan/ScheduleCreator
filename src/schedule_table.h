#ifndef SCHEDULE_TABLE_Y
#define SCHEDULE_TABLE_Y

#include "hour_info.h"

class ScheduleTable
{
public:
	HourInfo operator() (int pIndex1, int pIndex2);
	static ScheduleTable* GetInstance();
private:
	ScheduleTable();
	void Initialize();
private:
	HourInfo* HourInfoArray[];
	static ScheduleTable* m_instance;
};

#endif
