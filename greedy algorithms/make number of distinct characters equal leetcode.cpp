// You are given two 0-indexed strings word1 and word2.

// A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].

// Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.

 

// Example 1:

// Input: word1 = "ac", word2 = "b"
// Output: false
// Explanation: Any pair of swaps would yield two distinct characters in the first string, and one in the second string.
// Example 2:

// Input: word1 = "abcc", word2 = "aab"
// Output: true
// Explanation: We swap index 2 of the first string with index 0 of the second string. The resulting strings are word1 = "abac" and word2 = "cab", which both have 3 distinct characters.
// Example 3:

// Input: word1 = "abcde", word2 = "fghij"
// Output: true
// Explanation: Both resulting strings will have 5 distinct characters, regardless of which indices we swap.
 

// Constraints:

// 1 <= word1.length, word2.length <= 105
// word1 and word2 consist of only lowercase English letters.




class Solution {
public:
   bool isItPossible(string word1, string word2) {
    unordered_map<char, int> mp1, mp2;
    //add all chars to the map
    for(char ch: word1) mp1[ch]++;
    for(char ch: word2) mp2[ch]++;
    // if(mp1.size()==mp2.size())return true; 

    for(int i=0; i < 26; i++){
        for(int j=0; j < 26; j++){
            char ch1 = i + 'a', ch2 = j + 'a';
            if(mp1.count(ch1) && mp2.count(ch2)){
                //remove one char from both to swap
                if(--mp1[ch1] == 0) mp1.erase(ch1);
                if(--mp2[ch2] == 0) mp2.erase(ch2);

                //add the new char
                mp1[ch2]++;
                mp2[ch1]++;

                //if distinct chars in both, return true
                if(mp1.size() == mp2.size())
                    return true;

                //add back the removed chars, also remove the new added chars
                if(--mp1[ch2] == 0) mp1.erase(ch2);
                if(--mp2[ch1] == 0) mp2.erase(ch1);
                mp1[ch1]++;
                mp2[ch2]++;
            }
        }
    }
    return false;
}
};
