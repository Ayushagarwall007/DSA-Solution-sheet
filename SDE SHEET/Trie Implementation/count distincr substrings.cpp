// According to the problem we are given a string str, we must count all the substrings in the given string. Substring is a string which is a part of an already existing string whose size may be smaller than or equal to the existing string.

// Let's understand the problem and its solution with the help of examples.

// Input − str = "wxyz";

// Output − count of distinct substring is: 10

// Explanation − Distinct substrings counted are −

// wxyz, wxy, wx, w, xyz, xy, x, yz, y, z so their count is 10
// Input − str = "zzzz"

// Output − count of distinct substring is: 4

// Explanation − Distinct substrings counted are −

// zzzz, zzz, zz, z


class Node
{
    public:
    Node* child[26];
};
class Trie{
    Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(string &s , int &ans)
    {
        Node* node=root;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(node->child[s[i]-'a']==NULL)
            {
                node->child[s[i]-'a']=new Node();
                ans++;
            }
            node=node->child[s[i]-'a'];
        }
    }
};
int countDistinctSubstrings(string &s)
{
    Trie* root=new Trie();
    int n=s.size();
    int ans=0;
    string st="";
    for(int i=n-1;i>=0;i--)
    {
        st=s[i]+st;
        root->insert(st,ans);
    }
    return ans+1;
}
