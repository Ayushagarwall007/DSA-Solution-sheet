// In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].

// Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 

// Example 1:

// Input: barcodes = [1,1,1,2,2,2]
// Output: [2,1,2,1,2,1]
// Example 2:

// Input: barcodes = [1,1,1,1,2,2,3,3]
// Output: [1,3,1,3,1,2,1,2]
 

// Constraints:

// 1 <= barcodes.length <= 10000
// 1 <= barcodes[i] <= 10000


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()==1 || barcodes.size()==0){
            return barcodes;
        }
        map<int,int>m;
        vector<int>ans;
        for(auto it: barcodes){m[it]++;}
        priority_queue<pair<int,int>>q;
        for(auto it: m){q.push({it.second,it.first});}
        while(q.top().first>0){
            pair<int,int>p=q.top();
            q.pop();
            ans.push_back(p.second);
            p.first--;
            pair<int,int>p2=q.top();
            q.pop();
            if(p2.first>0){
                
                ans.push_back(p2.second);
                p2.first--;
            }
            q.push(p);
            q.push(p2);
        }
        return ans;
    }
};
