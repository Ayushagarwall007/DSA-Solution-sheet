#include <bits/stdc++.h>
using namespace std;
void insertion(vector<int>&v,int temp)
{
   if(v.size()==0 || v[v.size()-1]<=temp)
   {
   v.push_back(temp);
   return;
   }
   int x=v[v.size()-1];
   v.pop_back();
   insertion(v,temp);
   v.push_back(x);
}
void sorting(vector<int>&v)
{
   if(v.size()<=1)
   return;
   int temp=v[v.size()-1];
   v.pop_back();
   sorting(v);
   insertion(v,temp);
}
int main()
{
    vector<int>v={5,3,2,4,1};
    sorting(v);
   for(auto it:v)
   cout<<it<<" ";
    return 0;
}
