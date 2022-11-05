// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

// Example 1:


// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:


// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.
class TrieNode
{
public:
    vector<TrieNode*> children;
    bool endOfWord;
    
    TrieNode()
    {
        children.resize(26, nullptr);
        endOfWord = false;
    }
    
    ~TrieNode(){}
    
    void addWord(string word)
    {
        if(word.length() == 0)
            return;
            
        TrieNode* node = this;
        for(int i=0; i<word.length(); i++)
        {
            if(node->children[word[i]-'a'])
                node = node->children[word[i]-'a'];
            else
            {
                node->children[word[i]-'a'] = new TrieNode();
                node = node->children[word[i]-'a'];
            }
        }
        
        node->endOfWord = true;
    }
};

class Solution {
public:
    int m;
    int n;
    
    void findWordsHelper(vector<vector<char>>& board, TrieNode* node, int x, int y, string& s, vector<string>& result)
    {
        if(x<0 || y<0 || x>=m || y>=n || node == nullptr || board[x][y] == '\0')
            return;
            
        char t = board[x][y];
        if(node->children[t-'a'] == nullptr)
            return;
        
        s.push_back(t);
        node = node->children[t-'a'];
        board[x][y] = '\0';
        if(node->endOfWord)
        {
            result.push_back(s);
            node->endOfWord = false; // already been picked up
        }
        
        findWordsHelper(board, node, x-1, y, s, result);
        findWordsHelper(board, node, x+1, y, s, result);
        findWordsHelper(board, node, x, y-1, s, result);
        findWordsHelper(board, node, x, y+1, s, result);
        
        board[x][y] = t;
        s.pop_back();
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = new TrieNode();
        int i, x, y;
        for(i=0; i<words.size(); i++)
            root->addWord(words[i]);
            
        m = board.size();
        n = board[0].size();
        string s;
        vector<string> result;
        for(x=0; x<m; x++)
            for(y=0; y<n; y++)
            {
                findWordsHelper(board, root, x, y, s, result);
            }
            
        return result;
    }
};
