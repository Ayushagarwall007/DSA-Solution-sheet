// Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

// An integer y is a power of three if there exists an integer x such that y == 3x.

 

// Example 1:

// Input: n = 12
// Output: true
// Explanation: 12 = 31 + 32
// Example 2:

// Input: n = 91
// Output: true
// Explanation: 91 = 30 + 32 + 34
// Example 3:

// Input: n = 21
// Output: false


class Solution {
public:

    bool checkPowersOfThree(int sum) {
        
        vector<int> arr;
        
        // push all the elements into array which is less than sum and pow of 3
        
        long long x = 1;
        
        while(x <=  sum)
        {
            arr.push_back(x);
            
            x = x * 3;
        }
        
        int n = arr.size();
        
        // reverse the array
        
        reverse(arr.begin(), arr.end());
        
        // now start picking the element, untill sum > 0
    
        int i = 0;
        
        while(i < n && sum > 0)
        {
            if(arr[i] <= sum)
            {
                sum -= arr[i];
            }

            i++;
        }
        
        // if sum == 0, return true
        
        return sum == 0;
    }
};
