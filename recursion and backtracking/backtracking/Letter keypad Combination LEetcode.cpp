// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].



// using backtracking approach to apply  the proncipal of take and not take
class Solution {
public:
void solve(string digit,string output,int index,vector<string>& ans,string mapping[])
{
    if(index>=digit.size())
    {
        ans.push_back(output);
        return;
    }
    int number=digit[index]-'0';
    string value=mapping[number];
    for(int i=0;i<value.size();i++)
    {
        output.push_back(value[i]);
        solve(digit,output,index+1,ans,mapping);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0)
        return ans;
        string output;
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return ans;
    }
};

// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         vector<string> v;
//         vector<string>phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//         if(digits.size()==0)return v;
//         v.push_back("");

//         for(auto digit:digits)
//         {
//             vector<string>temp;
//             for(auto click:phone[digit-'0'])
//             {
//                 cout<<click<<"-> ";
//                 for(auto x:v)
//                 {
//                     cout<<x<<" ";
//                     temp.push_back(x+click);
//                 }
//                 cout<<endl;
//             }
//             v=temp;
//         }
//         return v;
//     }
// };
