// A string s is called happy if it satisfies the following conditions:

// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.
// Example 2:

// Input: a = 7, b = 1, c = 0
// Output: "aabaa"
// Explanation: It is the only correct answer in this case.
 

// Constraints:

// 0 <= a, b, c <= 100
// a + b + c > 0



class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,char>>pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        while(pq.size()>1)
        {
            char first=pq.top().second;
            int firstCnt=pq.top().first;
            pq.pop();
            char second=pq.top().second;
            int secondCnt=pq.top().first;
            pq.pop();
            if(first!=0 and second!=0)
           {
                if(firstCnt>secondCnt)
                {
                ans+=first;
                ans+=first;
                ans+=second;

                firstCnt-=2;
                secondCnt--;

                }
                else if(secondCnt>firstCnt)
                {
                    ans+=second;
                    ans+=second;
                    ans+=first;
                    secondCnt-=2;
                    firstCnt--;
                }
                else
                {
                    ans+=second;
                    ans+=first;
                    firstCnt--;
                    secondCnt--;

                }
            }
            if(firstCnt!=0)pq.push({firstCnt,first});
            if(secondCnt!=0)pq.push({secondCnt,second});
        }
        if(pq.size() and ans.back()!=pq.top().first)
        {
            if(pq.top().first>2)
            {
                ans+=pq.top().second;
                ans+=pq.top().second;
            }
            else if(pq.top().first==1)
            {
                ans+=pq.top().second;
            }
        }
        return ans;
    }
};
