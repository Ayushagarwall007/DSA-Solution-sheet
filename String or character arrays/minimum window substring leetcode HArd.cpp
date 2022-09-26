// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
 

// Follow up: Could you find an algorithm that runs in O(m + n) time?



class Solution {
public:
string minWindow(string s, string t) {
int i=0;
int j=0;
string result="";

int len=INT_MAX;
unordered_map<char,int>mp;
    
    
for(int i=0;i<t.length();i++){
    mp[t[i]]++;
}
    
int count=mp.size();
while(j<s.length()){
    
    if(mp.find(s[j])!=mp.end()){
        mp[s[j]]--;
        if(mp[s[j]]==0){
            count--;
        }
    }
    
    if(count>0){
        j++;
    }
    else if(count==0){
        if(j-i+1<len){
            len=min(len,j-i+1);
            // start=i;
            result=s.substr(i,len);
        }
        
    
        while(count==0){
            if(mp.find(s[i])==mp.end()){
                i++;
                if(j-i+1<len){
                    len=min(len,j-i+1);
                    // start=i;
                    result=s.substr(i,len);
                }
            }else{
                mp[s[i]]++;
                if(mp[s[i]]==1){
                    i++;
                    count++;
                }else{
                    i++;
                    if(j-i+1<len){
                    len=min(len,j-i+1);
                    // start=i;
                    result=s.substr(i,len);
                }
                    
                }
            }
        }
        j++;
    }
    
}
return (len==INT_MAX?"":result);
}
};
