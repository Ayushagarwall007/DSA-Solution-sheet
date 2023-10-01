// We have an horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = size of the stations array. Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of D. Find the answer exactly to 2 decimal places.

// Example 1:

// Input:
// N = 10
// stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// K = 9
// Output: 0.50
// Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
// Example 2:

// Input:
// N = 10
// stations = [3,6,12,19,33,44,67,72,89,95]
// K = 2
// Output: 14.00
// Explanation: Construction of gas stations at 86 locations
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findSmallestMaxDist() which takes a list of stations and integer K as inputs and returns the smallest possible value of D. Find the answer exactly to 2 decimal places.

// Expected Time Complexity: O(N*log K)
// Expected Auxiliary Space: O(1)

// Constraint:
// 10 <= N <= 5000 
// 0 <= stations[i] <= 109 
// 0 <= K <= 105






class Solution {
  public:
  bool isValid(vector<int>&stations,int K , double distance , int n)
  {
      int new_stations=0;
      for(int i=1;i<n;i++)
      {
          new_stations+=floor((stations[i]-stations[i-1])/distance);
      }
      return new_stations<=K;
  }
    double findSmallestMaxDist(vector<int> &stations, int K){
      
      int n=stations.size();
      double start=0;
      double end=stations[n-1]-stations[0];
      while(end-start>1e-6)
      {
          double mid=start+(end-start)/2.0;
          if(isValid(stations,K,mid,n))
          end=mid;
          else
          start=mid;
      }
      return start+0.000001;
    }
    
    
};w
