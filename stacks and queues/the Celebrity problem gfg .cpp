// // celebrity problem gfg

// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is
// a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it
// means ith person knows jth person. Here M[i][i] will always be 0.

// Note: Follow 0 based indexing.
 

// Example 1:

// Input:
// N = 3
// M[][] = {{0 1 0},
//          {0 0 0}, 
//          {0 1 0}}
// Output: 1
// Explanation: 0th and 2nd person both
// know 1. Therefore, 1 is the celebrity. 

// Example 2:

// Input:
// N = 2
// M[][] = {{0 1},
//          {1 0}}
// Output: -1
// Explanation: The two people at the party both
// know each other. None of them is a celebrity.

// Your Task:
// You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as 
// input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


// Constraints:
// 2 <= N <= 3000
// 0 <= M[][] <= 1

// approach:- 
// everyone knows celebrity
// celebrity knows  noone

// in the 2D matrix ignore the diagonal part because everyone knows himself or herself

// // celebrity ki row mai poore zero honge
// celebrity waale col mai saare one honge except the celebrity waala row or column kaa intersection 

// aligo:-
// =>put all element into the stack
// =>then till size!=-1 => top ke 2 element nikaal long ie A and B
// =>then two condition arises agar A B ko jaanta hai tooo A celeb nahi hai or A ko vaapas push kaar do
// same as for B
// =>jo single element baacha hua hai vo ekk potential candite ho skta hai
// => to verify that single element
//      -> check for its row
//      ->check for its col accepts the diagonal element


class Solution
{
    private:
    bool knows(vector<vector<int>>&M,int a,intb,int n)
    {
        if(M[a][b]==1)retiurn true;
        else
        return false;
    }
    
    public:
    int celebrity(vector<vector<int>>&M,int n)
    {
        stack<int>s;
        for(int i=0;i<n;i++)
        s.push(i);
        
        
        while(s.size()>1)
        {
            int a= s.top();s.pop();
            int b=s.top();s.pop();
            if(knows(M,a,b,n))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int candidate=s.top();
        // now single element in the stack has the potential to be the celebrity
        // to verify the single element check its rows and columns
                    bool rowCheck=false;
                    int zerocount =0;
                    for(int i=0;i<n;i++)
                    {
                        if(M[candidate][i]==0)zerocount++;
                    }
                    // all zeroes
                    if(zerocount==n)rowCheck=true;
                    
                    
                    // column check
                    bool colCheck=false;
                    int oneCount=0;
                    for(int i=0;i<n;i++)
                    {
                        if(M[i][candidate]==1)
                        oneCount++;
                    }
                    if(oneCount==n-1)colCheck=true;
                    
                    
                    
                    if(rowCheck==true&&colCheck==true)
                    {
                        return candidate;
                    }
                    return -1;
    }
}
