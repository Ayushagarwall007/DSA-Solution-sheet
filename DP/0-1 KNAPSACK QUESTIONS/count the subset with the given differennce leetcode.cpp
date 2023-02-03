// Let sum of subset 1 be s1 and subset 2 with s2
// s1 - s2 = diff (given)
// s1 + s2=sum of array (logical)
// Therefore adding both eq we get :
// 2s1= diff + sum of array
// s1= (diff + sum of array)/2;
// Problem reduces to find no of subsets with given sum**



// Let the sums of the elements of both the subsets be ‘S1’ and ‘S2’.

 

// Then, S1 + S2 = total_sum (Here, ‘total_sum’ is the sum of all the array elements).

 

// Also, the condition S1 - S2 = D needs to be satisfied.

 

// We get 2 * S1 = total_sum + D when we sum these two equations.

 

// And, if we subtract these two equations, we get 2 * S2 = total_sum - D.

 

// The problem is reduced to finding subsets with subset-sum equal to (total_sum - D) / 2 (let’s say target), which is our standard Knapsack problem, solved by Dynamic Programming.

 

// The steps are as follows:

// First, we need to handle some base cases:
// Since S1 is even, which is only possible if (total_sum - D) is even, if not, then the answer is 0.
// Also, since all the elements are ≥ 0, that means S2 ≥ 0, which implies total_sum - D ≥ 0. If not, then the answer is 0.
// Create a 2D DP array of dimensions N + 1 and target + 1.
// Here, DP[i][j] denotes the number of ways to form a subset of sum j if we only consider 1st i elements.
// Two cases arise:
// If we don’t include this element in our subset:
// DP[i][j] = DP[i - 1][j]
// If we include this element in our subset (this is only possible if ARR[i] >= j):
// DP[i][j] += DP[i - 1][j - ARR[i]]
// Finally, return DP[N][target], as it stores the number of ways to partition this array.




int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int dp[n + 1][sum + 1];
  // Initializing the first value of matrix
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
          // if the value is greater than the sum
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]]; 
            else
                  dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int countWithGivenSum(int arr[ ], int n, int diff)
{   
     int sum=0;
    for(int i=0;i<n;i++)
         sum+=nums[i]
	 
	 int reqSum=(diff+sum)/2;
	 return subsetSum(arr,n,reqSum);
}
