// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
 

// Test case format:

// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

// Example 1:


// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// Example 2:


// Input: adjList = [[]]
// Output: [[]]
// Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
// Example 3:

// Input: adjList = []
// Output: []
// Explanation: This an empty graph, it does not have any nodes.
 

// Constraints:

// The number of nodes in the graph is in the range [0, 100].
// 1 <= Node.val <= 100
// Node.val is unique for each node.
// There are no repeated edges and no self-loops in the graph.
// The Graph is connected and all nodes can be visited starting from the given node.




/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// 1. Cloned Graph has all nodes as newnodes and don't have node as reference to given original graph.
// 2. Graph has no practical edges, i.e no pointers for edges.
//          (2,3)            (1,3)<---adj list
// 		  (1)-------------(2)
// 		    |              |
// 			|              |
// 			|              |
// 		  (4)-------------(3)
// 		  (1,3)          (2,4)
// If i say '1' is my starting point and how should i jump to '2' for that i have to iterate through this adjacency list.

// 1. Cloned Graph has all nodes as newnodes and don't have node as reference to given original graph.
// 2. Graph has no practical edges, i.e no pointers for edges.
//          (2,3)            (1,3)<---adj list
// 		  (1)-------------(2)
// 		    |              |
// 			|              |
// 			|              |
// 		  (4)-------------(3)
// 		  (1,3)          (2,4)
// If i say '1' is my starting point and how should i jump to '2' for that i have to iterate through this adjacency list.


// 1. We use HashMap to solve it and using DFS.
// 2. Initially our hash map will be empty and we try to map the old node with the new node or the copy node.
// 3. We start with any entry point.
// 4. I am using '1' as my entry point.

// Now lets see how its going i am starting with 1 and whenever i visited a new node i coloned it and put in there.
// We are using DFS so algorithm is like 'it starts at the root node (select some arbitrary node as root node in the case of a graph) and explores as far as possible along each branch before backtracking.
// So the basic idea is to start from the root or any arbitrary node and mark the node and move to the adjacentunmarked node and continue this loop until there is no unmarked adjacent node. 
// Then backtrack and check for other unmarked nodes and traverse them. Finally, print the nodes in the path.'
// So we are using HashMap to put all the visited node or old node there with clone one to.
//  _________
// | HashMap |
//  ----------
// |Old|Clone| 
// | 1  | 1 |
// |  2 | 2 |
// |  3 | 3 |                                                     
// |  4 | 4 |                                                                                                            
// ---------

// Now i started with 1 so i cloned it and from 1 can go to 2 and 4 so i go 2 and when i visited 2 i cloned 2 and now fro  i have two choices either go to previous one that is 1 or discover 3 i.e new node
// so accordingly to dfs i go to 3 and from 3 i can go to 4 i go there and cloned it. Now if we see fro each node we have viisted to a new node but what about 4. So here half part of Dfs is completed,
// and now its time for recursive call to go back and now from here we check from current node i can go where and where.
// And follow the same rules over there.

// BUT BEFORE STARTING ANY CLONING WE HAVE TO CHECK THAT IF WE HAVE CLONED THAT NODE ALREADY THERE OR NOT. IF NOT THAN ONLY WE CLONED IT. 

// Thats the only reason we are using hash map so that we don't need to clone again and again.
// For every uncloned node we make a clone and iterate over the neighbors of original node using dfs traversal or bfs traversal.



class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};
