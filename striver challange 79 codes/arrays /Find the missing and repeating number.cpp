// Given an unsorted array of size n. Array elements are in the range of 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array.
//   Find these two numbers.

// Examples: 

// Input: arr[] = {3, 1, 3}
// Output: Missing = 2, Repeating = 3
// Explanation: In the array, 2 is missing and 3 occurs twice 

// Input: arr[] = {4, 3, 6, 2, 1, 1}
// Output: Missing = 5, Repeating = 1

#include<bits/stdc++.h>
vector<int> findMissingRepeatingNumbers(vector < int > a) {

    // Write your code here

    //better

    int n=a.size(); //size of the array

    int hash[n+1]={0}; // creating hash array 

 

    //update the hash array

    for(int i=0; i<n; i++){

        hash[a[i]]++;

    }

    // find the repeating and missing element

    int repeating=-1;

    int missing =-1;

    for(int i=1; i<=n;i++){

        if(hash[i]==2) repeating=i;

        else if(hash[i]==0) missing=i;

        if(repeating !=-1 && missing !=-1) break;

    }

    return {repeating,missing};

 

}
