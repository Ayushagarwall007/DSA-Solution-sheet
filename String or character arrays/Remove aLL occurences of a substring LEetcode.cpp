// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.


//APPROACH 01
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string s1 = "";
        int n;
        int k;
        //great solution in this case
        for (int i = 0; i < s.size(); i++)
        {
            s1 =s1+ s[i];
            n = s1.size();
            k = part.size();

            if (n >= k && s1.substr(n - k) == part )
            {
                while (k--)
                {
                    s1.pop_back();
                }
            }
        }
        return s1;
    }
};


//APPROACH 02
class Solution {
public:
string removeOccurrences(string s, string part) {
int n=s.length();
int p=part.length();
int i=0;
while(i< n)
{

        if (s.substr(i,p)==part)
        {
            s.erase(i,p);
            i=0;    
        }
        else
        {
            i++;
        }
        n=s.length();
    }
    return s;
}
};



// RECURSIVE APROACH
class Solution {
public:

string removeOccurrences(string s, string part) {
   
    int found = s.find(part);
    if(found == -1) return s;
    s.erase(found , part.size());
    return removeOccurrences(s, part); 
return s;
}
};
