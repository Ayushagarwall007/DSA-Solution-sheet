Complexity Analysis of Insertion Sort:
Time Complexity of Insertion Sort
The worst case time complexity of Insertion sort is O(N^2)
The average case time complexity of Insertion sort is O(N^2)
The time complexity of the best case is O(N).
  
  
  
  
  Space Complexity of Insertion Sort
The auxiliary space complexity of Insertion Sort’s Recursive Approach is O(n) due to the recursion stack.

FAQs related to Insertion Sort
What are the Boundary Cases of the Insertion Sort algorithm?
Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted. 

What are the Algorithmic Paradigm of Insertion Sort algorithm?
Insertion Sort algorithm follows incremental approach.

Is Insertion Sort an in-place sorting algorithm?
Yes, insertion sort is an in-place sorting algorithm.

Is Insertion Sort a stable algorithm?
Yes, insertion sort is a stable sorting algorithm.

When is the Insertion Sort algorithm used?
Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

// C++ program for insertion sort

#include <bits/stdc++.h>
using namespace std;

// Function to sort an array using
// insertion sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		// Move elements of arr[0..i-1],
		// that are greater than key, to one
		// position ahead of their
		// current position
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array
// of size n
void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int N = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, N);
	printArray(arr, N);

	return 0;
}
.......................................................................................................



  
#include <iostream>
#include <vector>

using namespace std;

void recursiveInsertionSort(vector<int>& arr, int n)
{
	// Base case: if the array has only one element, it is already sorted
	if (n <= 1) {
		return;
	}
	
	// Sort the first n-1 elements of the array recursively
	recursiveInsertionSort(arr, n - 1);
	
	// Insert the nth element into its correct position in the sorted subarray
	int last = arr[n - 1];
	int j = n - 2;
	
	// Shift elements to the right to make space for the nth element
	while (j >= 0 && arr[j] > last)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	
	// Place the nth element in its correct position
	arr[j + 1] = last;
}

void printArray(vector<int>& arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> arr = {12, 11, 13, 5, 6};
	int n = arr.size();

	recursiveInsertionSort(arr, n);
	printArray(arr, n);

	return 0;
}
