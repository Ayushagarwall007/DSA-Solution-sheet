// How does QuickSort work?
// The key process in quickSort is a partition(). The target of partitions is to place the pivot (any element can be chosen to be a pivot) at its correct position in the sorted array and put all smaller elements to the 
// left of the pivot, and all greater elements to the right of the pivot.

// This partition is done recursively which finally sorts the array. See the below image for a better understanding.

Quicksort's best-case time complexity is O (n*logn) .

// C++ code to implement quicksort

#include <bits/stdc++.h>
using namespace std;

// This function takes last element as pivot,
// places the pivot element at its correct position
// in sorted array, and places all smaller to left
// of pivot and all greater elements to right of pivot
int partition(int arr[], int low, int high)
{
	// Choosing the pivot
	int pivot = arr[high];

	// Index of smaller element and indicates
	// the right position of pivot found so far
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {

		// If current element is smaller than the pivot
		if (arr[j] < pivot) {

			// Increment index of smaller element
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high)
{
	if (low < high) {

		// pi is partitioning index, arr[p]
		// is now at right place
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Driver Code
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	quickSort(arr, 0, N - 1);
	cout << "Sorted array: " << endl;
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	return 0;
}

		
Why Quick Sort is preferred over MergeSort for sorting Arrays ?
// Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any extra storage) whereas merge sort requires O(N) extra storage, N denoting the array size which may be quite expensive. 
// Allocating and de-allocating the extra space used for merge sort increases the running time of the algorithm. Comparing average complexity we find that both types of sorts have O(N logN) average complexity but 
//  the constants differ. For arrays, merge sort loses due to the use of extra O(N) storage space.
// Most practical implementations of Quick Sort use randomized versions. The randomized version has an expected time complexity of O(N logN). The worst case is possible in the randomized version also, 
// but the worst case doesn’t occur for a particular pattern (like sorted array) and randomized Quick Sort works well in practice.
// Quick Sort is also a cache friendly sorting algorithm as it has a good locality of reference when used for arrays.
// Quick Sort is also tail recursive, therefore tail call optimizations are done.
			     
			     
Why MergeSort is preferred over QuickSort for Linked Lists ?
// In the case of linked lists, the case is different mainly due to the difference in memory allocation of arrays and linked lists. Unlike arrays, linked list nodes may not be adjacent in memory. 
// Unlike arrays, in linked lists, we can insert items in the middle in O(1) extra space and O(1) time. Therefore merge operation of merge sort can be implemented without extra space for linked lists.
// Unlike arrays, we can not do random access in linked lists. Quick Sort requires a lot of this kind of access. In a linked list to access the ith index, we have to travel each and every node from the head to ith node
//    as we don’t have a continuous block of memory. Therefore, the overhead increases for quicksort. Merge sort accesses data sequentially and the need for random access is low. 

Is QuickSort stable?
The default implementation is not stable. However, any sorting algorithm can be made stable by considering indices as a comparison parameter. 

Is QuickSort In-place?
As per the broad definition of in-place algorithm, it qualifies as an in-place sorting algorithm as it uses extra space only for storing recursive function calls but not for manipulating the input. 
			     
			     
			     
			     
             
             
