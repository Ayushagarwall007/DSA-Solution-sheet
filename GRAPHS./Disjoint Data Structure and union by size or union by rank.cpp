// disjoint data sturcture 

// TC O(4alpha) which is equal to O(const)\
// finding the unltimate parent and doing the rank either by union by rank or by union by size is the main task of Disjoint set 

// in both union by rank or in union by size we will connect samll component to the large components according to the size or by rak accordingly

#include<bits/stdc++.h>
using namespace std;
class disjoint_Set
{
    vector<int>rank,parent,size;
    public:
    disjoint_Set(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUltimateParent(int node)
    {
        if(node==parent[node])return node;
        return parent[node]=findUltimateParent(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ultiParU=findUltimateParent(u);
        int ultiParV=findUltimateParent(v);
        if(ultiParU==ultiParV)return;//this means that they belongs to the same component as theyu have the same ultimate parents
        if(rank[ultiParU]<rank[ultiParV])
        parent[ultiParU]=ultiParV;
        
        else if(rank[ultiParV]<rank[ultiParU])
        parent[ultiParV]=ultiParU;
        
        else {
        parent[ultiParU]=ultiParV;//or we can also do parent[ultiParV]=ultiParU;
        rank[ultiParV]++;
        }        
    }
    
    void unionBysize(int u,int v)
    {
        int ultiParU=findUltimateParent(u);
        int ultiParV=findUltimateParent(v);
        if(ultiParU==ultiParV)return;
        if(size[ultiParV]<size[ultiParU])
        {
            parent[ultiParV]=ultiParU;
            size[ultiParU]+=size[ultiParV];
        }
        else
        {
            parent[ultiParU]=ultiParV;
            size[ultiParV]+=size[ultiParU];
        }
        
    }
};


    
    int main()
    {
        disjoint_Set ds(7);
        ds.unionByRank(1,2);
        ds.unionByRank(2,3);
        ds.unionByRank(4,5);
        ds.unionByRank(6,7);
        ds.unionByRank(5,6);
        // if at this point of time if we want to find out weathte two nodes are in a same components or not then
        if(ds.findUltimateParent(3)==ds.findUltimateParent(4))cout<<"the nodes 3 & 4 are in a same component ";
        else cout<<"the nodes 3 and 4 are not in a same component "<<" ";
        ds.unionByRank(1,2);
        ds.unionByRank(3,7);
        
        
        
        disjoint_Set ds1(7);
        ds1.unionBysize(1,2);
        ds1.unionBysize(2,3);
        ds1.unionBysize(4,5);
        ds1.unionBysize(6,7);
        ds1.unionBysize(5,6);
        ds1.unionBysize(1,2);
        ds1.unionBysize(3,7);
        return 0;
        
    }
}
