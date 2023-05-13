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

				
             
             
