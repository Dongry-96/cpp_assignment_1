#ifndef QuickSort_H_
#define QuickSort_H_

#include <vector>
#include <limits>
#include <string>

class QuickSort
{
private:
	std::vector<int> NumList;
	int Order;

public:
	void DoSort();
	void Display();
	
private:
	void InputData();
	int GetValidInteger(const std::string& InputMessage, const std::string& ErrorMessage, int Min = INT_MIN, int Max = INT_MAX);
	void SortAlgorithm(std::vector<int>& NumList, int Left, int Right);
	int Partition(std::vector<int>& NumList, int Left, int Right);
};

#endif //!QuickSort_H_
	