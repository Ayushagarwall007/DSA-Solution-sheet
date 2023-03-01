// class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        string res="";
        priority_queue<char>pq;
        while(pq.size()>1)
        {
            auto ch=pq.top();
            pq.pop();
            auto ch1=pq.top();
            pq.pop();
            res+=ch;
            res+=ch1;
            mp[ch]--;
            mp[ch1]--;
            if(mp[ch]>0)pq.push(ch);
            if(mp[ch1]>0)pq.push(ch1);
        }
        if(!pq.empty())
        {
            int 
        }
        return res;
    }
};
