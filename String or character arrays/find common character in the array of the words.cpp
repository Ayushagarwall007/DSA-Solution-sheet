// 1002. Find Common Character

// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

// Example 1:

// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:

// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]
 

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of lowercase English letters.



class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        // unordered_map<int,int> mp;
        vector<string>ans;
        vector<int> arr(26,0);
        for(int i=0;i<words[0].length();i++){  //O(M)
            char c=words[0][i];
            arr[c-'a']++;
        }
        
        
        for(int i=1;i<words.size();i++){
            int n=words[i].length();   //O(N*M)
            vector<int>count(26,0);
            for(int j=0;j<n;j++){
                char c=words[i][j];
                count[c-'a']++;
            }
            
            for(int i=0;i<26;i++){   //O(26)
                arr[i]=min(arr[i],count[i]);
            }
        }
        
        
        for(int i=0;i<26;i++){
            int j=arr[i];    //O(26*E)
            
            while(j--){
                string s;
                s.push_back(i+'a');
                ans.push_back(s);
            }
        }
        
        
        return ans;
    }
};
