#include <iostream>
#include "schedule_table.h"
#include "schedule_entry.h"
#include "schedule_random_table.h"
#include "evaluation.h"
#include "selection.h"
#include "crossover.h"
#include "mutation.h"

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
	srand(time(NULL));
	const int ChromosomeCount = 6;
	std::vector<ScheduleRandomTable> lChromosomeVector;
	for (int i = 0; i < ChromosomeCount; i++) {
		lChromosomeVector.push_back(ScheduleRandomTable(i));
	}
	int lMax = 0;
	while(true) {
	// 1. Chromosome
	Evaluation* lEvaluation[ChromosomeCount];
	// 2. Evaluation
	for (int i = 0; i < ChromosomeCount; i++) {
		lEvaluation[i] = new Evaluation(lChromosomeVector[i]);
		std::cout << i << ": " << lEvaluation[i]->GetEvaluation() << std::endl;
		if (lEvaluation[i]->GetEvaluation() > lMax) {
		//	lMax = lEvaluation[i]->GetEvaluation();
		//	std::cout << lMax << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "Hello world" << std::endl;
	// 3. Selection
	Selection lSelection(lEvaluation, ChromosomeCount, lChromosomeVector);
	std::vector<ScheduleRandomTable> lNewChromosomeVector = lSelection.GetNewChromosomeVector();

	// 4. Crossover
	Crossover lCrossover(lNewChromosomeVector);
	std::vector<ScheduleRandomTable> lCrossoverChromosomeVector = lCrossover.GetScheduleRandomTable();
	// 5. Mutation

	Mutation lMutation(lCrossoverChromosomeVector);
	lChromosomeVector = lMutation.GetChromosomeVector();
	}
//	for (int p = 0; p < 6; p++) {
//	std::cout << "########################## " << p << std::endl;
//	for (int i = 0; i < 5; i++) {
//		std::cout << "****************" << i << std::endl;
//		for (int j = 0; j < 6; j++) {
//			std::vector<ScheduleEntry> lEntryVector;
//			for (int k = 0; k < 5; k++) {
//				try {
//					ScheduleEntry lScheduleEntry = lCrossover.GetScheduleRandomTable()[p](i,j,k);
//					lEntryVector.push_back(lScheduleEntry);
//				} catch(...) {
//				}
//			}
//			try {
//				print(lEntryVector);
//			} catch(...) {
//			}
//		}
//	}
//	}
/*
		Evaluation e(l);
		std::cout << e.GetEvaluation() << std::endl;
*/
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
