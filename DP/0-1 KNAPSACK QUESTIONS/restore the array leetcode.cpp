// A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

// Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: s = "1000", k = 10000
// Output: 1
// Explanation: The only possible array is [1000]
// Example 2:

// Input: s = "1000", k = 10
// Output: 0
// Explanation: There cannot be an array that was printed this way and has all integer >= 1 and <= 10.
// Example 3:

// Input: s = "1317", k = 2000
// Output: 8
// Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only digits and does not contain leading zeros.
// 1 <= k <= 109
class Solution {
public:
    int MOD = 1000000007;
    int solve(string& s, int& k, vector<int>&dp, int startIdx)
    {
        if (startIdx == s.size()) return 1;
        
        if (dp[startIdx] != -1) return dp[startIdx]; //retrieve results
        long long currNum = 0, ways = 0;
        //=================================================
        for (int i = startIdx; i < s.size(); i++)
        {
            int currDig = s[i] - '0';
            currNum = (currNum * 10) + currDig; //building the number from L->R

            if (currNum < 1 || currNum > k) break;
            int nextWays = solve(s, k, dp, i + 1);
            ways = (ways +  nextWays) % MOD;
        }
        //====================================================
        return dp[startIdx] = ways; //store results
    }
    int numberOfArrays(string s, int k) 
    {
        vector<int>dp(s.size(), -1);
        int ans = solve(s, k, dp, 0);
        return ans;
    }
};








class Solution {
public:
    int MOD = 1000000007;
    int numberOfArrays(string s, int k) 
    {
        int n = s.size();
        vector<int>dp(n + 1, 0);
        //In top down 
        //1) For string starting from startIdx
        //   we needed answers of strings starting from [startIdx+1, startIdx+2, ....]
        //2) Recursion did that for us
        
        //In bottom up
        //1) We need to pre-calculate the desired results first
        //2) So we will go from startIdx = n - 1 to startIdx = 0
        //3) Now for startIdx = x, we would already have answers stored for 
        //           startIdx = [x+1, x+2, x+3......]
        
        dp[n] = 1; //base case implemented here
        for (int startIdx = n - 1; startIdx >= 0; startIdx--)
        {
            long long currNum = 0, ways = 0;
            //=================================================
            for (int i = startIdx; i < s.size(); i++)
            {
                int currDig = s[i] - '0';
                currNum = (currNum * 10) + currDig; //building the number from L->R

                if (currNum < 1 || currNum > k) break;
                int nextWays = dp[i + 1]; 
                ways = (ways +  nextWays) % MOD;
            }
            //====================================================
            dp[startIdx] = ways;
        }
        return dp[0];
    }
};


