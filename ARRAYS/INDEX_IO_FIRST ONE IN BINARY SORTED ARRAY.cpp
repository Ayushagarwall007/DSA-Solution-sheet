// the array size is initially infinite      000000000000000001111111111111111111...........      <- sorted binary array

// we will first use the technique of finding the elemetn ie 1 in an infinite sorted array and then use the technique of finding the first 
// occurence of the element in the sorted array using the Binary search

#include<bits/stdc++.h>
using namespace std;

int index_of_one(int num[],int start,int end)
{
    int mid=start+(end-start)/2;
    int result=-1;
    
    while(start<=end)
    {
            if(num[mid]==1)
            {
            result=mid;
            end=mid-1;
            }
            else if(num[mid]>=1)
            {
                end=mid-1;
            }
            else
            {
                start= mid+1;
            }
            mid=start+(end-start)/2;
    }
    return result;
}

int posOfFirstOne(int arr[])// this function will find out the end points for the index of 1 from the infininte length array
{
    int s=0 , e =1;
    while(arr[e]>=1)
    {
        s=e;
        e=e*2;
    }
    return index_of_one(arr,s,e);
}

int main()
{
    int arr[] = { 0, 0, 1, 1, 1, 1 };
    cout << "Index = "<< posOfFirstOne(arr);
    return 0;
}
