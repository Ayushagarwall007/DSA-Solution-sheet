// Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.

// Implement the SummaryRanges class:

// SummaryRanges() Initializes the object with an empty stream.
// void addNum(int value) Adds the integer value to the stream.
// int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.
 

// Example 1:

// Input
// ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
// [[], [1], [], [3], [], [7], [], [2], [], [6], []]
// Output
// [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

// Explanation
// SummaryRanges summaryRanges = new SummaryRanges();
// summaryRanges.addNum(1);      // arr = [1]
// summaryRanges.getIntervals(); // return [[1, 1]]
// summaryRanges.addNum(3);      // arr = [1, 3]
// summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
// summaryRanges.addNum(7);      // arr = [1, 3, 7]
// summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
// summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
// summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
// summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
// summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
 

// Constraints:

// 0 <= value <= 104
// At most 3 * 104 calls will be made to addNum and getIntervals.
 

// Follow up: What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?





class SummaryRanges {
public:
    set<int>st; //initialize set
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value); //adding value in set
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans; 
        vector<int>t(st.begin(),st.end()); // converting set to vector for better traversing [for me :)]
        int i = 0;
        while(i<t.size())
        {
            int start = t[i]; //start of interval
			
			//while there is values whose difference is 1 just consider it.. in the rangeand
            while(i+1<t.size() and t[i]+1 == t[i+1])
            {
                i++;
            }
            ans.push_back({start,t[i]});
            i++;
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
