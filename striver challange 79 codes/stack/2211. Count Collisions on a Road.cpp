// There are n cars on an infinitely long road. The cars are numbered from 0 to n - 1 from left to right and each car is present at a unique point.

// You are given a 0-indexed string directions of length n. directions[i] can be either 'L', 'R', or 'S' denoting whether the ith car is moving towards the left, towards the right, or staying at its current point respectively. Each moving car has the same speed.

// The number of collisions can be calculated as follows:

// When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
// When a moving car collides with a stationary car, the number of collisions increases by 1.
// After a collision, the cars involved can no longer move and will stay at the point where they collided. Other than that, cars cannot change their state or direction of motion.

// Return the total number of collisions that will happen on the road.

 

// Example 1:

// Input: directions = "RLRSLL"
// Output: 5
// Explanation:
// The collisions that will happen on the road are:
// - Cars 0 and 1 will collide with each other. Since they are moving in opposite directions, the number of collisions becomes 0 + 2 = 2.
// - Cars 2 and 3 will collide with each other. Since car 3 is stationary, the number of collisions becomes 2 + 1 = 3.
// - Cars 3 and 4 will collide with each other. Since car 3 is stationary, the number of collisions becomes 3 + 1 = 4.
// - Cars 4 and 5 will collide with each other. After car 4 collides with car 3, it will stay at the point of collision and get hit by car 5. The number of collisions becomes 4 + 1 = 5.
// Thus, the total number of collisions that will happen on the road is 5. 
// Example 2:

// Input: directions = "LLRR"
// Output: 0
// Explanation:
// No cars will collide with each other. Thus, the total number of collisions that will happen on the road is 0.
 

// Constraints:

// 1 <= directions.length <= 105
// directions[i] is either 'L', 'R', or 'S'.




class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        stack<char>st;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(directions[i]);
            }
            else
            {
                // agar koyi Car right mein jaa rahi hai and koyi car left mein aa rahi hai toh collision hoga toh hum stack se right aane waali car ko hata denge and uski jagah 'S' daal denge taaki ye bata saken ki dono gaadi stop hogayi hai
                if(st.top()=='R' && directions[i]=='L')
                {
                    count += 2;
                    st.pop();
                    st.push('S');
                }
                else if(st.top()=='R' && directions[i]=='S')
                {
                    count += 1;
                    st.pop();
                    st.push(directions[i]);
                }
                // agar koyi car already stop hai and koyi car left mein jaa rahi hai toh collision hoga and left mein jaane waali car stop ho jayegi
                else if(st.top()=='S' && directions[i]=='L')
                {
                    count += 1;
                    st.push('S');
                }
                // agar upar waala koyi case nahi bana toh bas stack mein push kardo
                else
                {
                    st.push(directions[i]);
                }
            }
        }
        // ab agar stack mein top par right mein jaane waali cars hai toh unhe pop kardo
        while(!st.empty() && st.top() == 'R')
            st.pop();
        // agar stack ke top par koyi car nahi bachi jo ki right mein jaa rahi ho toh tab tak pop karo jab tak koyi aesi car na mile jo ki right mein jaa rahi ho and jese hi koyi car mile jo ki right mein jaa rahi ho toh pop kardo and count ko increase kardo because agar ye right jaane waali car baad mein aayi hai aur hum isse pehle un cars ko nikal chuke hai jo stay par thi toh iska matlab ye right mein jaane waali car stay par rehne waali car ke saath takraane waali hai
        while(!st.empty())
        {
            if(st.top() == 'R')
                count++;
            st.pop();
        }
        return count;
    }
};
