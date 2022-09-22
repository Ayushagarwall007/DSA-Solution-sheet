// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

// Example 1:

// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True
 

// Constraints:

// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 104 calls in total will be made to insert, search, and startsWith.



struct TrieNode
{
    TrieNode * next[26]={};
    bool isWord=false;
};

class Trie {
    TrieNode root;   
public:
    Trie() {
     
    }
    
    void insert(string word) {
        auto node=&root;
        for(int i=0;i<word.size();++i)
        {
            if(!node->next[word[i]-'a'])
                node->next[word[i]-'a']=new TrieNode();
            node=node->next[word[i]-'a'];
        }
        node->isWord=true;
    }
    
    bool search(string word) {
        auto node=&root;
        for(int i=0;i<word.size();++i)
        {
            if(!node->next[word[i]-'a'])
               return false;
            node=node->next[word[i]-'a'];
        }
        if(!node->isWord)
            return false;
        return true;
    }
    
    bool startsWith(string p) {
        auto node=&root;
        for(int i=0;i<p.size();++i)
        {
            if(!node->next[p[i]-'a'])
               return false;
            node=node->next[p[i]-'a'];
        }
         return true;
    }
};
