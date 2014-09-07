#ifndef CROSSOVER_H
#define CROSSOVER_H

#include "schedule_random_table.h"

class Crossover
{
public:
	Crossover(std::vector<ScheduleRandomTable> lChromosomeVector);
	std::vector<ScheduleRandomTable> GetScheduleRandomTable() { return m_chromosomeVector; }
private:
	std::vector<ScheduleRandomTable> m_chromosomeVector;
	double* m_randomNumbers;
	int m_chromoseCount;
	int** m_parentsPair;
	int* m_randomCrossoverPoints;
	int m_parentsPairCount;
	void GenerateRandomNumbers();
	void ChooseParentChromosomes();
	void CalculateParentsPairCount();
	void GenerateRandomCrossoverPoints();
	void CrossoverCut();
  void SwapChromosome(int pIndex1, int pIndex2, int pCrossoverPoint);
};

#endif
