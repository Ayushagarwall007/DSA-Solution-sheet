// You are given a string num consisting of digits only.

// Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.

// Notes:

// You do not need to use all the digits of num, but you must use at least one digit.
// The digits can be reordered.
 

// Example 1:

// Input: num = "444947137"
// Output: "7449447"
// Explanation: 
// Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
// It can be shown that "7449447" is the largest palindromic integer that can be formed.
// Example 2:

// Input: num = "00009"
// Output: "9"
// Explanation: 
// It can be shown that "9" is the largest palindromic integer that can be formed.
// Note that the integer returned should not contain leading zeroes.
 

// Constraints:

// 1 <= num.length <= 105
// num consists of digits.


class Solution {
public:
    string largestPalindromic(string num) {
        vector<int>cnt(10);
        for(char c:num)
        {
            cnt[c-'0']++;
        }
        string lp,rp; //left and right partition
            for(int i:num)
            {
                for(int j=9;j>=0;j--)
                {
                    if(cnt[j]>1 and (j>0||lp.size()))
                    {
                        lp+='0'+j;
                        rp+='0'+j;
                        cnt[j]-=2;
                        break;
                    }
                }
            }
         for (int i = 9; i >= 0; i--) {
            if (cnt[i]) {
                lp += '0' + i; break;
            }}
        reverse(rp.begin(),rp.end());
            return lp+rp;
        
    }
};
