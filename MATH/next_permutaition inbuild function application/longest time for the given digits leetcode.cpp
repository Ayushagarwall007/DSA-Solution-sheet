// Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.

// 24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.

// Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.

 

// Example 1:

// Input: arr = [1,2,3,4]
// Output: "23:41"
// Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.
// Example 2:

// Input: arr = [5,5,5,5]
// Output: ""
// Explanation: There are no valid 24-hour times as "55:55" is not valid.
 

// Constraints:

// arr.length == 4
// 0 <= arr[i] <= 9



class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        string s="";
        int ans=-1;
        do
        {
            int h=arr[0];
            int h1=arr[1];
            int m=arr[2];
            int m1=arr[3];
            int hr=h*10+h1;
            int min=m*10+m1;
            if(hr>23 or min>59)continue;
            if(hr*60+min>ans)
            {
                ans=hr*60+min;
                s.clear();
                s.push_back(h+48);
                s.push_back(h1+48);
                s.push_back(':');
                s.push_back(m+48);
                s.push_back(m1+48);
            }
        }while(next_permutation(arr.begin(),arr.end()));
        return s;
    }
};
