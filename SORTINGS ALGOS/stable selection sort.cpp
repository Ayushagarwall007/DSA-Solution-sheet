Selection sort can be made Stable if instead of swapping, the minimum element is placed in its position without swapping i.e. by placing the number in its position by pushing every element 
one step forward(shift all elements to left by 1). 
  Example: 4A 5 3 2 4B 1
         First minimum element is 1, now instead
         of swapping. Insert 1 in its correct place 
         and pushing every element one step forward
         i.e forward pushing.
         1 4A 5 3 2 4B
         Next minimum is 2 :
         1 2 4A 5 3 4B
         Next minimum is 3 :
         1 2 3 4A 5 4B
         Repeat the steps until array is sorted.
         1 2 3 4A 4B 5
           
           
           
// C++ program for modifying Selection Sort
// so that it becomes stable.
#include <iostream>
using namespace std;

void stableSelectionSort(int a[], int n)
{
	// Iterate through array elements
	for (int i = 0; i < n - 1; i++)
	{

		// Loop invariant : Elements till a[i - 1]
		// are already sorted.

		// Find minimum element from
		// arr[i] to arr[n - 1].
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min] > a[j])
				min = j;

		// Move minimum element at current i.
		int key = a[min];
	//Shift left all elements by one.
	for(int k=min;k>i;k--)
		a[k]=a[k-1];
	//Store the key at its right position.
		a[i] = key;
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int a[] = { 4, 5, 3, 2, 4, 1 };
	int n = sizeof(a) / sizeof(a[0]);
	stableSelectionSort(a, n);
	printArray(a, n);
	return 0;
}
