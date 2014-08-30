#include <iostream>
#include "schedule_table.h"
#include "schedule_entry.h"
#include "schedule_random_table.h"

void print(std::vector<ScheduleEntry> pScheduleEntry) {
	for (int i = 0; i < pScheduleEntry.size(); i++) {
		if (pScheduleEntry[i].GetClassroom() != nullptr) {
			std::cout << pScheduleEntry[i].GetClassroom()->GetName() << "\t\t\t\t\t\t\t\t";
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < pScheduleEntry.size(); i++) {
		if (pScheduleEntry[i].GetLecture() != nullptr) {
			std::cout << pScheduleEntry[i].GetLecture()->GetName() << "\t\t\t";
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < pScheduleEntry.size(); i++) {
		if (pScheduleEntry[i].GetTeacher() != nullptr) {
			std::cout << pScheduleEntry[i].GetTeacher()->GetName() << "\t\t\t";
		}
	}
	std::cout << std::endl;
}

int main()
{
	ScheduleRandomTable l;
	for (int i = 0; i < 5; i++) {
		std::cout << "**********************************************" << i << std::endl;
		for (int j = 0; j < 6; j++) {
			std::vector<ScheduleEntry> lEntryVector;
			for (int k = 0; k < 5; k++) {
				try {
					ScheduleEntry lScheduleEntry = l(i,j,k);
					lEntryVector.push_back(lScheduleEntry);
				} catch(...) {
				}
			}
			try {
				print(lEntryVector);
			} catch(...) {
			}
		}
	}

	//ScheduleTable* lScheduleTable = ScheduleTable::GetInstance();	
	//for (int i = 0; i < 5; i++) {
		//(*lScheduleTable)(i);
		/*
		std::cout << "**********************************************" << i << std::endl;
		for (int j = 0; j < 6; j++) {
			std::vector<ScheduleEntry> lEntryVector;
			for (int k = 0; k < 5; k++) {
				try {
					ScheduleEntry lScheduleEntry = (*lScheduleTable)(i,j,k);
					lEntryVector.push_back(lScheduleEntry);
				} catch(...) {
				}
			}
			try {
				print(lEntryVector);
			} catch(...) {
			}
		}
		*/
	//}
	//std::cout << lScheduleEntry.GetClassroom()->GetName() << std::endl;
	//std::cout << lScheduleEntry.GetTeacher()->GetName() << std::endl;
//	std::cout << lScheduleEntry.GetLecture()->GetName() << std::endl;
}
