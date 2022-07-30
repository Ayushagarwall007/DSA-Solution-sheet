// You are given two string arrays words1 and words2.

// A string b is a subset of string a if every letter in b occurs in a including multiplicity.

// For example, "wrr" is a subset of "warrior" but is not a subset of "world".
// A string a from words1 is universal if for every string b in words2, b is a subset of a.

// Return an array of all the universal strings in words1. You may return the answer in any order.

 

// Example 1:

// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
// Output: ["facebook","google","leetcode"]
// Example 2:

// Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
// Output: ["apple","google","leetcode"]
 

// Constraints:

// 1 <= words1.length, words2.length <= 104
// 1 <= words1[i].length, words2[i].length <= 10
// words1[i] and words2[i] consist only of lowercase English letters.
// All the strings of words1 are unique.


class Solution {
    private:
    unordered_map<char,int>getFreqMap(string s)
    {
        unordered_map<char ,int>freq;
        for(char ch:s)
        {
            freq[ch]++;
            
        }
        return freq;
    }
    
    
    bool isSubset(unordered_map<char,int>b , unordered_map<char,int>a)
    {
        for(auto entry:b)
        {
            if(entry.second>a[entry.first]) return false;
        }
        return true;
    }
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
       vector<string>res;
        unordered_map<char,int>freq;
        for(string word2:words2)
        {
            vector<int>temp(26,0);
            for(char ch:word2)
            {
                temp[ch-'a']++;
                freq[ch]=max(freq[ch],temp[ch-'a']);
            }
        }
        for(string word1:words1)
        {
            unordered_map<char,int>word1_freq=getFreqMap(word1);
            bool flag=true;
            if(isSubset(freq,word1_freq))
                res.push_back(word1);
        }
        return res;
    }
};
