// this algorithm is used to find the total number of strngly connectd componnents in the directed graph in linear time
// steps:-
// 1-> sort all the components on the basis of their finishing time
// 2-> reverse the graph vertioces
// 3-> Do the dfs and print the connected components 
#include<bits/stdc++.h>
class Solution
{
   
void dfs1(int node,vector<int>adj[],vector<int>&vis,stack<int>&s){
    vis[node] = 1;
    for(auto i: adj[node]) {
        if(!vis[i])
            dfs1(i,adj,vis,s);
    }
    s.push(node);
}
void dfs2(int node,vector<int>adj[],vector<int>&vis,vector<int>&ans){
    vis[node] = 1;
    ans.push_back(node);
    for(auto i: adj[node]) {
        if(!vis[i])
            dfs2(i,adj,vis,ans);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int>adj1[n],adj2[n];
    for(auto i: edges) 
        adj1[i[0]].push_back(i[1]);
    
    vector<int>vis(n);
    stack<int>s;
    for(int i=0;i<n;i++) {
        if(!vis[i])
            dfs1(i,adj1,vis,s);
    }
    for(int i=0;i<n;i++) {
        vis[i] = 0;
        for(auto j: adj1[i])
            adj2[j].push_back(i);
    }
    vector<vector<int>>res;
    while(!s.empty()) {
        auto node = s.top();
        s.pop();
        vector<int>ans;
        if(!vis[node]) {
            dfs2(node,adj2,vis,ans);
        }
        res.push_back(ans);
    }
    return res;
}
};
