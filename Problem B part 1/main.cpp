#include <iostream>
#include <algorithm>
using namespace std;
void Swap(int &x,int &y){
int temp;
temp=x;
x=y;
y=temp;

}
void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout <<endl;
}
void merge(int X[], int Y[], int SizeOf_x, int SizeOf_n)
{

	for (int i = 0; i < SizeOf_x;  i++)
	{
		if (X[i] > Y[0])
		{
			Swap(X[i], Y[0]);
			int first = Y[0];
			int j;
			for (j = 1; j < SizeOf_n && Y[j] < first; j++) {
				Y[j - 1] = Y[j];
			}

			Y[j - 1] = first;
		}
	}
}

int main()
{
	int X[] = { 1, 4, 7, 8, 10 };
	int Y[] = { 2, 3, 9 };
	int SizeOf_x = sizeof(X) / sizeof(X[0]);
	int SizeOf_y = sizeof(Y) / sizeof(Y[0]);

	merge(X, Y,SizeOf_x, SizeOf_y);

	cout << "X: "; Print(X, SizeOf_x);
	cout << "Y: "; Print(Y, SizeOf_y);

	return 0;
}
