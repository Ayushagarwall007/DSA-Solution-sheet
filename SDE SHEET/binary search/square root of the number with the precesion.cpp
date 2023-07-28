#include<bits/stdc++.h>
using namespace std;
int results(int number)
{
  int start=1;
  int end=number/2;
  int ans=-1;
  while(start<=end)
    {
      int mid=start+(end-start)/2;
      long long check=mid*mid;
      if(mid==n)
        return mid;
      else if(mid<n)
      {
          ans=mid;
          start=mid+1;
      }
      else
      {
        end=mid-1;
      }
    }
  return ans;
}

double sqRoot(int n, int prec,long long int results)
{
  double factor=1;
  double ans=results;
  for(int i=0;i<prec;i++)
    {
      factor/=10;
      for(double j=ans;j*j<=results;j+=ans)
        {
          ans=j;
        }
    }
  return ans;
}
int main()
{
  int number;
  cin>>number;
  int res=results(number);
  // finding the decimal numbers of the square root
  double nummm=sqRoot(n,3,results);
}
