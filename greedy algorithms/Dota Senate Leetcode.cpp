// In the world of Dota2, there are two parties: the Radiant and the Dire.

// The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

// Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
// Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
// Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

// The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

// Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".

 

// Example 1:

// Input: senate = "RD"
// Output: "Radiant"
// Explanation: 
// The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
// And the second senator can't exercise any rights anymore since his right has been banned. 
// And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
// Example 2:

// Input: senate = "RDD"
// Output: "Dire"
// Explanation: 
// The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
// And the second senator can't exercise any rights anymore since his right has been banned. 
// And the third senator comes from Dire and he can ban the first senator's right in round 1. 
// And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
 

// Constraints:

// n == senate.length
// 1 <= n <= 104
// senate[i] is either 'R' or 'D'.





// In this specific case, we can apply the following strategy:
// Count the number of senators belonging to each party.
// If one of the parties has no senators, the other party wins.
// Otherwise, start iterating over the senators in the given order.
// For each senator, check whether there are still senators from both parties with the right to vote.
// If so, ban the right of a senator from the opposite party (it doesn't matter which one).
// If not, the party with the remaining senators wins.
// Approach
// we keep two separate queues, one for Radiant senators and the other for Dire senators.
// We start by adding all the senators to their respective queues. Then, we simulate the voting process by taking the senator from the front of each queue and checking which one has a lower ID (index).
// The senator with the lower ID wins and we add him back to the end of his queue, but with an increased ID (by adding n to it), as it can be banned in 2nd round.





class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> rq,dq;
        
        for(int i=0;i<n;i++)
        {
            if(senate[i] == 'R')
                rq.push(i);
            else
                dq.push(i);
        }
        
        while(!rq.empty() && !dq.empty())
        {
            int a=rq.front(),b=dq.front();
            rq.pop();
            dq.pop();
            
            if(a < b)
            {
                rq.push(a + n);
            }
            else
            {
                dq.push(a + n);
            }
        }
        
        if(!rq.empty())
            return "Radiant";
        
        return "Dire";
    }
};
