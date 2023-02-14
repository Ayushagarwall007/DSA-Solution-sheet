// Design a data structure that supports adding new words and finding if a string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

// Example:

// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True
 

// Constraints:

// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 3 dots in word for search queries.
// At most 104 calls will be made to addWord and search.











// First we need to create our TrieNode class
class TrieNode
{
public:
    bool is_leaf;
	 // as we only need to store lower case english letters, we only need an array with 26 size
	 // it's a good trick to use when we need to store only letters, because we can do it with O(1) in space for each node
	 // so, we have a linked list, where which node will store only a character.
    TrieNode* children[26];
    TrieNode()
    {
        is_leaf = false; // it'll be used to define if you get the word or not
		// because if you get is_leaf = true, it means that you got all the word
		
		// all children will be initialize being 0
		// it's the same as use a loop, like: for (int i = 0; i < 26; i++) children[i] = 0;
        memset(children, 0, sizeof(children)); 
    }
};

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
			// if we already have put a specific letter in a specific level, we don't need to create another node
			// for example, in 'dog' and 'dag', as we have 'd' in the same position, 
			// we can use the same node which store 'd' to be the parent of 'o' and 'a'
            if (!node->children[c - 'a'])
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
		// as we achieved the last node, this will be our leaf node
        node->is_leaf = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
		// we want a search function which has other parameters, so we'll create a private search function
        return search(word, root, 0);
    }

private:
    TrieNode *root; // our private root

    bool search(string word, TrieNode *node, int pos)
    {
		// in our recursion, first we need to code our stop condition
        if(pos == word.size())
            return node->is_leaf;
       
	   // if there's no '.', we can just iterate in our linked list
        if (word[pos] != '.'){
            node = node->children[word[pos] - 'a'];
			// this 'node' before the search is to avoid unnecessary recursion calls (if node is null, the linked list was ended up)
			// we increment our 'pos' by 1, in order to search the next character, if it exists
            return node && search(word, node, pos + 1);
        }
        
		// if there's a '.', we need to force iteration in all possible cases
        for (int i = 0; i < 26; i++)
			// 'node->children[i]' is here to avoid unnecessary recursion calls (if this node->children[i] is null, the linked list was ended up)
            if(node->children[i] && search(word, node->children[i], pos + 1))
                return true;
        return false;        
    }
};
