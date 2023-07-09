// We are given an array asteroids of integers representing asteroids in a row.

// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

// Example 1:

// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
// Example 2:

// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.
// Example 3:

// Input: asteroids = [10,2,-5]
// Output: [10]
// Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

// Constraints:

// 2 <= asteroids.length <= 104
// -1000 <= asteroids[i] <= 1000
// asteroids[i] != 0





class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>s;
        int n=ast.size();
        
        for(int i=0;i<n;i++)
        {
            if(ast[i]>0 or s.empty())
            {
                s.push(ast[i]);
            }
            else
            {
                while(!s.empty() and s.top()>0 and s.top()<abs(ast[i]))
                {
                    s.pop();
                }
                if(!s.empty() and s.top()==abs(ast[i]))
                {
                    s.pop();
                }
                else
                {
                    if(s.empty() or s.top()<0)
                    {
                        s.push(ast[i]);
                    }
                }
            }
        }
        vector<int>res(s.size());
        for(int i=s.size()-1;i>=0;i--)
        {
            res[i]=s.top();
            s.pop();
        }
        return res;
    }
};
