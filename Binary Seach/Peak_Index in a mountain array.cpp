// An array arr a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    int start=1, end=(arr.size()-2);int mid; 
// I have started start with 1 and end with n-2 bcz we already know that the peak element can't be in the beginning or end. 
// Also, it will save us from reaching maxbuffer, bcz if mid is at extreme left and we compare arr[mid] with arr[mid-1], it is maxbuffer error. 
// Now, simply check if an element is greater than both it's left and right, it is peak. If it is greater than the left element, then end =mid-1, else start = mid+1.
    while(start<=end){
          mid=start+((end-start)/2);
        if((arr[mid] > arr[mid-1]) && (arr[mid] > arr[mid+1])){
            break;
        }
        else if(arr[mid] > arr[mid-1]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
       
    } 
    return mid;
    }
};






#include<vector>
using namespace std;

class Solution {
public:
  
    int find_pivot(vector<int> v) {
	int s = 0, e = v.size() - 1;
	int mid=(s + e) / 2;
	while (s < e)
	{
		if(v[mid] < v[mid+1])
     			s=mid+1;
    		else
      			e = mid;
    
		mid = (s + e) / 2;
	}
	return s;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return find_pivot(arr);
    }
};
 
