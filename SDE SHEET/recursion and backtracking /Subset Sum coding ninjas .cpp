// you are given the array a of n integers you have to return true if subsets of a returns to sum k otherwise return false



// #include<bits/stdc++.h>
// bool solve(int ind,int sum , vector<int>&a)
// {
//     if(sum==0)return true;
//     if(ind<0 )return false;
//     bool pick=false;
//     bool notPick=false;
    
//     pick=solve(ind-1,sum-a[ind],a);
//     notPick=solve(ind-1,sum,a);
//     return (pick or notPick);
// }
// bool isSubsetPresent(int n, int sum, vector<int> &a)
// {
//     return solve(n-1,sum,a);
// }


#include<bits/stdc++.h>
bool isPresent(int i, int sum,int k , vector<int>& a)
{
    if(sum>k)return false;
    if(i==a.size())
    {
        if(sum==k)
        {
            return true;
        }
        return false;
    }
    sum=sum+a[i];
    if(isPresent(i+1,sum,k,a))return true;
    sum=sum-a[i];
    
    if(isPresent(i+1,sum,k,a))return true;
    return false;
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
   return isPresent(0,0,k,a);
   
}



