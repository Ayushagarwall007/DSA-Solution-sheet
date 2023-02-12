// Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].

 

// Example 1:

// Input: nums = [5,2,6,1]
// Output: [2,1,1,0]
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
// Example 2:

// Input: nums = [-1]
// Output: [0]
// Example 3:

// Input: nums = [-1,-1]
// Output: [0,0]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104


class Solution {
public:
  void merge(vector<int>&cnt,vector<pair<int,int>>&v,int low,int mid,int high ){
      vector<pair<int,int>>tmp(high-low+1);
      int i=low,j=mid+1,k=0;
      while(i<=mid and j<=high){
          if(v[i].first<=v[j].first){
              tmp[k++]=v[j++];
          }
          else {
              cnt[v[i].second]+=high-j+1;
              tmp[k++]=v[i++];
          }
      }
      while(i<=mid){
          tmp[k++]=v[i++];
      }
      while(j<=high){
          tmp[k++]=v[j++];
      }
      for(int i=low;i<=high;i++)v[i]=tmp[i-low];
  }
   void mergesort(vector<int>&cnt,vector<pair<int,int>>&v,int low ,int high){
       if(low<high){
      int mid= low+(high-low)/2;
       mergesort(cnt,v,low,mid);
       mergesort(cnt,v,mid+1,high);
       merge(cnt,v,low,mid,high);
       }
   }
    vector<int> countSmaller(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }
         vector<int>ans(n,0);
         mergesort(ans,v,0,n-1);
        return ans;
    }
};
