//   Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 class Solution {
public:
    string frequencySort(string s) {
    map<char,int> mp;
    for(char ch:s){
        mp[ch]++;  //key=char, value=int(count)
    }
    
    priority_queue<pair<int,char>> pq;  //MAX HEAP
    
    for(auto it: mp) pq.push({it.second, it.first}); //max heap will arrange the heap on the basis of count
    
    string str;
    
    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        
        for(int i=0;i<top.first;i++){  
            str+=top.second;
        }
    }
    return str;
}
};
