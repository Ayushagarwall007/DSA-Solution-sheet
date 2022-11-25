// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

// Example 1:

// Input: 
// N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}
// Output:
// 1
// Explanation:
// Here order of characters is 
// 'b', 'd', 'a', 'c' Note that words are sorted 
// and in the given language "baa" comes before 
// "abcd", therefore 'b' is before 'a' in output.
// Similarly we can find other orders.
// Example 2:

// Input: 
// N = 3, K = 3
// dict = {"caa","aaa","aab"}
// Output:
// 1
// Explanation:
// Here order of characters is
// 'c', 'a', 'b' Note that words are sorted
// and in the given language "caa" comes before
// "aaa", therefore 'c' is before 'a' in output.
// Similarly we can find other orders.
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


// Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
// Expected Space Compelxity: O(K)


// Constraints:
// 1 ≤ N, M ≤ 300
// 1 ≤ K ≤ 26
// 1 ≤ Length of words ≤ 50




// suppose in the given two words if the two characters are mismatching then the node is directed from the character of word 1 
// to the character of the word 2 that means the character of word 1 will come before the character of word2
class Solution{
    public:
    vector<int>toposort(int V,vector<int>adj[])
    {
        int indegree[V]={0};
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
            vector<int>topo;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                topo.push_back(node);
                for(auto it:adj[node])
                {
                    indegree[it]--;
                    if(indegree[it]==0)q.push(it);
                }
            }
        return topo;
    }
    string findOrder(string dict[], int N, int k) {
        vector<int>adj[k];
        for(int i=0;i<N-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            for(int i=0;i<len;i++)
            {
                if(s1[i]!=s2[i])
                {
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
            
        }
        vector<int>topo=toposort(k,adj);
        string ans="";
        for(auto it:topo)
        {
            ans=ans+char(it+'a');
        }
        return ans;
        
        
        
    }
};
