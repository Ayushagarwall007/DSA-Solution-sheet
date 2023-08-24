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




#include <bits/stdc++.h>
void dfs(int node, vector<bool> &visited, stack<int> &st, vector<int> adj[]) {

    visited[node] = true;

    for (int nbr : adj[node]) {

        if (!visited[nbr]) {

            dfs(nbr, visited, st, adj);

        }
    }
    st.push(node);
}
string getAlienLanguage(vector<string> &dictionary, int k) {
    vector<int> adj[k];

    for (int i = 0; i < dictionary.size() - 1; i++) {

        string s1 = dictionary[i];

        string s2 = dictionary[i + 1];

        int len = min(s1.size(), s2.size());

        for (int ptr = 0; ptr < len; ptr++) {

            if (s1[ptr] != s2[ptr]) {

                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');

                break;

            }

        }

    }

 

    // Perform topological sort using DFS

    stack<int> st;

    vector<bool> visited(k, false);

    for (int i = 0; i < k; i++) {

        if (!visited[i]) {

            dfs(i, visited, st, adj);

        }

    }

 

    // Extract characters from the stack to form the result

    string ans = "";

    while (!st.empty()) {

        ans += char(st.top() + 'a');

        st.pop();

    }

    return ans;

}


// string getAlienLanguage(vector<string> &dictionary, int k)
// {
//     vector<int>adj[k];
//     for(int i=0;i<dictionary.size()-1;i++)
//     {
//         string s1=dictionary[i];
//         string s2=dictionary[i+1];
//         int len=min(s1.size(),s2.size());
//         for(int j=0;j<len;j++)
//         {
//             if(s1[j]!=s2[j])
//             {
//                 adj[s1[j]-'a'].push_back(s2[j]-'a');
//                 break;
//             }
//         }
//     }
// queue<int>q;
// vector<int>ans;
//     int indegree[n+1]={0};
//     for(int i=0;i<=n;i++)
//     {
//         for(auto it:adj[i])
//         {
//             indegree[it]++;
//         }
//     }
//     while(!q.empty())
//     {
//         int node=q.front();
//         q.pop();
//         ans.push_back(node);
//         for(auto it:adj[node])
//         {
//             indegree[it]--;
//             if(indegree[it]==0)q,push(it);
//         }
//     }
//     vector<char>sol;
//     for(auto it:ans)
//     {
//         sol.push_back(it+'a');
//     }
//     if(sol.size()==n)return sol;
//     else return {};

    
// }
