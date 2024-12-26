#include "QuickSort.h"
#include <iostream>
#include <string>

using namespace std;

void QuickSort::InputData()
{
	int InputSize = GetValidInteger("������ ������ �Է��ϼ���...", "��ȿ�� ������ �Է��ϼ���!", 1);

	cout << endl << "������ " << InputSize << "���� ���ڸ� �Է��ϼ���!" << endl;
	for (int i = 0; i < InputSize; i++)
	{
		int Value = GetValidInteger("", "��ȿ�� �Է��� �ƴմϴ�, �ٽ� �Է��ϼ���!");
		NumList.push_back(Value);
	}

	Order = GetValidInteger
	("������������ �����Ϸ��� '1'��, ������������ �����Ϸ��� '2'�� �Է��ϼ���!", "�߸��� �Է��Դϴ�. 1 Ȥ�� 2�� �Է����ּ���", 1, 2);
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
	if (Left < Right) //���ȣ�� ���� ����
	{
		// Pivot�� Ȯ�� ��ġ Idx�� �������� ���ʰ� ���������� ������ ���ȣ��
		int PivotIndex = Partition(NumList, Left, Right);
		SortAlgorithm(NumList, Left, PivotIndex - 1);
		SortAlgorithm(NumList, PivotIndex + 1, Right);
	}
}

int QuickSort::Partition(vector<int>& NumList, int Left, int Right)
{
	// ���Ƿ� ������ ���� Pivot���� ����
	int Pivot = NumList[Right];

	int i = Left - 1;

	for (int j = Left; j <= Right; ++j)
	{
		// �������� ����
		if (Order == 1)
		{
			if (NumList[j] < Pivot)
			{
				++i;
				swap(NumList[i], NumList[j]);
			}
		}
		// �������� ����
		else
		{
			if (NumList[j] > Pivot)
			{
				++i;
				swap(NumList[i], NumList[j]);
			}
		}
	}
	// (i + 1)�� Pivot�� ���� ��ġ 
	swap(NumList[i + 1], NumList[Right]);

	// Pivot�� ��ġ �ε��� ��ȯ
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
		cout << endl << "������������ ���ĵ� ������: ";
	}
	else
	{
		cout << endl << "������������ ���ĵ� ������: ";
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