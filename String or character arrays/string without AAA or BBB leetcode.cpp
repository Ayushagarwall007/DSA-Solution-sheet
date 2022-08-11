// Given two integers a and b, return any string s such that:

// s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
// The substring 'aaa' does not occur in s, and
// The substring 'bbb' does not occur in s.
 

// Example 1:

// Input: a = 1, b = 2
// Output: "abb"
// Explanation: "abb", "bab" and "bba" are all correct answers.
// Example 2:

// Input: a = 4, b = 1
// Output: "aabaa"
 

// Constraints:

// 0 <= a, b <= 100
// It is guaranteed such an s exists for the given a and b.




class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;
        string l="a",r="b";
        while(a+b>0){
            if(a>b){
                if(a)ans+=l,a--;
                if(a)ans+=l,a--;
                if(b)ans+=r,b--;
            }
            else if(b>a){
                if(b)ans+=r,b--;
                if(b)ans+=r;b--;
                if(a)ans+=l,a--;
            }
            else{
                if(a)ans+=r,a--;
                if(b)ans+=l,b--;
            }
        }
        return ans;
    }
};
