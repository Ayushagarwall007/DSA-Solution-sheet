// Given that there are N books and M students. Also given are the number of pages in each book in ascending order. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum, with the condition that every student is assigned to read some consecutive books. Print that minimum number of pages.

// Example : 

// Input: N = 4, pages[] = {12, 34, 67, 90}, M = 2

// Output: 113

// Explanation: There are 2 number of students. Books can be distributed in following combinations: 

// [12] and [34, 67, 90] -> Max number of pages is allocated to student ‘2’ with 34 + 67 + 90 = 191 pages
// [12, 34] and [67, 90] -> Max number of pages is allocated to student ‘2’ with 67 + 90 = 157 pages 
// [12, 34, 67] and [90] -> Max number of pages is allocated to student ‘1’ with 12 + 34 + 67 = 113 pages
// Of the 3 cases, Option 3 has the minimum pages = 113.



#include <bits/stdc++.h> 

 

bool isPossible(int n, int m, vector<int> &time,long long mid)

{

    int dayCount = 1;

    long long int chapterStore = 0;

 

    for(int i=0 ; i<m ; i++)

    {

        if(chapterStore + time[i] <= mid)

        {

            chapterStore += time[i];

        }

        else

        {

            dayCount++;

 

            if(dayCount > n || time[i]>mid)

            {

                return false;

            }

 

            chapterStore = time[i];

        }

    }

    return true;

}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 

{   

    long long int s =0;

    long long int sum=0;

 

    for(auto i : time)

    {

        sum+=i;

    }

    long long int e = sum;

    long long int ans = -1;

    long long int mid = s+ (e-s)/2;

 

    while(s<=e)

    {

        if(isPossible(n,m,time,mid))

        {

            ans = mid;

            e=mid-1;

        }

        else

        {

            s=mid+1;

        }

        mid = s +(e-s)/2;

    }

    return ans;

}
