// the basic structure oif the knapsack 0-1 problem by applying the dp in it:-

// approach 1 : memonization
  int knapsack(int wt[], int val[],int W,int n)
{
  if(n==0 or W==0)return 0;
  if(t[n][n]!=-1)return t[n][n];
  
  if(wt[n-1]<=W)
    return t[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1,knapsack(wt,val,W,n-1);
  else if(wt[n-1]>W)
     return t[n][W]=knapsack(wt,val,W,n-1);
  }

                                         
// // approach 02 
// Top down approach :-
// 2 steps to do this :-
// //    1-initialization of the array -> isme hum recursive call ko iterative call mai change kaar dena hota hai.....isme humm 2D matrix kaa phli row or phli column kaa initilaixsation recursive call ki base condtion mai hogi...

                                         
FOR THE MATERIX T[N+1][W+1]
// initialization with the base condition
for(int i=0;i<n+!;i++)
{
  for(int j=0;j<W+1;j++)
  {
    if(i==0 or j==0)t[i][j]=0;
  }
}
 aab isme i or j kaa loop chalana hai 1 se                                        
if(wt[n-1]<=W)
t[n][W]=max(val[n-1]+t[W-wt[n-1]][n-1],t[n-1][W]);
 
else 
t[n][W]= t[n-1][W];                                         
at last return t[n][W]            
                          
                                         
                                         
                                         
IDENTIFICATON OF THE KNAPSACK 0-1 TYOW OF PROBLEMS
ISME AGAR KOI BHI NUMBER OF ITEMS HONGE OR HUMEE CHOICE HAI KIII HUME UNKE LENA HHAI YA NAHI OR USS BAG MAI ADD ON KAARNA HAI KI NAHI TO HUMM KNAPSACK 01 APPREACH USE KAARENGE
                                         
                                         
                                         
                                         
                                         
                
                                         
