#include "AverageCalculator.h"
#include <iostream>
#include <iomanip>

using namespace std;

void AverageCalculator::InputData()
{
	NumListSize = GetValidInteger("입력하실 숫자의 개수를 입력하세요!", "유효하지 않은 숫자입니다.. 다시 입력하세요!");
	
	cout << "숫자를 입력하세요!" << endl;
	for (int i = 0; i < NumListSize; i++)
	{
		int Value = GetValidInteger(" ", "유효하지 않은 숫자입니다.. 다시 입력하세요!");
		NumList.push_back(Value);
	}
	GetSum(NumList);
	GetAverage(Sum);
}

int AverageCalculator::GetValidInteger(const string& InputMessage, const string& ErrorMessage)
{
	int Value;
	cout << InputMessage << endl;
	while (1)
	{
		cin >> Value;
		if (cin.fail())
		{
			cout << ErrorMessage << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else break;
	}
	return Value;
}

void AverageCalculator::GetSum(const vector<int> Numlist)
{
	for (vector<int>::iterator it = NumList.begin(); it != NumList.end(); ++it)
	{
		Sum += *it;
	}
}

void AverageCalculator::GetAverage(const int Sum)
{
	Average =  static_cast<float>(Sum) / NumListSize;
}

void AverageCalculator::DisplaySumAndAverage()
{
	cout << endl << "결과를 보여드리겠습니다." << endl;
	cout << "총합: " << Sum << ", 평균: " << fixed << setprecision(1) << Average << endl;
}

int main()
{
	AverageCalculator Calculator;

	Calculator.InputData();
	Calculator.DisplaySumAndAverage();

	return 0;
}