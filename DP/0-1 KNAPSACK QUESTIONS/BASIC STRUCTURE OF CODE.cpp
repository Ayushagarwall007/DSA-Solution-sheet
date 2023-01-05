// the basic structure oif the knapsack 0-1 problem by applying the dp in it:-
  int knapsack(int wt[], int val[],int W,int n)
{
  if(n==0 or W==0)return 0;
  if(t[n][n]!=-1)return t[n][n];
  
  if(wt[n-1]<=W)
    return t[n][n]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1,knapsack(wt,val,W,n-1);
  else if(wt[n-1]>W)
     return t[n][n]=knapsack(wt,val,W,n-1);
  }
