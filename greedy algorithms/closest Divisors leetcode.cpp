// Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.

// Return the two integers in any order.

 

// Example 1:

// Input: num = 8
// Output: [3,3]
// Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
// Example 2:

// Input: num = 123
// Output: [5,25]
// Example 3:

// Input: num = 999
// Output: [40,25]
 

// Constraints:

// 1 <= num <= 10^9



class Solution {
public:
    vector<int> closestDivisors(int num) {
        int res = INT_MAX ; 
        int first = 0 , second = 0 ;
        int x = num + 1 ; 
        int y = num + 2 ; 
        for(int i = 1; i<=sqrt(y);i++){
            if(x%i==0){
                if(abs(i-x/i)<res){
                    first = i ; 
                    second = x/i;
                    res = abs(i-x/i);
                }
            }
            if(y%i==0){
                if(abs(i-y/i)<res){
                    first = i ; 
                    second = y/i;
                    res = abs(i-y/i);
                }
            }
        }
        return {first,second};
    }
};
