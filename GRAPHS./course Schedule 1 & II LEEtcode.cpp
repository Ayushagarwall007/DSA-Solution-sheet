// 207. Course Schedule
// Medium
// 12K
// 468
// Companies
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


// using the topological sort technique to solve this probelm

class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       int n=prerequisites.size();
       if(n==0) return  true;
       vector<vector<int>> graph(numCourses);
       vector<int>indegree(numCourses,0);

       for(auto edge:prerequisites)
       {
           graph[edge[1]].push_back(edge[0]);
           indegree[edge[0]]++;
       }
       queue<int>q;
       for(int i=0;i<numCourses;i++)
       {
           if(indegree[i]==0)q.push(i);
       }
       int noCoursesTaken=0;
       while(!q.empty())
       {
           noCoursesTaken++;
           int curr=q.front();
           q.pop();
           for(auto neighbour:graph[curr])
           {
               indegree[neighbour]--;
               if(indegree[neighbour]==0)
               q.push(neighbour);
           }
       }
       return (noCoursesTaken==numCourses);

    }
};







// 210. Course Schedule II
// Medium
// 8.3K
// 273
// Companies
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct.



class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) { 
        vector<vector<int>> graph(n,vector<int>());
        vector<int> in_degree(n,0);
        vector<int> ans;
        queue<int> q;
        vector<int> nothing={};
        for(auto p:prerequisites){graph[p[1]].push_back(p[0]);
                                  in_degree[p[0]]++;}
        for(int i=0;i<n;i++)
        {if(in_degree[i]==0)
             q.push(i);
        }
        while(!q.empty())
        {   int cur=q.front();
            q.pop();
            ans.push_back(cur);
            for(int child: graph[cur]) 
            {
                --in_degree[child];
                if(in_degree[child]==0) 
                {q.push(child);}
            }
        }
       if(ans.size()==n) 
       return ans;else return nothing;
    }
};
