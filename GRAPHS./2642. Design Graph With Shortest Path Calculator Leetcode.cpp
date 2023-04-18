// There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.

// Implement the Graph class:

// Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
// addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. It is guaranteed that there is no edge between the two nodes before adding this one.
// int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.




class Graph {
public:
    unordered_map<int,vector<pair<int,int>>>graph;
    int k;
    Graph(int n, vector<vector<int>>& edges) {
        for(auto x:edges)
        {
            vector<int>l;
            graph[x[0]].push_back({x[1],x[2]});
        }
        k=n;
    }
    
    void addEdge(vector<int> e) {
        graph[e[0]].push_back({e[1],e[2]});
    }
    
    int shortestPath(int n1, int n2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        p.push({0,n1});
        vector<int>dis(k+1,1e9);
        dis[n1]=0;
        while(!p.empty())
        {
            int dist=p.top().first;
            int node=p.top().second;
            p.pop();
            for(auto i:graph[node])
            {
                if(dist+i.second<dis[i.first])
                {
                    dis[i.first]=dist+i.second;
                    p.push({dis[i.first],i.first});
                }
            }
        }
        if(dis[n2]==1e9)return -1;
        return dis[n2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
