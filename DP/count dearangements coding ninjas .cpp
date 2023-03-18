// problem statement:- Q:
// You are given N balls numbered from 1 to N and there are N baskets numbered from 1 to N in front of you, the ith basket is meant for the ith ball. Calculate the number of ways in which no ball goes into its respective basket.
// Eg

// Input: 3
// Output: 2
// Explaination: The (number-basket) pairs are 
// [(1-3),(2-1),(3-2)] and [(1-2),(2-3),(3-2)].
  
//   the question means that the total number of arrangements kii hum particular element ko uski original position ke alawa dusri or koi position mai rakh sakte hai..
//   abb isme 3 case bante hai 
  
  
//   : case 1 : let suppose humpe ekk array hai [0,1,2,3,4]
//   hum element 0 ko n-1 pos maii or rakh skte hai 
//   sol= (n-1)*(baaki ke elements kaa sub problem)
  
    
//     case 2:
// now let suppose hum 0 ko ith position mai rakhna chate hai to hum dono ke postrion ko swqp kaar denge
//  no of elemtes left =n-2.
//   no of blocks left = n-2
//   ie. the function become n-2
  
  
//   case 3:
// now after swap humm i ko 0th position mai naa rakh ke baaki ki postion mai rakhnaa chate hai 
// total no of elefments left for swap n-1
//   total no of blocks left for swap n-1
    
    
//     now the final recursive solutio0n become 
//     F(n) = (n - 1) * [ F(n - 1) + F(n - 2) ]
    
    
    
Recursive Statement

F(n) = (n - 1) * [ F(n - 1) + F(n - 2) ]
Recursive Code:
 long int disarrange(int n){
        
        if(n==0) return 0;
        if(n==1) return 1;
        
        return (n-1)*(disarrange(n-1)+disarrange(n-2));
    }
Time Complexity: T(n) = T(n-1) + T(n-2) which is exponential.

We can observe that this implementation does repeat work. For example, see recursion tree for countDer(5), countDer(3) is being evaluated twice.

cdr() ==> countDer()

                    cdr(5)   
                 /         \     
             cdr(4)          cdr(3)   
           /      \         /     \
       cdr(3)     cdr(2)  cdr(2)   cdr(1)
Pure Dp (Auxiliary Space: O(N))
long int disarrange(int n){
        
        vector<long int> dp(n+1,0);
        dp[1]=0;
        dp[2]=1;
        for(int i=3;i<=n;i++)
        {
            dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
        }
        return dp[n];
    }
    
