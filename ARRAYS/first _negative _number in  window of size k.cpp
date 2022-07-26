#include<bits/stdc++.h>

vector<int> firstNegative(vector<int> a, int n, int k) {

// Write your code here.

   int i=0,j=0;

   vector<int>ans;

   deque<int>q;

   while(j<n)

   {

       if(a[j]<0)

           q.push_back(a[j]);

       if(j-i+1<k)

       {  j++;

        continue;

       }

       else if(j-i+1==k)

       {

           if(!q.empty())

               ans.push_back(q.front());

           else

               ans.push_back(0);

               if(a[i]==q.front())

                   q.pop_front();

               i++;

           }

       j++;

    }

   return ans;

}
