// 72. Edit Distance
// Hard
// 10.4K
// 116
// Companies
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 

// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.



class Solution {
public:
    int solve(string word1,string word2 ,int i,int j)
    {
        if(i==word1.size())
        return word2.size()-j;

        if(j== word2.size()) return word1.size()-i;

        if(word1[i]==word2[j]) return solve(word1,word2,i+1,j+1);
        else
        {
            int insertAns=solve(word1,word2,i,j+1);
            int replaceAns=solve(word1,word2,i+1,j+1);
            int DeleteAns=solve(word1,word2,i+1,j);

            return min(insertAns,min(replaceAns,DeleteAns))+1;
        }
    }
    int minDistance(string word1, string word2) {
        return solve(word1,word2,0,0);
    }
};
