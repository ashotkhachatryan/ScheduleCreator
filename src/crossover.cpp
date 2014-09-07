#include "crossover.h"
#include <iostream>

#define CROSSOVER_RATE 0.1
#define PAIR_COUNT 2

Crossover::Crossover(std::vector<ScheduleRandomTable> lChromosomeVector)
	: m_chromosomeVector(lChromosomeVector)
	, m_randomNumbers(new double[lChromosomeVector.size()])
	, m_chromoseCount(lChromosomeVector.size())
	, m_parentsPairCount(0)
{
	GenerateRandomNumbers();
	CalculateParentsPairCount();

  //m_parentsPair initialization
	m_parentsPair = new int*[m_parentsPairCount];
	for (int i = 0; i < m_parentsPairCount; i++) {
		m_parentsPair[i] = new int[PAIR_COUNT];
	}

	ChooseParentChromosomes();
	GenerateRandomCrossoverPoints();
	CrossoverCut();
}

void
Crossover::GenerateRandomNumbers()
{
	for (int i = 0; i < m_chromoseCount; i++) {
    int RandomNumber = rand() % (10000 + 1);
    m_randomNumbers[i] = (double)RandomNumber / 10000;
	}
}

void
Crossover::ChooseParentChromosomes()
{
	if (m_parentsPairCount != 0) {
	int lIndex = 0;	
	for (int i = 0; i < m_chromoseCount; i++) {
		if (m_randomNumbers[i] < CROSSOVER_RATE) {
			if (lIndex != 0) {
				m_parentsPair[lIndex - 1][1] = i;
			}
			m_parentsPair[lIndex][0] = i;
			lIndex++;
		}
	}
	m_parentsPair[lIndex - 1][1] = m_parentsPair[0][0];
	}
}

void
Crossover::CalculateParentsPairCount()
{
	for (int i = 0; i < m_chromoseCount; i++) {
		if (m_randomNumbers[i] < CROSSOVER_RATE) {
			m_parentsPairCount++;
		}
	}
}

void
Crossover::GenerateRandomCrossoverPoints()
{
	m_randomCrossoverPoints = new int[m_parentsPairCount];
	for (int i = 0; i < m_parentsPairCount; i++) {
      m_randomCrossoverPoints[i] = 1 + rand() % (m_chromosomeVector[0].GetScheduleEntryArray().size() - 2);
	}
}

void
Crossover::SwapChromosome(int pIndex1, int pIndex2, int pCrossoverPoint)
{
	std::vector<std::vector<std::vector<ScheduleEntry>>> lScheduleTable1 = m_chromosomeVector[pIndex1].GetScheduleEntryArray();
	std::vector<std::vector<std::vector<ScheduleEntry>>> lScheduleTable2 = m_chromosomeVector[pIndex2].GetScheduleEntryArray();
	std::vector<std::vector<std::vector<ScheduleEntry>>> lTmpScheduleTable;
	lTmpScheduleTable.insert(lTmpScheduleTable.end(), lScheduleTable1.begin(), (lScheduleTable1.begin() + pCrossoverPoint));
	lTmpScheduleTable.insert(lTmpScheduleTable.end(), lScheduleTable2.begin() + pCrossoverPoint, lScheduleTable2.end());
	m_chromosomeVector[pIndex1].SetScheduleEntryArray(lTmpScheduleTable);
}

void
Crossover::CrossoverCut()
{

	for (int i = 0; i < m_parentsPairCount; i++) {
		m_chromosomeVector[m_parentsPair[i][0]];
		SwapChromosome(m_parentsPair[i][0], m_parentsPair[i][1], m_randomCrossoverPoints[i]);
	}
}

