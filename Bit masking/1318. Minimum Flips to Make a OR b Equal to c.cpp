// Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
// Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

 

// Example 1:



// Input: a = 2, b = 6, c = 5
// Output: 3
// Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
// Example 2:

// Input: a = 4, b = 2, c = 7
// Output: 1
// Example 3:

// Input: a = 1, b = 2, c = 3
// Output: 0
 

// Constraints:

// 1 <= a <= 10^9
// 1 <= b <= 10^9
// 1 <= c <= 10^9



class Solution {
public:
    int minFlips(int a, int b, int c) {
       int ans=0;
       while( a or b or c)  //it process till all digits becomes zero
       {

           //extracting all LSBs of a , b and c
           //we can extract LSB by performing '&' operation to 1

            int x1 = a & 1;
            int x2 = b & 1;
            int x3 = c & 1;
            
            if( (x1 | x2) != x3)  //if this true then we have to flip the digits
            {
               if(x1&x2) ans += 2;   //if both are 1 then we have to flip 2 times
               else      ans += 1;   //else only 1 times
            }

            //shift to right by 1 position to perform operation in next digits 
            a = a>>1;       
            b = b>>1;
            c = c>>1; 
       } 
       return ans;
    }
};




// class Solution {
// public:
//     int minFlips(int a, int b, int c) {
//         bitset<32>A(a);
//         bitset<32>B(b);
//         bitset<32>C(c);

//         string x= A.to_string();
//         string y=B.to_string();
//         string z=C.to_string();
//         int res=0;
//         for(int i=31;i>=0;i--)
        
//         {
//             int a=x[i]-'0';
//             int b=y[i]-'0';
//             int c=z[i]-'0';

//             if((a or b)!=c)
//             {
//                 if(c==0 and a==1 and b==1)res+=2;
//                 else
//                 res+=1;
//             }
//         }
//         return res;
//         }
// };
