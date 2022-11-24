// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

 

// Example 1:

// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
// Example 2:

// Input: s = "ababbc", k = 2
// Output: 5
// Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

// Constraints:

// 1 <= s.length <= 104
// s consists of only lowercase English letters.
// 1 <= k <= 105



class Solution {
public:
    int solve(string s, int start, int end, int k){
        if(end-start < k) return 0;
        vector<int>arr(26, 0);
        for(int i = start; i < end; i++){
            arr[s[i]-'a']++;
        }
        for(int i = start; i < end; i++){
            if(arr[s[i]-'a'] < k){
                int j = i+1;
                while(j < end && arr[s[j]-'a'] < k){
                    j++;
                }
                return max(solve(s,start,i,k),solve(s,j,end,k));
            }
        }
        return end-start;
    }
    
    int longestSubstring(string s, int k) {
        return solve(s,0,s.size(),k);
    }
};
