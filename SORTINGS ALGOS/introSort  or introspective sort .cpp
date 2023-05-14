Introsort being a hybrid sorting algorithm uses three sorting algorithm to minimise the running time, Quicksort, Heapsort and Insertion Sort 

How does it work? 
// Introsort begins with quicksort and if the recursion depth goes more than a particular limit it switches to Heapsort to avoid Quicksort’s worse case O(N2) time complexity. It also uses insertion sort when the number 
// of elements to sort is quite less. So first it creates a partition. Three cases arises from here.

If the partition size is such that there is a possibility to exceed the maximum depth limit then the Introsort switches to Heapsort. We define the maximum depth limit as 2*log(N)
  
If the partition size is too small then Quicksort decays to Insertion Sort. We define this cutoff as 16 (due to research). So if the partition size is less than 16 then we will do insertion sort.
  
If the partition size is under the limit and not too small (i.e- between 16 and 2*log(N)), then it performs a simple quicksort.
  
Why is it better than simple Quicksort or Why the need of Introsort? 
// Since Quicksort can have a worse case O(N2) time complexity and it also increases the recursion stack space (O(log N) if tail recursion applied), so to avoid all these, we need to switch the algorithm from Quicksort
// to another if there is a chance of worse case. So Introsort solves this problem by switching to Heapsort. Also due to larger constant factor, quicksort can perform even worse than O(N2) sorting algorithm when N is
// small enough. So it switches to insertion sort to decrease the running time of sorting. Also if a bad pivot-selection is done then the quicksort does no better than the bubble-sort. 

// Why is Insertion Sort used (and not Bubble Sort, etc)?
//  Insertion sort offers following advantages.
// It is a known and established fact that insertion sort is the most optimal comparison-based sorting algorithm for small arrays.
// It has a good locality of reference
// It is an adaptive sorting algorithm, i.e- it outperforms all the other algorithms if the array elements are partially sorted.
  
Why is Heapsort used (and not Mergesort etc)? 
// This is solely because of memory requirements. Merge sort requires O(N) space whereas Heapsort is an in-place O(1) space algorithm. 
  
Why is Heapsort not used in place of Quicksort when the partition size is under the limit ? 
// This question is same as why Quicksort generally outperforms Heapsort ? The answer is, although Heapsort also being O(N log N) in average as well as worse case and O(1) space also, we still don’t use it when the
// partition size is under the limit because the extra hidden constant factor in Heapsort is quite larger than that of Quicksort. 

Why is cut-off 16 for switching from quick sort to insertion sort, and 2*logN for switching from quick sort to heap sort ? 
// These values are chosen empirically as an approximate because of various tests and researches conducted. 
  
  
  
  
  #include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
// Function to perform insertion sort on subarray `a[low…high]`
void insertionsort(int a[], int low, int high)
{
    // start from the second element in the subarray
    // (the element at index `low` is already sorted)
    for (int i = low + 1; i <= high; i++)
    {
        int value = a[i];
        int j = i;
 
        // find index `j` within the sorted subset a[0…i-1]
        // where element a[i] belongs
        while (j > low && a[j - 1] > value)
        {
            a[j] = a[j - 1];
            j--;
        }
 
        // Note that the subarray `a[j…i-1]` is shifted to
        // the right by one position, i.e., `a[j+1…i]`
 
        a[j] = value;
    }
}
 
// Function to partition the array using Lomuto partition scheme
int partition(int a[], int low, int high)
{
    // Pick the rightmost element as a pivot from the array
    int pivot = a[high];
 
    // elements less than the pivot will be pushed to the left of `pIndex`
    // elements more than the pivot will be pushed to the right of `pIndex`
    // equal elements can go either way
    int pIndex = low;
 
    // each time we find an element less than or equal to the pivot, `pIndex`
    // is incremented, and that element would be placed before the pivot.
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
 
    // swap `pIndex` with pivot
    swap (a[pIndex], a[high]);
 
    // return `pIndex` (index of the pivot element)
    return pIndex;
}
 
// Quicksort randomized partition to rearrange elements across pivot
int randPartition(int a[], int low, int high)
{
    // choose a random index between `[low, high]`
    int pivotIndex = rand() % (high - low + 1) + low;
 
    // swap the end element with the element present at a random index
    swap(a[pivotIndex], a[high]);
 
    // call the partition procedure
    return partition(a, low, high);
}
 
// Function to perform heapsort on the given range of elements
void heapsort(int *begin, int *end)
{
    make_heap(begin, end);
    sort_heap(begin, end);
}
 
// Function to perform introsort on the given array
void introsort(int a[], int *begin, int *end, int maxdepth)
{
    // perform insertion sort if partition size is 16 or smaller
    if ((end - begin) < 16) {
        insertionsort(a, begin - a, end - a);
    }
    // perform heapsort if the maximum depth is 0
    else if (maxdepth == 0) {
        heapsort(begin, end + 1);
    }
    else {
        // otherwise, perform Quicksort
        int pivot = randPartition(a, begin - a, end - a);
        introsort(a, begin, a + pivot - 1, maxdepth - 1);
        introsort(a, a + pivot + 1, end, maxdepth - 1);
    }
}
 
int main()
{
    int a[] = { 5, 7, -8, 9, 10, 4, -7, 0, -12, 1, 6, 2, 3, -4, -15, 12 };
    int n = sizeof(a) / sizeof(a[0]);
 
    // get the maximum depth
    int maxdepth = log(n) * 2;
 
    // sort the array using introsort the algorithm
    introsort(a, a, a + n - 1, maxdepth);
 
    // print the sorted array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
 
    return 0;
}
   



Is Introsort stable ? 
// Since Quicksort is also not stable so Introsort is also not stable. 
// Time Complexity Best Case – O(N log N) Average Case- O(N log N) Worse Case- O(N log N) where, N = number of elements to be sorted. Auxiliary Space Just like quicksort, it may use O(log N) auxiliary recursion
// stack space
