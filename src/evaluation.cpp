#include "evaluation.h"
#include "schedule_table.h"
#include "schedule_db.h"
#include "assert.h"
#include <iostream>

Evaluation::Evaluation(const ScheduleRandomTable& pScheduleRandomTable)
	: m_sum(0)
{
	m_scheduleEntryArray = pScheduleRandomTable.GetScheduleEntryArray();	
	Estimation();
}

void
Evaluation::Estimation()
{
	ScheduleTable* lScheduleTable = ScheduleTable::GetInstance();
	for (int i = 0; i < m_scheduleEntryArray.size(); i++) {
		for (int j = 0; j < m_scheduleEntryArray[i].size(); j++) {
			for (int k = 0; k < m_scheduleEntryArray[i][j].size(); k++) {
				ScheduleEntry lScheduleEntry = m_scheduleEntryArray[i][j][k];
				int lStatus = 0;
				
				for (int i1 = 0; i1 < m_scheduleEntryArray.size(); i1++) {
					if (j < m_scheduleEntryArray[i1].size()) {
						if (k < m_scheduleEntryArray[i1][j].size()) {
							ScheduleEntry lScheduleEntry1 = m_scheduleEntryArray[i1][j][k];

							if (lScheduleEntry.GetTeacher() == lScheduleEntry1.GetTeacher()) {
								lStatus++;
							}
						} else {
							lStatus++;
						}
					} else {
						lStatus++;
					}
				}
				
				if (lStatus == 1) {
					m_sum++;
				}

				const Lecture* lLecture = lScheduleEntry.GetLecture();
				int lLectureCount = lScheduleTable->GetLectureCountInClassroom(i, lLecture);
				int lLineNumber = (lLectureCount - 1) / ScheduleDb::DayCount;
				int lCount = 0;
				for (int j1 = 0; j1 < j; j1++) {
					ScheduleEntry lScheduleEntry1 = m_scheduleEntryArray[i][j1][k];
					if (lLecture == lScheduleEntry1.GetLecture()) {
						lCount++;
					}
				}
				if (lCount <= lLineNumber) {
					m_sum++;
				}
			}
		}	
	}
}
