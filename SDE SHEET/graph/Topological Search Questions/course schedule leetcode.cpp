// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.




class Solution {
public:
bool dfs(vector<int>adj[] ,int &n, vector<int>&vis,vecctor<int>&pathVis,int node)
{
    if(pathVis[node])return true;
    if(vis[node])return false;
    vis[node]=pathVis[node]=true;
    
}
    bool canFinish(int v, vector<vector<int>>& pre) {
        vector<int>adj[v];
        for(auto i:pre)
        {
            adj[pre[i]].push_back(pr[0]);
        }
        vector<bool>vis(v,false),pathVis(v,false);
        for(int i=0;i<v;i++)
        {
            if(!vis[i] and dfs(adj,v,vis,pathVis,i))return false;
        }
        return true;
    }
};


// class Solution {
// public:
//     bool canFinish(int n, vector<vector<int>>& pre) {
//         vector<int>indegree(n);
//         vector<int>adj[n];
//         // for bfs hum hur node ko reverse kaar denge taaaki vo indegree mai aa haye
//         for(auto i:pre)
//         {
//             adj[i[1]].push_back(i[0]);
//             indegree[i[0]]++;
//         }

//         queue<int>q;
//         for(int i=0;i<n;i++)
//         {
//             if(indegree[i]==0)q.push(i);
//         }
//         vector<int>topo;
//         while(!q.empty())
//         {
//             int node=q.front();
//             topo.push_back(node);
//             q.pop();
//             for(auto it:adj[node])
//             {
//                 indegree[it]--;
//                 if(indegree[it]==0)q.push(it);
//             }
//         }
//         return topo.size()==n;
//     }
// };
