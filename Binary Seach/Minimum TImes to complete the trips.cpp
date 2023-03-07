// You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

// Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

// You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. Return the minimum time required for all buses to complete at least totalTrips trips.

 

// Example 1:

// Input: time = [1,2,3], totalTrips = 5
// Output: 3
// Explanation:
// - At time t = 1, the number of trips completed by each bus are [1,0,0]. 
//   The total number of trips completed is 1 + 0 + 0 = 1.
// - At time t = 2, the number of trips completed by each bus are [2,1,0]. 
//   The total number of trips completed is 2 + 1 + 0 = 3.
// - At time t = 3, the number of trips completed by each bus are [3,1,1]. 
//   The total number of trips completed is 3 + 1 + 1 = 5.
// So the minimum time needed for all buses to complete at least 5 trips is 3.
// Example 2:

// Input: time = [2], totalTrips = 1
// Output: 2
// Explanation:
// There is only one bus, and it will complete its first trip at t = 2.
// So the minimum time needed to complete 1 trip is 2.
 

// Constraints:

// 1 <= time.length <= 105
// 1 <= time[i], totalTrips <= 107



class Solution {
public:
long long check(vector<int>&a,long long givenTime)
{
    long long int totalTrips=0;
    for(auto x:a)
    {
        long long int val=x;
        totalTrips+=(givenTime/val);
    }
    return totalTrips;
}
    long long minimumTime(vector<int>& arr, int totalTrips) {
        long long low=1;
        long long high=1e14;
        while(low<high)
        {
            long long int mid=low+(high-low)/2;
            if(check(arr,mid)>=totalTrips)
            {
                high=mid;
            }
            else
            low=mid+1;
        }
        return low;
    }
};


// In this question , we have to find minimum time

// let's take the lowestTime can be 1 and highestTime can be as large as 1e14 (10^14) ,
// now we will find for given mid what will be the answer (which is to count totalTrips at time = mid)
// if we get number of trips >= requiredTrips , then we have to decrease the time , that is why I moved my right pointer which is highestTime ,
// if we get number of trips < requiredTrips , then we have to increase the time , that is why I moved my left pointer which is lowestTime
// finally return lowestTime
