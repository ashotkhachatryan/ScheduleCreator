#ifndef EVALUATION_H
#define EVALUATION_H

#include "schedule_random_table.h"

class Evaluation
{
public:
	Evaluation() {};
	Evaluation(const ScheduleRandomTable& pScheduleRandomTable);
	int GetEvaluation() { return m_sum; }
private:
	std::vector<std::vector<std::vector<ScheduleEntry>>> m_scheduleEntryArray;
	void Estimation();
	int m_sum;
};

#endif
