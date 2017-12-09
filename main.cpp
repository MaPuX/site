#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;


int randomNumber(int from, int to)
{
	return from + rand() % (to - from + 1);
}

void enterMatrixSize(int** &matrix, int &linesCount, int &columnsCount)
{
     setlocale(LC_ALL, "rus");
	if (linesCount > 0 || columnsCount > 0)
	{
		for (int i = 0; i < linesCount; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	linesCount = 0; columnsCount = 0;
	while (linesCount <= 0)
	{
		printf("������� ����� �����: ");
		cin >> linesCount;
		if (linesCount <= 0)
		{
			cout<<"�� ����� �������� ��������!\n";
		}
	}
	while (columnsCount <= 0)
	{
		printf("������� ����� ��������: ");
		cin>>columnsCount;
		if (columnsCount <= 0)
		{
			cout<<"�� ����� �������� ��������!\n";
		}
	}

	matrix = new int*[linesCount];
	for (int i = 0; i < linesCount; i++)
	{
		matrix[i] = new int[columnsCount];
		for (int j = 0; j < columnsCount; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void fillMatrixWithKeyboard(int **matrix, int linesCount, int columnsCount)
{
	if (linesCount <= 0 || columnsCount <= 0)
	{
		printf("�� ��� �� ������ �������!\n");
	}
	else
	{
		for (int i = 0; i < linesCount; i++)
		{
			for (int j = 0; j < columnsCount; j++)
			{
				cout<<"Please, enter the %d item of the %d line of the matrix: ", j, i;
				cin>>matrix[i][j];
			}
		}
	}
}

void fillMatrixWithRandomNumbers(int **matrix, int linesCount, int columnsCount)
{
	if (linesCount <= 0 || columnsCount <= 0)
	{
		cout<<"�� ��� �� ������ �������!\n";
	}
	else
	{
		cout << "������� ������ ����� ��������� �����: ";
		int lowerLimit = 0;
		cin>>lowerLimit;

		cout << "������� ������� ����� ��������� �����: ";
		int upperLimit = 0;
		cin>>upperLimit;

		for (int i = 0; i < linesCount; i++)
		{
			for (int j = 0; j < columnsCount; j++)
			{
				matrix[i][j] = randomNumber(lowerLimit, upperLimit);
			}
		}
	}
}

void printMatrix(int **matrix, int linesCount, int columnsCount)
{
	if (linesCount <= 0 || columnsCount <= 0)
	{
		cout<<"�� ��� �� ������ �������!\n";
	}
	else
	{
		for (int i = 0; i < linesCount; i++)
		{
			for (int j = 0; j < columnsCount; j++)
			{
				cout <<" " << matrix[i][j] << " ";
			}
			cout<<endl;
		}
	}
}

void swapSmallestAndBiggest(int** matrix, int linesCount, int columnsCount)
{
	if (linesCount == 0)
	{
		cout<<"�� ��� �� ������ �������!\n";
	}
	else
	{
		for (int i = 0; i < columnsCount; i++)
		{
			int smallestItem = matrix[0][i], smallestIndex = 0;
			int biggestItem = matrix[0][i], biggestIndex = 0;

			for (int j = 0; j < linesCount; j++)
			{
				if (matrix[j][i] < smallestItem)
				{
					smallestItem = matrix[j][i];
					smallestIndex = j;
				}

				if (matrix[j][i] > biggestItem)
				{
					biggestItem = matrix[j][i];
					biggestIndex = j;
				}
			}

			int buffer = matrix[smallestIndex][i];
			matrix[smallestIndex][i] = matrix[biggestIndex][i];
			matrix[biggestIndex][i] = buffer;
		}
	}
}

int main()
{
    setlocale(LC_ALL, "rus");
	int **matrix = NULL;
	int linesCount = 0, columnsCount = 0;

	cout<<"��������� �� ������ � ��������\n";

	bool programIsClosed = false;
	while (!programIsClosed)
	{
		cout << "1 - ������� ������ �������\n";
		cout << "2 - ��������� ������� �������\n";
		cout << "3 - ��������� ������� ���������� �������\n";
		cout << "4 - ������� �������\n";
		cout << "5 - �������� ���������� � ���������� ������� � ������ �������\n";
		cout << "0 - �����\n";
		cout <<"���������� ������� ����� �������: ";

		int optionCode = -1;
		cin>>optionCode;
		switch (optionCode)
		{
		case 1:
			enterMatrixSize(matrix, linesCount, columnsCount);
			break;
		case 2:
			fillMatrixWithKeyboard(matrix, linesCount, columnsCount);
			break;
		case 3:
			fillMatrixWithRandomNumbers(matrix, linesCount, columnsCount);
			break;
		case 4:
			printMatrix(matrix, linesCount, columnsCount);
			break;
		case 5:
			swapSmallestAndBiggest(matrix, linesCount, columnsCount);
			break;
		case 0:
			programIsClosed = true;
			break;
		default:
			cout<<"�� ����� �������� ����� �������!\n";
		}
	}

	if (linesCount > 0 || columnsCount > 0)
	{
		for (int i = 0; i < linesCount; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}

	return 0;
}
