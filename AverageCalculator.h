#ifndef AverageCalculator_H_
#define AverageCalculator_H_

#include <vector>
#include <string>

class AverageCalculator
{
private:
	std::vector<int> NumList;
	int NumListSize;
	int Sum;
	float Average;
public:
	AverageCalculator() : Sum(0) {}

	void InputData();
	int GetValidInteger(const std::string& InputMessage, const std::string& ErrorMessage);
	void GetSum(const std::vector<int> Numlist);
	void GetAverage(const int Sum);
	void DisplaySumAndAverage();
};

#endif //!AverageCalculator_H_