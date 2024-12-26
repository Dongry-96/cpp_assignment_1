#include "AverageCalculator.h"
#include <iostream>
#include <iomanip>

using namespace std;

void AverageCalculator::InputData()
{
	NumListSize = GetValidInteger("�Է��Ͻ� ������ ������ �Է��ϼ���!", "��ȿ���� ���� �����Դϴ�.. �ٽ� �Է��ϼ���!");
	
	cout << "���ڸ� �Է��ϼ���!" << endl;
	for (int i = 0; i < NumListSize; i++)
	{
		int Value = GetValidInteger(" ", "��ȿ���� ���� �����Դϴ�.. �ٽ� �Է��ϼ���!");
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
	cout << endl << "����� �����帮�ڽ��ϴ�." << endl;
	cout << "����: " << Sum << ", ���: " << fixed << setprecision(1) << Average << endl;
}

int main()
{
	AverageCalculator Calculator;

	Calculator.InputData();
	Calculator.DisplaySumAndAverage();

	return 0;
}