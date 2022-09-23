https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


class TrieNode
{
    public:
    char data;
    TrieNode* childern[26];
    bool isTerminal;
    
    TrieNode(char ch)
    {
        data = ch;
        for(int i=0;i<26;i++)
        {
            childern[i]=NULL;
            
        }
        isTerminal=false;
    }
};
class Trie
{
    public:
    TrieNode* root;
    
    Trie()
    {
        root=new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word)
    {
        // base case
        if(word.size()==0){root->isTerminal=true;  return;}
        int index=word[0]-'a';
        TrieNode* child;
        // present
        if(root->childern[index]!=NULL)
        child=root->childern[index];
        
        else  // not present
        {
            child=new TrieNode(word[0]);
            root->childern[index]=child;
        }
        
        // recursion
        insertUtil(child,word.substr(1));
        
        
        
    }
    
    
    void insertWord(string word)
    {
        insertUtil(root,word);
    }
    
    
    void printSuggestions(TrieNode* curr, vector<string>&temp , string prefix)
    {
        if(curr->isTerminal)
        {
            temp.push_back(prefix);
        }
        for(char ch= 'a'; ch<='z';ch++)
        {
            TrieNode* next= curr->childern[ch-'a'];
            if(next!=NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string> > getSuggestions(string str)
    {
        TrieNode* prev=root;
        vector<vector<string>> output;
        string prefix="";
        for(int i=0;i<str.length();i++)
        {
            char lastch=str[i];
            prefix.push_back(lastch);
            
            
//             check for the last character
            TrieNode* curr= prev->childern[lastch-'a'];
            
            // if not found
            if(curr==NULL)
            {
                break;
            }
           // if found
            vector<string>temp;
        printSuggestions(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return output;
        
    }
    
   
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie *t=new Trie();
    
    //insert all the contact in trie
    for(int i=0;i<contactList.size();i++)
    {
        string str= contactList[i];
        t->insertWord(str);
    }
    
    return t->getSuggestions(queryStr);
    
}
