#include "mutation.h"
#include <iostream>
#include <algorithm>
#include "schedule_db.h"
#include <assert.h>

#define MUTATION_RATE 0.5

Mutation::Mutation(std::vector<ScheduleRandomTable> lChromosomeVector)
	: m_chromosomeVector(lChromosomeVector)
	, m_genLength(0)
	, m_mutationNumber(0)
{
	CalculateGenLength();
	CalculateOneChromosomeGenLength();
	m_mutationNumber = (m_genLength * MUTATION_RATE) / 100;
	GenerateRandomNumbers();
	DoMutation();
}

void
Mutation::CalculateOneChromosomeGenLength()
{
	int lSize = 0;
		std::vector<std::vector<std::vector<ScheduleEntry>>> lScheduleEntryArray = 
		m_chromosomeVector[0].GetScheduleEntryArray();
		for (int l = 0; l < lScheduleEntryArray.size(); l++) {
			for (int m = 0; m < lScheduleEntryArray[l].size(); m++) {
				lSize += lScheduleEntryArray[l][m].size();
			}
		}
	m_oneChromosomeGenLength = lSize;
}

void
Mutation::CalculateGenLength()
{
	int lSize = 0;
	for (int i = 0; i < m_chromosomeVector.size(); i++) {
		std::vector<std::vector<std::vector<ScheduleEntry>>> lScheduleEntryArray = 
		m_chromosomeVector[i].GetScheduleEntryArray();
		for (int l = 0; l < lScheduleEntryArray.size(); l++) {
			for (int m = 0; m < lScheduleEntryArray[l].size(); m++) {
				lSize += lScheduleEntryArray[l][m].size();
			}
		}
	}
	m_genLength = lSize;
}

void
Mutation::GenerateRandomNumbers()
{
	m_randomNumbers = GetRandomNumbers(m_mutationNumber);
}
	
void
Mutation::DoMutation()
{
	for (int i = 0; i < m_randomNumbers.size(); i++) {
		Invoke(m_randomNumbers[i]);
	}
}

std::vector<int>
Mutation::GetRandomNumbers(int pCount) const
{
  std::vector<int> lVector;
  for (int i = 0; i < pCount; i++) {
    int lRandom;
    while(true) {
      lRandom = rand() % m_genLength;
      if (std::find(lVector.begin(), lVector.end(), lRandom) == lVector.end()) {
        break;
      }
    }
    lVector.push_back(lRandom);
  }
  return lVector;
}

void
Mutation::Invoke(int pRandomNumber)
{
	int lChromosomeIndex = pRandomNumber / m_oneChromosomeGenLength;
	ScheduleRandomTable lScheduleRandomTable = m_chromosomeVector[lChromosomeIndex];
	std::vector<std::vector<std::vector<ScheduleEntry>>> lScheduleEntryArray = lScheduleRandomTable.GetScheduleEntryArray();
	int lSchoolIndex = -1;
	int lHourIndex = -1;
	int lDayIndex = -1;
	int lRandomHourIndex = -1;
	int lRandomDayIndex = -1;
	int lSchoolSize = 0;
	int lRelativeNumber = pRandomNumber - (lChromosomeIndex * m_oneChromosomeGenLength);
	int lTmpRelativeNumber = lRelativeNumber;
	bool lStatus = false;
	for (int i = 0; i < lScheduleEntryArray.size(); i++) {
		int lClassroomSize = 0;
		for (int j = 0; j < lScheduleEntryArray[i].size(); j++) {
			lSchoolSize += lScheduleEntryArray[i][j].size();
			lClassroomSize += lScheduleEntryArray[i][j].size();

		if (!lStatus) {
		if ((lSchoolSize - 1) >= lRelativeNumber) {
			lSchoolIndex = i;
			lHourIndex = j;
			lDayIndex = lTmpRelativeNumber % ScheduleDb::DayCount;
			lStatus = true;
		}
		}

		}
		if (lStatus) {
			int r = rand() % lClassroomSize;
			lRandomHourIndex = r / ScheduleDb::DayCount; 
		  lRandomDayIndex = r - (lRandomHourIndex * ScheduleDb::DayCount);

			i = lScheduleEntryArray.size();
			break;
		}
		lTmpRelativeNumber -= lClassroomSize;
	}
	assert (lSchoolIndex != -1);
	assert (lHourIndex != -1);
	assert (lDayIndex != -1);
	assert (lRandomHourIndex != -1);
	assert (lRandomDayIndex != -1);
	std::swap(lScheduleEntryArray[lSchoolIndex][lHourIndex][lDayIndex], 
						lScheduleEntryArray[lSchoolIndex][lRandomHourIndex][lRandomDayIndex]);
	m_chromosomeVector[lChromosomeIndex].SetScheduleEntryArray(lScheduleEntryArray);
}
