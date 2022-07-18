#include<bits/stdc++.h>
using namespace std;
long long int result(int n)
{
    int s=0;
    int e= n;
    int ans=-1;
  long long int mid=s+(e-s)/2;
        while(s<=e)
        {
            long long int square =mid*mid;
            if(square==n)
            {
                return mid;
            }
            if(square <n)
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans; 
  }
  double squareRoot(int n,int precision,int tempSol)
  {
    double factor =1;
    double ans=tempSol;
    for(int i=0;i<precision;i++)
    {
        factor/=10;
        for(double j=ans;j*j<n;j+=factor)
        {
            ans=j;
        }
    }
    return ans;
  }
  
  
int main()
{
    int n;
    cout<<"enter the number for finding the square root of the number ..."<<endl;
    cin>>n;
    int results=result(n);
    cout<<"the square root of the number with the precosion of 3 is "<<squareRoot(n,3,results);
}
