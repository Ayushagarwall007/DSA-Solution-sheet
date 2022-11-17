// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 

// Example 1:


// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
// Example 2:


// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
 

// Constraints:

// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]


BFS approach:-
'''

class Solution {
public:
	int findCircleNum(vector<vector<int>>& isConnected) {
		int V=isConnected.size();
		vector<int>adjls[V];
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
				if(isConnected[i][j]==1 && i!=j){
					adjls[i].push_back(j);
					adjls[j].push_back(i);
				}
			}
		}
		vector<int>v(V, 0);
		int cnt=0;
		for(int i=0; i<V; i++){
			if(v[i]==0){
				cnt++;
				queue<int>q;
				q.push(i);
				while(!q.empty()){
					int ft=q.front();
					q.pop();
					for(auto it: adjls[ft]){
						if(!v[it]){
							v[it]=1;
							q.push(it);
						}
					}
				}
			}
		}
		return cnt;
	}
};
'''
DFS approach:-
'''

class Solution {
public:
	void dfs(int st, vector<int>adjls[], vector<int>& v){
	  v[st]=1;
	  for(auto it: adjls[st]){
		  if(!v[it]){
			  v[it]=1;
			  dfs(it, adjls, v);
		  }
	  }
  }
	int findCircleNum(vector<vector<int>>& isConnected) {
		int V=isConnected.size();
		vector<int>adjls[V];
		for(int i=0; i<V; i++){
			for(int j=0; j<V; j++){
				if(isConnected[i][j]==1 && i!=j){
					adjls[i].push_back(j);
					adjls[j].push_back(i);
				}
			}
		}
		vector<int>v(V, 0);
		int cnt=0;
		for(int i=0; i<V; i++){
			if(v[i]==0){
				cnt++;
				int st=i;
				dfs(st, adjls, v);
			}
		}
		return cnt;
	}
};
