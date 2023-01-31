// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

// Example 1:


// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
// Example 2:


// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2
// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.
 

// Constraints:

// 1 <= n <= 105
// 1 <= connections.length <= min(n * (n - 1) / 2, 105)
// connections[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated connections.
// No two computers are connected by more than one cable.





class disjointset
{
    public:
    vector<int>par;
    disjointset(int n)
    {
        par.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
        }
    }
    int findp(int u)
    {
        if(par[u]==u)return u;
        return par[u]=findp(par[u]);
    }
    void un(int u,int v)
    {
        par[findp(u)]=par[findp(v)];
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointset d(n);
        int cnt=0;
        int cnt1=0;
        for(auto i:connections)
        {
            if(d.findp(i[0])!=d.findp(i[1]))
            {
                d.un(i[0],i[1]);
            }
            else
            cnt++;
        }
        for(int i=0;i<n;i++)
        if(d.findp(i)==i){cnt1++;}

        if(cnt1-1<=cnt){
            return cnt1-1;
        }
        return -1;
    }
};
