#include<bits/stdc++.h>

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {

    // Write your code here!

    int indeg[nodes]={0};

    vector<int>ans;

    vector<int>adjl[nodes];

    for(int i=0;i<graph.size();i++){

        int u=graph[i][0];

        int v=graph[i][1];

        adjl[u].push_back(v);

         }

         for(int i=0;i<nodes;i++){

             for(auto it:adjl[i]){

                 indeg[it]++;

             }

         }

         queue<int>q;

         for(int i=0;i<nodes;i++){

             if(indeg[i]==0){

                 q.push(i);

             }

         }

         while(!q.empty()){

             int node=q.front();

             q.pop();

             ans.push_back(node);

             for(auto it:adjl[node]){

                 indeg[it]--;

                 if(indeg[it]==0){

                     q.push(it);

                 }

             }

         }

         

       return ans;  

}
