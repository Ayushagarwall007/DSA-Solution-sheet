// 386. Lexicographical Numbers
// Medium

// 1445

// 122

// Add to List

// Share
// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

// Example 1:

// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
// Example 2:

// Input: n = 2
// Output: [1,2]
 

// Constraints:

// 1 <= n <= 5 * 104



class TrieNode
{
    public:
    vector<TrieNode*> next;
    bool isword;
    int data;
    
    TrieNode()
    {
        next.resize(10,NULL);
        isword=false;
        data=-1;
    }
    
};


class Solution {
public:
    TrieNode* root = new TrieNode();
    vector<int> ans;
    void printAll(TrieNode* root)
    {
        if(root->isword){
            ans.push_back(root->data);
        }
        for(int i=0;i<10;i++){
            if(root->next[i])
                printAll(root->next[i]);
        }
    }
    void insert(int num)
    {
        string s= to_string(num);
        TrieNode *p=root;
        for(int i=0;i<s.size();i++)
        {
            if(p->next[s[i]-'0']==NULL)
                p->next[s[i]-'0'] = new TrieNode();
            p=p->next[s[i]-'0'];
        }
        p->data=num;
        p->isword=true;
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=n;i++)
            insert(i);
            printAll(root);
            return ans;
        
    }
};
