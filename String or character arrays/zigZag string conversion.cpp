// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"
 

// Constraints:

// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000



class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows,vector<char>(s.size(),'#'));
        
        if(numRows==1) return s;
        
        int k=1,i,j=0;
        v[0][0]=s[0];
        while(k<s.size()){
            for(i=1;i<numRows && k<s.size();i++)
            {
                v[i][j]=s[k];
                k++;
            }
           // cout<<"&&"<<i<<"&&"<<endl;
            i=i-1;
            while(k<s.size() && i>0)
            {
                v[i-1][j+1]=s[k];
                k++;
                i--;
                j++;
            }
        }
        
        string res="";
        for(i=0;i<numRows;i++)
        {
            for(j=0;j<s.size();j++)
            {
                if(v[i][j]!='#' && v[i][j]!=' ')
                    res+=v[i][j];
            }
        }
        return res;
    }
};
