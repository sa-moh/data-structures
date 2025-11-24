#include "../src/IPartition.h"
#include "../src/FiveWayPartition.h"
#include <iostream>
#include "I.h"

using namespace std;
template <class T>
void checkResult(IPartition<T> *fwp, T *A, T *pivots, int *q, int p, int r, int pivotsCount)
{

	fwp->partition(A, pivots, q, p, r, pivotsCount);

	cout << "\n\nLess than " << pivots[0] << ":" << endl;
	for (int i = p; i < q[0]; i++)
	{
		cout << A[i] << ", ";
		if (A[i] >= pivots[0])
		{
			throw runtime_error("value doesn't less than first pivot!");
		}
	}

	cout << "\n\nEquals to " << pivots[0] << ":" << endl;
	for (int i = q[0]; i < q[1]; i++)
	{
		cout << A[i] << ", ";
		if (A[i] != pivots[0])
		{
			throw runtime_error("value doesn't equal to first pivot!");
		}
	}

	cout << "\n\nLess than " << pivots[1] << " and greater than " << pivots[0] << ":" << endl;
	for (int i = q[1]; i < q[2]; i++)
	{
		cout << A[i] << ", ";
		if (A[i] <= pivots[0] || A[i] >= pivots[1])
		{
			throw runtime_error("value doesn't greater than first pivot or less than second pivot!");
		}
	}

	cout << "\n\nEquals to " << pivots[1] << ":" << endl;
	for (int i = q[2]; i < q[3]; i++)
	{
		cout << A[i] << ", ";
		if (A[i] != pivots[1])
		{
			throw runtime_error("value doesn't equal to second pivot!");
		}
	}

	cout << "\n\nGreater than " << pivots[1] << ":" << endl;
	for (int i = q[3]; i <= r; i++)
	{
		cout << A[i] << ", ";
		if (A[i] <= pivots[1])
		{
			throw runtime_error("value doesn't greater than second pivot!");
		}
	}
}

void testFiveWayPartition(int n, int p, int r, int bound)
{
	int pivotsCount = 2;
	int indexCount = 4;
	int *pivots;
	int *q;
	int *A;

	A = new int[n];

	q = new int[indexCount];

	pivots = new int[pivotsCount];
	for (int i = 0; i < pivotsCount; i++)
	{
		pivots[i] = rand() % (bound + 1);
	}

	if (pivots[0] > pivots[1])
		swap(pivots[0], pivots[1]);

	if (pivots[0] == pivots[1])
	{
		pivots[1]++;
	}

	cout << "Initial Array:" << endl;
	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % bound;
		cout << A[i] << ", ";
	}

	IPartition<int> *fwp = new FiveWayPartition<int>();
	checkResult(fwp, A, pivots, q, p, r, pivotsCount);

	cout << endl
		 << endl
		 << "Array after partition:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << ", ";
	}
	cout << endl
		 << "Excellent!" << endl;
}

void testTemplateFiveWayPartition(int n, int p, int r, int bound)
{
	int pivotsCount = 2;
	int indexCount = 4;
	I *pivots;
	int *q;
	I *A;

	A = new I[n];

	q = new int[indexCount];

	pivots = new I[pivotsCount];
	for (int i = 0; i < pivotsCount; i++)
	{
		pivots[i] = I((rand() % bound) / 10.0);
	}

	if (pivots[0] > pivots[1])
		swap(pivots[0], pivots[1]);

	if (pivots[0] == pivots[1])
	{
		pivots[1] = I(pivots[0].getValue() + 1);
	}

	cout << "Initial Array:" << endl;
	for (int i = 0; i < n; i++)
	{
		A[i] = I((rand() % bound) / 10.0);
		cout << A[i] << ", ";
	}

	IPartition<I> *fwp = new FiveWayPartition<I>();
	checkResult(fwp, A, pivots, q, p, r, pivotsCount);

	cout << endl
		 << endl
		 << "Array after partition:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << ", ";
	}
	cout << endl
		 << "Excellent!" << endl;
}

int main()
{
	cout << "Test fiveWay partition with p = start of arr and r = end of arr" << endl;
	testFiveWayPartition(10, 0, 9, 6);
	cout << endl
		 << "Test fiveWay partition with p = 5 and r = 15" << endl;
	testFiveWayPartition(20, 5, 15, 10);
	cout << endl
		 << "Test template fiveWay partition" << endl;
	testTemplateFiveWayPartition(15, 0, 14, 10);
}
