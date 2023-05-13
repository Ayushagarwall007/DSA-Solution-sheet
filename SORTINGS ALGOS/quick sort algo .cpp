// How does QuickSort work?
// The key process in quickSort is a partition(). The target of partitions is to place the pivot (any element can be chosen to be a pivot) at its correct position in the sorted array and put all smaller elements to the 
// left of the pivot, and all greater elements to the right of the pivot.

// This partition is done recursively which finally sorts the array. See the below image for a better understanding.

Quicksort's best-case time complexity is O (n*logn) .

#include<bits.stdc++.h>
using namespace std;
int partion(int arr[],int s,int e)
{
// 	taking the 0th index as the pivot element
	int pivot=arr[s];
	int cnt=0;
// 	counting the number of elements samller than the pivot element
	for(int i=s+1;i<=e;i++)
		if(arr[i]<pivot)cnt++;
	
// 	now placing the pivot element at the right position
	int pivotIndex=s+cnt;
	swap(arr[pivotIndex],arr[s]);
// aab left or right part ke elements to ajust kaar dete hai.		 
	int i=s;
	int j=e;	 
	while(i<pivotIndex and j>pivotIndex)
	{
		while(arr[i]<=pivot)i++;
		while(arr[j]>pivot)j--;
		if(i<pivotIndex and j>pivotIndex)
		{
			swap[arr[i++],arr[j--])
		}
	}
				 return pivotIndex;
}
void quickSort(int arr[],int s,int e)
{
	if(s>=e)return;
	int p=partiton(arr,s,e);
	quickSort(arr,s,p-1);
	quickSort(arr,p+1,e);
}
int main() {

    int arr[10] = {2,4,1,6,9 ,9,9,9,9,9};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


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
			     
			     
			     
			     
             
             
