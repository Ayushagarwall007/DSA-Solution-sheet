// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

// Example 1:

// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
// Example 2:

// Input: hand = [1,2,3,4,5], groupSize = 4
// Output: false
// Explanation: Alice's hand can not be rearranged into groups of 4.

 

// Constraints:

// 1 <= hand.length <= 104
// 0 <= hand[i] <= 109
// 1 <= groupSize <= hand.length





class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int N) {
        // first put everything into priority queue
        priority_queue<int>pq;
        map<int,int>mp;  // this is to store the frequency 

        for(int i=0;i<hand.size();i++)
        {   
            mp[hand[i]]++;
            if(mp[hand[i]]==1)
              pq.push(hand[i]);   // only unique element are pushed into pq
        }

        // we need another data structure say temp so as to store the element who have been popped but occurred with still has some instance left due to multiple ooccurence , so can be pushed again after one cycle
        
        while(!pq.empty())
        {
            int count=N;
            int last=-1;
            vector<int>temp;

            while(count && !pq.empty())
            {   
                // if thats the first element of the group , no need to compare but store it in last and decrease the freq, if it still has freq left then push into the temp
                if(last==-1)
                {
                    last=pq.top();
                    mp[last]--;
                    if(mp[last]>0)
                    {
                        temp.push_back(last);
                    }
                    pq.pop();
                    count--;
                }
                
                else
                {   
                    // compare the newelement to the last is thats continous then fine else return 0 , same way check if still frequency is left then push into temp
                    int newe=pq.top();
                    mp[newe]--;
                    if(mp[newe]>0)
                    {
                        temp.push_back(newe);
                    }
                    pq.pop();
                    if(newe==(last-1))
                    {   
                        last=newe;
                        count--;
                    }
                    else
                    {   
                        return 0;
                    }

                }

            }
            // if pq became empty and still the count >0 ie group can't be formed
            if(count>0 && pq.empty())
            {
               return 0; 
            }
            // push all those element that have still freq left 
            for(int i=0;i<temp.size();i++)
            {
                pq.push(temp[i]);
            }
        }
        // in all other cases where the iteration is complete ie the 0 was not returned hence they can be distributed in group size 
        return 1;
    }
};
