// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
// Medium
// 1.4K
// 29
// Companies
// You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

// Return the number of pairs of different nodes that are unreachable from each other.

 

// Example 1:


// Input: n = 3, edges = [[0,1],[0,2],[1,2]]
// Output: 0
// Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.
// Example 2:


// Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
// Output: 14
// Explanation: There are 14 pairs of nodes that are unreachable from each other:
// [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
// Therefore, we return 14.
 

// Constraints:

// 1 <= n <= 105
// 0 <= edges.length <= 2 * 105
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated edges.




// Explaination:

// Using Union Find to find all the connected components,
// Parent array stores:
// For nodes with no parent : number of nodes in the group.
// Fore nodes with parent : parent of the node (with - minus sign).

// Code:

//-----------------------------Union Find Approach-------------------------------
class Solution {
public:
    int parent[100001];
    int find(int a)
    {
        if(parent[a]>0)return a;
        parent[a]=-find(-parent[a]);
        return -parent[a];
    }
    void Union(int a,int b)
    {
        a=find(a),b=find(b);
        if(a==b)return;
        if(parent[a]>parent[b])
        {
            parent[a]+=parent[b];
            parent[b]=-a;
        }
        else
        {
            parent[b]+=parent[a];
            parent[a]=-b;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=(long long)n*(n-1)/2;
        for(int i=0;i<n;i++)
            parent[i]=1;
        for(auto &e:edges)
            Union(e[0],e[1]);
        for(int i=0;i<n;i++)
        {
            if(parent[i]>0)
                ans-=(long long)parent[i]*(parent[i]-1)/2;
        }
        return ans;
    }
};
// DFS
// Code:

// //-------------------------------DFS Approach--------------------------------
// class Solution {
// public:
//     vector<int>mp[100001];
//     bool vis[100001];
//     int ret;
//     void dfs(int u)
//     {
//         vis[u]=1;
//         ret++;
//         for(auto &it:mp[u])
//             if(!vis[it])dfs(it);
//     }
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         for(auto &e:edges)
//         {
//             mp[e[0]].push_back(e[1]);
//             mp[e[1]].push_back(e[0]);
//         }
//         long long ans=(long long)n*(n-1)/2;
//         for(int i=0;i<n;i++)
//         {
//             if(vis[i])continue;
//             ret=0;
//             dfs(i);
//             ans-=(long long)ret*(ret-1)/2;
//         }
//         return ans;
//     }
// };
// BFS
// Code:

// //--------------------------------BFS Approach--------------------------------
// class Solution {
// public:
//     vector<int> mp[100001];
//     bool vis[100001];
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         for(auto &e:edges)
//         {
//             mp[e[0]].push_back(e[1]);
//             mp[e[1]].push_back(e[0]);
//         }
//         long long ans=(long long)n*(n-1)/2;
//         queue<int>q;
//         int cnt,temp;
//         for(int i=0;i<n;i++)
//         {
//             if(vis[i])continue;
//             q.push(i);
//             vis[i]=1;
//             cnt=0;
//             while(!q.empty())
//             {
//                 cnt++;
//                 temp=q.front();q.pop();
//                 for(auto &it:mp[temp])
//                     if(!vis[it])vis[it]=1,q.push(it);
//             }
//             ans-=(long long)cnt*(cnt-1)/2;
//         }
//         return ans;
//     }
// };
