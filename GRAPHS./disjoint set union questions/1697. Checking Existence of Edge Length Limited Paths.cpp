// An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. Note that there may be multiple edges between two nodes.

// Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that each edge on the path has a distance strictly less than limitj .

// Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, and false otherwise.

 

// Example 1:


// Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
// Output: [false,true]
// Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
// For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
// For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.
// Example 2:


// Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
// Output: [true,false]
// Exaplanation: The above figure shows the given graph.
 

// Constraints:

// 2 <= n <= 105
// 1 <= edgeList.length, queries.length <= 105
// edgeList[i].length == 3
// queries[j].length == 3
// 0 <= ui, vi, pj, qj <= n - 1
// ui != vi
// pj != qj
// 1 <= disi, limitj <= 109
// There may be multiple edges between two nodes.





// Intuition
// Sort both the array weight wise and traverse until queries is smaller then edgeList
// Approach
// Make a parent array and initialize it with themselves.
// Make a answer array and initislize it with false.
// Swap the first and third part of edgeList to sort it w.r.t weight.
// Sort edgeList.
// Make an array to store the weights of the queries vector and their index.
// Traverse in the edgeList until its weight is greater than queries weight.
// Make their parents same in the loop which has been traversed.
// Outside the loop check if they have same parents means they can be traversed so make them true.
class Solution {
public:
    int dsu(vector<int>& parent,int x)
    {
        //Base case
        if(parent[x] == x)
            return x;
        //Else check its parent
        else
            return parent[x] = dsu(parent,parent[x]);
        
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) 
    {
        //A parent vector to store the parent of the elements
        vector<int> parent(n,-1);

        //Answer vector to store the answer
        vector<bool> ans(queries.size(),false);

        //Make every element its own parent
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        //Swap the weight index with the first index so that we can sort it by weight
        for(int i=0;i<edgeList.size();i++)
            swap(edgeList[i][0],edgeList[i][2]);

        //Sort by Weight
        sort(edgeList.begin(),edgeList.end());

        //Store the queries weight and its index
        vector<pair<int,int>> arr;

        for(int i=0;i<queries.size();i++)
            arr.push_back({queries[i][2],i});
        
        //Sort the queries w.r.t weight
        sort(arr.begin(),arr.end());


        int j = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            //Traverse until query weight is greater than the edge weight
            while(j < edgeList.size() && edgeList[j][0] < arr[i].first)
            {    
                //Take the vertices of the edgelist
                int u = edgeList[j][1],v = edgeList[j][2];
                //Check their parents
                int pu = dsu(parent,u),pv = dsu(parent,v);
                //If not equal make them equal
                if(pu != pv)
                    parent[pu] = pv;
                
                j++;
            }
            //Take the vertices of the query 
            int x = queries[arr[i].second][0],y = queries[arr[i].second][1];
            //Check their parents
            int px = dsu(parent,x),py = dsu(parent,y);
            //If parents are equal then return true
            if(px == py)
                ans[arr[i].second] = true;
            
        }
        return ans;

    }
};
