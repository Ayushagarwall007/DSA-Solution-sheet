// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

// Constraints:

// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.




// iss question mai humm phle humm saare words koo set data structure mai rakhenge or phir humm start word ko queue mai rakhene or phla word uthayenge or uske hurr ek character kaa combination ko a se z tkk change kaarke
// dekhenge or phir checj kaarenge ki vo set mai present hai ki nahi agar hai to queue mai push kaar denge or set se remove kaar denge agar queue emoty ho gyi or humme targetword nahi milaa to humm 0 return kaar denge nahi 
// too hum number of steos retur nkaar denge
class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({startWord,1});
        set<string>st(wordList.begin(),wordList.end());
        st.erase(startWord);
        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;

            q.pop();

            if(word==targetWord)return steps;
            for(int i=0;i<word.size();i++)
            {
                int originalChar=word[i];
                for(int ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=originalChar;
            }
        }
        return 0;

    }
};
