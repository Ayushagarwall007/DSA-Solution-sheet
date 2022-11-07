// 1079. Letter Tile Possibilities
// Medium
// 2K
// 56
// Companies
// You have n  tiles, where each tile has one letter tiles[i] printed on it.

// Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 

// Example 1:

// Input: tiles = "AAB"
// Output: 8
// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
// Example 2:

// Input: tiles = "AAABBC"
// Output: 188
// Example 3:

// Input: tiles = "V"
// Output: 1
 

// Constraints:

// 1 <= tiles.length <= 7
// tiles consists of uppercase English letters.


class Solution {
public:
set<string> ans;
    void solve(string tiles,vector<int> vis,string s)
    {
        for(int i=0;i<tiles.size();i++)
        {
         if(!vis[i])
         {
          s+=tiles[i];   
          vis[i]=1;
          cout<<s<<" ";
          ans.insert(s);
          solve(tiles,vis,s);
          vis[i]=0;
            s.pop_back();            
         }   
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> vis(tiles.size(),0);
        string s="";
        solve(tiles,vis,s);
        return ans.size();
    }
};
