// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30



class Solution {
public:
vector<vector<int>> ans;
    void solve(vector<int>&curr,int target,int sum,vector<int> &candidates,int curIdx)
    {
        int n=candidates.size();
        if(target==sum)
        {
            ans.push_back(curr);
            return;
        }
        else if(sum>target) return;

        for(int i=curIdx;i<n;i++)
        {
            if(i!=curIdx and candidates[i]==candidates[i-1]) continue;

            sum+=candidates[i];
            curr.push_back(candidates[i]);
            solve(curr,target,sum,candidates,i+1);
            sum-=candidates[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        
        sort(candidates.begin(),candidates.end());
        solve(curr,target,0,candidates,0);
        return ans;
    }
};
