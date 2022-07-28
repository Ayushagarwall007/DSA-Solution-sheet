// Question number  290 Leet Code
// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
 

// Constraints:

// 1 <= pattern.length <= 300
// pattern contains only lower-case English letters.
// 1 <= s.length <= 3000
// s contains only lowercase English letters and spaces ' '.
// s does not contain any leading or trailing spaces.
// All the words in s are separated by a single space.



class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<string> v;
        s+=" ";
        string str = "";
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                v.push_back(str);
                str = "";
            }else{
                str += s[i];
            }
        }
        // for(int i=0; i<v.size(); i++){
        //     cout<<v[i]<<" ";
        // }
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        if(p.length() != v.size()){
            return false;
        }
        for(int i=0; i<p.length(); i++){
            if(mp1.find(p[i])==mp1.end() && mp2.find(v[i])==mp2.end()){
                mp1[p[i]] = v[i];
                mp2[v[i]] = p[i];
            }else if(mp1[p[i]] != v[i]){
                return false;
            }
        }
        return true;
    }
};
