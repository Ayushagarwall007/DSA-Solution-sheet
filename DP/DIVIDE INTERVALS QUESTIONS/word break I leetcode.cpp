// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
 

// Constraints:

// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.




// /*

//     Time Complexity : O(2^N), Given a string of length N, there are N+1 ways to split it into two parts. At each
//     step, we have a choice: to split or not to split. In the worse case, when all choices are to be checked, that
//     results in O(2^N).

//     Space Complexity : O(N), The depth of the recursion tree can go upto N.
    
//     Solved using String + Backtracking + Hash Table.

// */


// /***************************************** Approach 1 First Code *****************************************/

// class Solution {
// private:
//     bool wordBreak(string s, unordered_set<string> &set){
//         if(s.size() == 0){
//             return true;
//         }
//         for(int i=0; i<s.size(); i++){
//             if(set.count(s.substr(0, i+1)) && wordBreak(s.substr(i+1), set)){
//                 return true;
//             }
//         }
//         return false;
//     }
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> set(wordDict.begin(), wordDict.end());
//         return wordBreak(s, set);
//     }
// };






// /*

//     Time Complexity : O(2^N), Given a string of length N, there are N+1 ways to split it into two parts. At each
//     step, we have a choice: to split or not to split. In the worse case, when all choices are to be checked, that
//     results in O(2^N).

//     Space Complexity : O(N), The depth of the recursion tree can go upto N.
    
//     Solved using String + Backtracking + Hash Table.

// */


// /***************************************** Approach 1 Second Code *****************************************/

// class Solution {
// private:
//     bool wordBreak(string s, unordered_set<string> &set, int start){
//         if(start == s.size()){
//             return true;
//         }
//         for(int i=start; i<s.size(); i++){
//             if(set.count(s.substr(start, i+1-start)) && wordBreak(s, set, i+1)){
//                 return true;
//             }
//         }
//         return false;
//     }
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> set(wordDict.begin(), wordDict.end());
//         return wordBreak(s, set, 0);
//     }
// };






/*

    Time Complexity : O(N^3), Size of recursion tree can go up to N^2.

    Space Complexity : O(N), The depth of the recursion tree can go upto N.
    
    Solved using String + DP(Memoisation) + Hash Table.

*/


/***************************************** Approach 2 *****************************************/

class Solution {
private:
    bool wordBreak(string s, unordered_set<string> &set, vector<int> &memo, int start){
        if(start == s.size()){
            return true;
        }
        if(memo[start] != -1){
            return memo[start];
        }
        for(int i=start; i<s.size(); i++){
            if(set.count(s.substr(start, i+1-start)) && wordBreak(s, set, memo, i+1)){
                memo[start] = true;
                return true;
            }
        }
        return memo[start] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wordBreak(s, set, memo, 0);
    }
};






/*

    Time Complexity : O(N^3), There are two nested loops, and substring computation at each iteration. Overall
    that results in O(N^3) time complexity.

    Space Complexity : O(N), Length of dp array is N+1.
    
    Solved using String + DP(Tabulation) + Hash Table.

*/


/***************************************** Approach 3 *****************************************/

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<bool> dp(s.size()+1, 0);
//         dp[0] = true;
//         unordered_set<string> set(wordDict.begin(), wordDict.end());
//         for(int i=1; i<=s.size(); i++){
//             for(int j=0; j<i; j++){
//                 if(dp[j] && set.count(s.substr(j, i-j))){
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[s.size()];
//     }
// };

// struct Node {
//     Node* links[26];
//     bool flag = false;
//     bool containKey(char ch)
//     {
//         return (links[ch-'a']!=NULL);
//     }
//     void put(char ch , Node* node)
//     {
//         links[ch-'a'] = node;
//     }
//     Node* get(char ch)
//     {
//         return links[ch-'a'];
//     }
//     void setEnd()
//     {
//         flag = true;
//     }
//     bool isEnd()
//     {
//         return flag;
//     }
// };


// class Trie{
//     private:
//         Node* root;
//     public:
//         Trie()
//         {
//             root = new Node();
//         }

//         void insert(string s)
//         {
//             Node* node = root;
//             for(int i = 0;i<s.size();i++)
//             {
//                 if(!node->containKey(s[i]))
//                 {
//                     node->put(s[i],new Node());
//                 }
//                 node = node->get(s[i]);
//             }
//             node->setEnd();
//         }

//         bool search(string st)
//         {
//             Node* node = root; 
//             for(int i = 0;i<st.size();i++)
//             {
//                 if(!node->containKey(st[i])) return false;

//                 node = node->get(st[i]);
//             }

//             return node->isEnd();
//         }
// };

// class Solution {
    
// public:
     
//     bool wordBreak(string s, vector<string>& wordDict) {
  
//          Trie trie;
//         for(auto it: wordDict)
//         {
//             trie.insert(it);
//         }
        
        
//         vector<bool> dp(s.size()+1, false);
//         dp[0]=true;
        
//         for(int len=1; len<=s.size(); len++){
//             for(int i=0; i<len; i++){
//                 if(dp[i] && trie.search(s.substr(i, len-i)))
//                     dp[len]=true;
//             }
//         }
//         return dp[s.size()];

//     }
// };
