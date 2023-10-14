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
void solve(vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>temp,int sum, int i)
{
    if(sum==target)
    {
        ans.push_back(temp);
        return;
    }
    if(sum>target or i==candidates.size())return;
    temp.push_back(candidates[i]);
    sum+=candidates[i];
    solve(candidates,target,ans,temp,sum,i+1);
    sum-=candidates[i];
    temp.pop_back();
    while(i+1<candidates.size() and candidates[i]==candidates[i+1])i++;
    solve(candidates,target,ans,temp,sum,i+1);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        int sum=0;
        solve(candidates,target,ans,temp,sum,0);
        return ans;

    }
};
