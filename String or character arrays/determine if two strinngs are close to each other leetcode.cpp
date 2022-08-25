// 1657. Determine if Two Strings Are Close

// Two strings are considered close if you can attain one from the other using the following operations:

// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb
// Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
// You can use the operations on either string as many times as necessary.

// Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

// Example 1:

// Input: word1 = "abc", word2 = "bca"
// Output: true
// Explanation: You can attain word2 from word1 in 2 operations.
// Apply Operation 1: "abc" -> "acb"
// Apply Operation 1: "acb" -> "bca"
// Example 2:

// Input: word1 = "a", word2 = "aa"
// Output: false
// Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
// Example 3:

// Input: word1 = "cabbba", word2 = "abbccc"
// Output: true
// Explanation: You can attain word2 from word1 in 3 operations.
// Apply Operation 1: "cabbba" -> "caabbb"
// Apply Operation 2: "caabbb" -> "baaccc"
// Apply Operation 2: "baaccc" -> "abbccc"
 

// Constraints:

// 1 <= word1.length, word2.length <= 105
// word1 and word2 contain only lowercase English letters.



class Solution {
public:
    bool closeStrings(string str1, string str2) {
        
       int n1=str1.size();
        int n2= str2.size();
        
        if(n1!=n2)return false;
        
        vector<int> hash1(26,0);
        vector<int>hash2(26,0);
        
        
        for(int i=0;i<n1;i++)
        {
            hash1[str1[i]-'a']++;
            hash2[str2[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(hash1[i]==0 and hash2[i])return false;
            if(hash1[i] && hash2[i] == 0) return false;
        }
        
        
        unordered_map<int ,int>mp1;
        unordered_map<int,int> mp2;
        
        for(int i=0;i<26;i++)
        {
            mp1[hash1[i]]++;
            mp2[hash2[i]]++;
        }
        
        for(auto  x : mp1)
        {
            if(x.second!=mp2[x.first])return false;
        }
       
        for(auto x : mp2)
        {
            if(x.second != mp1[x.first])
                return false;
        }  
            
        return true;
    }
};
