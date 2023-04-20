// Given a string word to which you can insert letters "a", "b" or "c" anywhere and any number of times, return the minimum number of letters that must be inserted so that word becomes valid.

// A string is called valid if it can be formed by concatenating the string "abc" several times.

 

// Example 1:

// Input: word = "b"
// Output: 2
// Explanation: Insert the letter "a" right before "b", and the letter "c" right next to "a" to obtain the valid string "abc".
// Example 2:

// Input: word = "aaa"
// Output: 6
// Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".
// Example 3:

// Input: word = "abc"
// Output: 0
// Explanation: word is already valid. No modifications are needed. 
 

// Constraints:

// 1 <= word.length <= 50
// word consists of letters "a", "b" and "c" only. 



class Solution {
public:
    int addMinimum(string word) {
        int n=word.size();
        int i=0;
        int ans=0;
        while(i<n)
        {
            if(word.substr(i,3)=="abc")
            i+=3;
            else if(word.substr(i,2)=="ab" or word.substr(i,2)=="bc" or word.substr(i,2)=="ac")
            {
                ans+=1;
                i+=2;
            }
            else
            {
                ans+=2;
                i++;
            }
        }
        return ans;
    }
};
