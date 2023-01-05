class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
       long long int mod = 1000000000+7 ;
	    long long int dp[n+1][sum+1] ; 
	    dp[0][0]=1 ; 
	    for(int i=1 ; i<=sum ; i++){
	        dp[0][i]=0 ; 
	    }
	    for(int i=1 ; i<=n ; i++){
	        for(int j=0 ; j<=sum ; j++){
	            if(arr[i-1]<=j){
	                dp[i][j] = ((dp[i-1][j])%mod+(dp[i-1][j-arr[i-1]])%mod)%mod ;
	            }
	            else{
	                dp[i][j] = dp[i-1][j]%mod ;
	            }
	        }
	    }
	    return dp[n][sum]%mod ;
	}
	  
};
