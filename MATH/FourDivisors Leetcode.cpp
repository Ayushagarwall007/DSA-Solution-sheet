// Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

// Example 1:

// Input: nums = [21,4,7]
// Output: 32
// Explanation: 
// 21 has 4 divisors: 1, 3, 7, 21
// 4 has 3 divisors: 1, 2, 4
// 7 has 2 divisors: 1, 7
// The answer is the sum of divisors of 21 only.
// Example 2:

// Input: nums = [21,21]
// Output: 64
// Example 3:

// Input: nums = [1,2,3,4,5]
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 104
// 1 <= nums[i] <= 105




class Solution {
public:
int check(int num)
{
    int n=num;
    int sum=0;
    int count=0;
    for(int i=1;i<=num;i++)
    {
            if(n%i==0)
            {
                sum+=i;
                count++;
            }
            else continue;
    }
    
    if(count==4)return sum;
    else return -1;
}
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int ans=check(nums[i]);
            cout<<ans<<" ";
           if(ans>0)
           {
               sum+=ans;
           }
        }
        return sum;
        
    }
};


class Solution
{
    public:
     int sumFourDivisors(vector<int>& nums)
     {
         int ans=0;
         for(int i=0;i<nums.size();i++)
         {
             int x=nums[i];
             int count=0;
             int sum=0;

             for(int j=1;j*j<=x;j++)
             {
                 if(x%j==0)
                 {
                     if(x/j==j)
                     {
                         count++;
                         sum+=j;
                     }
                     else{
                         count+=2;
                         sum+=j;
                         sum+=(x/j);
                     }
                 }
             }
             if(count==4)
             ans+=sum;
         }
         return ans;
     }
};
