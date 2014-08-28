#include "schedule_table.h"

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

HourInfo
ScheduleTable::operator() (int pIndex1, int pIndex2)
{
	return HourInfoArray[pIndex1][pIndex2];
}

void
ScheduleTable::Initialize()
{
}
