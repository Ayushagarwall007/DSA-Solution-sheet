// we have given the sorted array of size N and the element K . we must have to subtract each element from the key element and must have  to return the element
// with the minimum absolute  differnece from the each dofference.


// if the key elemnt is present in the array than the answer is key element as the difference is zero and if the key element is not present in the array than the 
// result is the element which is present near to the key element as the minimum difference is obtained from the element present near to the key element.

#include<bits/stdc++.h>
using namespace std;

int bs(int arr[],int key,int r)
{
    int l=0;
    // int r=sizeof(arr)/sizeof(arr[0])-1;
    int result=-1;
    while(l<=r)
    {
        int mid= l+(r-l)/2;
        if(arr[mid]==key)
        {
            return key;
            
        }
        else if(arr[mid]>key)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    int res1= abs(arr[r]-key);
    int res2= abs(arr[l]-key);
    if(res1<res2)
    return arr[r];
    else
    {
    return arr[l];
    }    
}

int main()
{
    int arr[]={1,3,8,10,13,15};
     int r=sizeof(arr)/sizeof(arr[0])-1;
    int key=12;
    int result= bs(arr,key,r);
    cout<<result<<endl;
    return 0;
}
