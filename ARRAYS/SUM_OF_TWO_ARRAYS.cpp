// You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element represents a digit. 
//  You need to find the sum of these two numbers and return this sum in the form of an array.
//   Note:
// 1. The length of each array is greater than zero.

// 2. The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.

// 3. Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros.
// Input Format:
// The first line of the input contains an integer T, denoting the number of test cases.

// The first line of each test case contains two space-separated integers 'N' and 'M', denoting the size of the two arrays.

// The second line of each test case contains 'N' space-separated integers denoting the elements of the first array.

// The third line of each test case contains 'M' space-separated integers denoting the elements of the second array.
// Output Format:
// The only line of output of each test case contains space-separated digits which correspond to the sum of the two numbers 'A' and 'B'.
// Note :
// You do not need to print anything, it has already been taken care of. Just implement the given function.

vector<int> reverse(vector<int>v){

   int s = 0;

   int e = v.size()-1;

   while(s<e){

       swap(v[s] , v[e]);

       s++;

       e--;

   }    

   return v;

}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {

vector<int>ans;

   int mul=1,i,j,res1=0,res2=0;

   for(int i=n-1;i>=0;i--){

       res1 = res1 + (a[i]*mul);

       mul=mul*10;

   }

   mul=1;

   for(int i=m-1;i>=0;i--){

       res2 = res2 + (b[i]*mul);

       mul=mul*10;

   }

   int total = res1+res2;

   while(total > 0){

       int ele = total % 10;

       ans.push_back(ele);

       total = total / 10;

   }

   return reverse(ans);

}
