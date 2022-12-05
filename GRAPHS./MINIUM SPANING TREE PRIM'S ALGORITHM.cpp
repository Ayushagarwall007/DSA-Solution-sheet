// PRIM'S ALGORITHM
// a sppaning tree is a graph with the n edges and n-1 versitces such that all nodes are reachable to other 
// a minimum spanning tree is a tree with the minimum sum of all vertices among all the spanning trees
// we will use the priority queue here ie {weight,node,parent} if we want to print the mst but oif we want the minimum sum then we will not take teh parent in the
// priority queue and we take two array ie ms array and vis array first we take the first node and mark it as present and then 
// look for its adjacent nodes and add them in the queue now take out the node with the minimum wt and check for it adjacent node if that
// adjacent node is not visited then mark the first node as visted and add it to the ms array

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vist(V, 0);
        int sum = 0;
        // {wt, node}
        pq.push({0, 0}); // we are only keeping track of weight and node and not the parent
        // as we only have to retrun the sum and not the edges in MST.
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int node = it.second;
            
            if(vist[node] == 1) continue; // if already visisted
            vist[node] = 1; // else mark it visited only after popping out of the min-heap
            
            sum += wt; // add the edge weight to sum
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgwt = it[1];
                
                if(!vist[adjNode])
                    pq.push({edgwt, adjNode});
            }
        }
        
        return sum;
    }
};




// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

// Example 1:


// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation: 

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.
// Example 2:

// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18
 

// Constraints:

// 1 <= points.length <= 1000
// -106 <= xi, yi <= 106
// All pairs (xi, yi) are distinct.


// using the concept of minimum spanning tree
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>>adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                int distance=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,distance});
                adj[j].push_back({i,distance});
            }
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,-1}});
        vector<bool>visited(n,false);
        int rval=0;
        int edges=0;
        while(edges<n)
        {
            pair<int,pair<int,int>>curr=pq.top();
            pq.pop();

            int weight=curr.first;
            int node=curr.second.first;
            int parent=curr.second.second;
            if(visited[node])continue;
            visited[node]=true;
            for(auto u:adj[node])
            {
                if(!visited[u.first])
                {
                    pq.push({u.second,{u.first,node}});
                }
            }
            rval+=weight;
            edges++;
        }
        return rval;
    }
};
