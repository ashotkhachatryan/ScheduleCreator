#include "selection.h"
#include <iostream>
#include <iomanip>
#include <assert.h>

Selection::Selection(Evaluation* e[], int pCount, std::vector<ScheduleRandomTable> pScheduleRandomTable )
	: m_fitness(new double[pCount])
	, m_probability(new double[pCount])
	, m_comulativeProbability(new double[pCount])
	, m_randomNumbers(new double[pCount])
	, m_chromoseCount(pCount)
	, m_newChromosomeSequence(new int[pCount])
	, m_total(0)
	, m_scheduleRandomTable(pScheduleRandomTable)
{
	CalculateFitness(e);
	CalculateTotal();
	CalculateProbability();
	CalculateComulativeProbability();
	GenerateRandomNumbers();
	CalculateNewChromosomeSequence();
	SetNewScheduleRandomTable();
}

void
Selection::CalculateFitness(Evaluation* e[])
{
	for (int i = 0; i < m_chromoseCount; i++) {
		m_fitness[i] = 1 / (1 + (double)e[i]->GetEvaluation());
	}
}

void
Selection::CalculateTotal()
{
	for (int i = 0; i < m_chromoseCount; i++) {
		m_total += m_fitness[i];	
	}
}

void
Selection::CalculateProbability()
{
	for (int i = 0; i < m_chromoseCount; i++) {
		m_probability[i] = m_fitness[i] / m_total;
	}	
}

void
Selection::CalculateComulativeProbability()
{
	m_comulativeProbability[0] = m_probability[0];
	for (int i = 1; i < m_chromoseCount; i++) {
		m_comulativeProbability[i] = m_comulativeProbability[i-1] + m_probability[i];
	}
}

void
Selection::GenerateRandomNumbers()
{
	for (int i = 0; i < m_chromoseCount; i++) {
    int RandomNumber = rand() % (10000 + 1);
    m_randomNumbers[i] = (double)RandomNumber / 10000;
	}
}

void
Selection::CalculateNewChromosomeSequence()
{
	for (int i = 0; i < m_chromoseCount; i++) {
		for (int j = 0; j < m_chromoseCount - 1; j++) {
			if (m_randomNumbers[i] <= m_comulativeProbability[0]) {
				m_newChromosomeSequence[i] = 0;
			} else if (m_randomNumbers[i] > m_comulativeProbability[j] &&
								 m_randomNumbers[i] <= m_comulativeProbability[j+1]) {
				m_newChromosomeSequence[i] = j + 1;
			}
		}
	}
	for (int i = 0; i < m_chromoseCount; i++) {
		assert(m_newChromosomeSequence[i] < m_chromoseCount);
	}
}

void
Selection::SetNewScheduleRandomTable()
{
	for (int i = 0; i < m_chromoseCount; i++) {
		m_newScheduleRandomTable.push_back(m_scheduleRandomTable[m_newChromosomeSequence[i]]);
	}
}

std::vector<ScheduleRandomTable> 
Selection::GetNewChromosomeVector() const
{
	return m_newScheduleRandomTable;
}
