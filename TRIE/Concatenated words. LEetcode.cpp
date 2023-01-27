// Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

 

// Example 1:

// Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
// "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
// Example 2:

// Input: words = ["cat","dog","catdog"]
// Output: ["catdog"]
 

// Constraints:

// 1 <= words.length <= 104
// 1 <= words[i].length <= 30
// words[i] consists of only lowercase English letters.
// All the strings of words are unique.
// 1 <= sum(words[i].length) <= 105



class TrieNode{
    public:
    vector<TrieNode*>childern;
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        childern=vector<TrieNode*>(26,NULL);
    }
};

class Trie
{
    private:
    TrieNode* root;
    public:
    TrieNode* getRoot()
    {
        return root;
    }
    Trie(vector<string>&words)
    {
        root=new TrieNode();
        for(auto & word:words)insert(word);
    }
    void insert(string & word)
    {
        auto cur=root;
        for(int i=0;i<word.size();i++)
        {
            int index=word[i]-'a';
            if(cur->childern[index]==NULL)
            {
                cur->childern[index]=new TrieNode();

            }
            cur=cur->childern[index];
        }
        cur->isEnd=true;
    }
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie* trie = new Trie(words);
        vector<string>result;
        for(auto &word:words)
        {
            int index=0,concatenatedWordCount=0;
            if(isConcatenatedWord(trie,word,index,concatenatedWordCount))
            {
                result.push_back(word);
            }
        }
        return result;

    }
    bool isConcatenatedWord(Trie* trie,string & word,int index,int concatenatedWordCount)
    {
        if(index==word.size())return concatenatedWordCount>=2;
        auto root=trie->getRoot();
        for(int i=index;i<word.size();i++)
        {
            int trieIndex=word[i]-'a';

            if(root->childern[trieIndex]==NULL)return false;
            root=root->childern[trieIndex];

            if(root->isEnd)
            {
                if(isConcatenatedWord(trie,word,i+1,concatenatedWordCount+1))
                {
                    return true;
                }
            }
        }
        return false;
    }

};
