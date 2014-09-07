#ifndef MUTATION_H
#define MUTATION_H

#include "schedule_random_table.h"

class Mutation
{
public:
	Mutation(std::vector<ScheduleRandomTable> lChromosomeVector);
	std::vector<ScheduleRandomTable> GetChromosomeVector() { return m_chromosomeVector; }
private:
	std::vector<ScheduleRandomTable> m_chromosomeVector;
	int m_genLength;
	int m_oneChromosomeGenLength;
	int m_mutationNumber;
	std::vector<int> m_randomNumbers;
	void CalculateGenLength();
	void CalculateOneChromosomeGenLength();
	std::vector<int> GetRandomNumbers(int pCount) const;
	void GenerateRandomNumbers();
	void Invoke(int pRandomNumber);
	void DoMutation();
};

#endif
