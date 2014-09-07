#ifndef SELECTION_H
#define SELECTION_H

#include "evaluation.h"

class Selection
{
public:
	Selection(Evaluation* e[], int pCount, std::vector<ScheduleRandomTable> lScheduleRandomTable);
	std::vector<ScheduleRandomTable> GetNewChromosomeVector() const;
private:
	double* m_fitness;
	double* m_probability;
	double* m_comulativeProbability;
	double* m_randomNumbers;
	int m_chromoseCount;
	int* m_newChromosomeSequence;
	double m_total;
	std::vector<ScheduleRandomTable> m_scheduleRandomTable;
	std::vector<ScheduleRandomTable> m_newScheduleRandomTable;
	void CalculateFitness(Evaluation* e[]);
	void CalculateTotal();
	void CalculateProbability();
	void CalculateComulativeProbability();
	void GenerateRandomNumbers();
	void CalculateNewChromosomeSequence();
	void SetNewScheduleRandomTable();
};

#endif
