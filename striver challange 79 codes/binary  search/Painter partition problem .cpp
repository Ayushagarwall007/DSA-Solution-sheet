// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

// The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.


// Example 1:

// Input:
// n = 5
// k = 3
// arr[] = {5,10,30,20,15}
// Output: 35
// Explanation: The most optimal way will be:
// Painter 1 allocation : {5,10}
// Painter 2 allocation : {30}
// Painter 3 allocation : {20,15}
// Job will be done when all painters finish
// i.e. at time = max(5+10, 30, 20+15) = 35
// Example 2:

// Input:
// n = 4
// k = 2
// arr[] = {10,20,30,40}
// Output: 60
// Explanation: The most optimal way to paint:
// Painter 1 allocation : {10,20,30}
// Painter 2 allocation : {40}
// Job will be complete at time = 60

// Your task:
// Your task is to complete the function minTime() which takes the integers n and k and the array arr[] as input and returns the minimum time required to paint all partitions.


// Expected Time Complexity: O(n log m) , m = sum of all boards' length
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ n ≤ 105
// 1 ≤ k ≤ 105
// 1 ≤ arr[i] ≤ 105




bool isValid(vector<int> &boards, int k,int mid,int n)
{
    int painter=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(boards[i]>mid)return false;
        sum=sum+boards[i];
        if(sum>mid)
        {
            painter++;
            sum=boards[i];
        }
    }
    return painter<=k;
    
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int start =0;
    int sum=0;
    int n= boards.size();
    for(int i=0;i<n;i++)
    {
        sum=sum+boards[i];
    }
    int end=sum;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isValid(boards,k,mid,n))
        end=mid-1;
        else
        {
            start=mid+1;
        }
    }
    return start;
}

