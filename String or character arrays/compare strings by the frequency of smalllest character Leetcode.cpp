// Let the function f(s) be the frequency of the lexicographically smallest character in a non-empty string s. For example, if s = "dcce" then f(s) = 2 because the lexicographically smallest character is 'c', which has a frequency of 2.

// You are given an array of strings words and another array of query strings queries. For each query queries[i], count the number of words in words such that f(queries[i]) < f(W) for each W in words.

// Return an integer array answer, where each answer[i] is the answer to the ith query.

 

// Example 1:

// Input: queries = ["cbd"], words = ["zaaaz"]
// Output: [1]
// Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
// Example 2:

// Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
// Output: [1,2]
// Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
 

// Constraints:

// 1 <= queries.length <= 2000
// 1 <= words.length <= 2000
// 1 <= queries[i].length, words[i].length <= 10
// queries[i][j], words[i][j] consist of lowercase English letters.





class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words)
    {
        int map[26]={0};
        int freq[11]={0};
        for(int i=0; i<words.size(); i++)
        {
            if(i!=0)
                memset(map, 0, sizeof(map));

            char minChar=words[i][0];
            for(auto& z:words[i]) // extraxcting the minimum character from the words in the lexicographical order
            {
                if(z<minChar)
                    minChar=z;

                map[z-'a']++;
            }

            for(int j=1; j<map[minChar-'a']; j++)
                freq[j]++;
        }

        vector<int> ans;

        for(int i=0; i<queries.size(); i++)
        {
            memset(map, 0, sizeof(map));

            char minChar=queries[i].at(0);
            for(auto& z:queries[i])
            {
                if(z<minChar)
                    minChar=z;

                map[z-'a']++;
            }

            cout<<minChar;
            ans.push_back(freq[map[minChar-'a']]);
        }

        return ans;
    }
};
