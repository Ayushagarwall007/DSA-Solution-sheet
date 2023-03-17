// A sentence is a list of words that are separated by a single space with no leading or trailing spaces. For example, "Hello World", "HELLO", "hello world hello world" are all sentences. Words consist of only uppercase and lowercase English letters.

// Two sentences sentence1 and sentence2 are similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. For example, sentence1 = "Hello my name is Jane" and sentence2 = "Hello Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in sentence2.

// Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

 

// Example 1:

// Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
// Output: true
// Explanation: sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".
// Example 2:

// Input: sentence1 = "of", sentence2 = "A lot of words"
// Output: false
// Explanation: No single sentence can be inserted inside one of the sentences to make it equal to the other.
// Example 3:

// Input: sentence1 = "Eating right now", sentence2 = "Eating"
// Output: true
// Explanation: sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.
 

// Constraints:

// 1 <= sentence1.length, sentence2.length <= 100
// sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
// The words in sentence1 and sentence2 are separated by a single space.



class Solution {
public:
vector<string>parse(string &sentence){
        vector<string>ans;
        int start=0,prev=0;
        while(start<sentence.size()){
            if(sentence[++start]==' '){
                ans.push_back(sentence.substr(prev,start-prev));
                prev=++start;
            } else if(start==sentence.size()){
                ans.push_back(sentence.substr(prev));
            }
        }
        return ans;
    }
    bool areSentencesSimilar(string s1, string s2) {
        if(s2.size()>s1.size())
        swap(s1,s2);
        if(s1.size()==s2.size()) return s1==s2;

        else
        {
            vector<string> first=parse(s1);
            vector<string>second=parse(s2);

            int start=0,end=second.size()-1,strtcnt=0,endcnt=0;

            for(int i=0;i<first.size();i++)
            {
                if(first[i]==second[start])
                {
                    if(++start==second.size())
                    return true;
                    strtcnt++;
                    
                }
                else break;

            }
            
            for(int i=first.size()-1;i>=0;i--){
                if(first[i]==second[end]){
                    if(--end<0){
                        return true;
                    }
                    endcnt++;
                } else {
                    break;
                    
                }
            }
            return strtcnt+endcnt==second.size();

        }
    }
};
