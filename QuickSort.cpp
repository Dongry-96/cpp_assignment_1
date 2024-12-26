#include "QuickSort.h"
#include <iostream>
#include <string>

using namespace std;

void QuickSort::InputData()
{
	int InputSize = GetValidInteger("숫자의 개수를 입력하세요...", "유효한 정수를 입력하세요!", 1);

	cout << endl << "정렬할 " << InputSize << "개의 숫자를 입력하세요!" << endl;
	for (int i = 0; i < InputSize; i++)
	{
		int Value = GetValidInteger("", "유효한 입력이 아닙니다, 다시 입력하세요!");
		NumList.push_back(Value);
	}

	Order = GetValidInteger
	("오름차순으로 정렬하려면 '1'을, 내림차순으로 정렬하려면 '2'를 입력하세요!", "잘못된 입력입니다. 1 혹은 2를 입력해주세요", 1, 2);
}

int QuickSort::GetValidInteger(const string& InputMessage, const string& ErrorMessage, int Min, int Max)
{
	cout << InputMessage << endl;
	int Value;
	while (1)
	{
		cin >> Value;
		if (cin.fail() || Value < Min || Value > Max)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		else
		{
			return Value;
		}
	}
	return -1;
}

void QuickSort::SortAlgorithm(vector<int>& NumList, int Left, int Right)
{
	if (Left < Right) //재귀호출 종료 조건
	{
		// Pivot의 확정 위치 Idx를 기준으로 왼쪽과 오른쪽으로 나누어 재귀호출
		int PivotIndex = Partition(NumList, Left, Right);
		SortAlgorithm(NumList, Left, PivotIndex - 1);
		SortAlgorithm(NumList, PivotIndex + 1, Right);
	}
}

int QuickSort::Partition(vector<int>& NumList, int Left, int Right)
{
	// 임의로 마지막 값을 Pivot으로 설정
	int Pivot = NumList[Right];

	int i = Left - 1;

	for (int j = Left; j <= Right; ++j)
	{
		// 오름차순 정렬
		if (Order == 1)
		{
			if (NumList[j] < Pivot)
			{
				++i;
				swap(NumList[i], NumList[j]);
			}
		}
		// 내림차순 정렬
		else
		{
			if (NumList[j] > Pivot)
			{
				++i;
				swap(NumList[i], NumList[j]);
			}
		}
	}
	// (i + 1)은 Pivot의 최종 위치 
	swap(NumList[i + 1], NumList[Right]);

	// Pivot의 위치 인덱스 반환
	return i + 1;
}

void QuickSort::DoSort()
{
	InputData();
	SortAlgorithm(NumList, 0, NumList.size() - 1);
}

void QuickSort::Display()
{
	if (Order == 1)
	{
		cout << endl << "오름차순으로 정렬된 데이터: ";
	}
	else
	{
		cout << endl << "내림차순으로 정렬된 데이터: ";
	}

	for (vector<int>::iterator it = NumList.begin(); it != NumList.end(); ++it)
	{
		cout << *it << " ";
	}
}

//int main()
//{
//	QuickSort Sort;
//
//	Sort.DoSort();
//	Sort.Display();
//
//	return 0;
//}