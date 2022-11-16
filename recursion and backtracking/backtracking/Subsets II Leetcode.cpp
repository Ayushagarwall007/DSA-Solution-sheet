// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10




class Solution {
public:
    vector<vector<int>>m;
    set<vector<int>>s;
    void solve(vector<int>nums,vector<int>v)
    {
        if(nums.size()==0)
        {
            
            if(s.find(v)==s.end())
            {
            
                s.insert(v);
                m.push_back(v);
                
            }
            return ;
        }
        vector<int>v1=v,v2=v;
        v1.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(nums,v1);
        solve(nums,v2);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>op;
        sort(nums.begin(),nums.end());
        solve(nums,op);
        return m;
        
    }
};



// class Solution {
// public:
//     vector<vector<int>> result;
    
//     void subs(vector<int> &nums, int curr, vector<int> &res){
//         result.push_back(res);
//         for(int i = curr; i < nums.size(); i++){
//             if(i!=curr && nums[i]==nums[i-1]){
//                 continue;
//             }
//             res.push_back(nums[i]);
//             subs(nums, i+1, res);
//             res.pop_back();
            
//         }
//     }
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         if(nums.size() == 0){
//             return result;
//         }
//         vector<int> res;
//         sort(nums.begin(), nums.end());
//         subs(nums, 0, res);
//         return result;
//     }
// };
