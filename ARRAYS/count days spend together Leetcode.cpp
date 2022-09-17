// Alice and Bob are traveling to Rome for separate business meetings.

// You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.

// Return the total number of days that Alice and Bob are in Rome together.

// You can assume that all dates occur in the same calendar year, which is not a leap year. Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

 

// Example 1:

// Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
// Output: 3
// Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.
// Example 2:

// Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
// Output: 0
// Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.
 

// Constraints:

// All dates are provided in the format "MM-DD".
// Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
// The given dates are valid dates of a non-leap year.



class Solution {
public:
    int countDaysTogether(string aA, string lA, string aB, string lB) {
        int aam = 10*(aA[0]-'0')+(aA[1]-'0');
        int aad = 10*(aA[3]-'0')+(aA[4]-'0');
        
        int alm = 10*(lA[0]-'0')+(lA[1]-'0');
        int ald = 10*(lA[3]-'0')+(lA[4]-'0');
        
        int bam = 10*(aB[0]-'0')+(aB[1]-'0');
        int bad = 10*(aB[3]-'0')+(aB[4]-'0');
        
        int blm = 10*(lB[0]-'0')+(lB[1]-'0');
        int bld = 10*(lB[3]-'0')+(lB[4]-'0');
        
        cout<<aam<<" "<<alm<<endl;
        cout<<bam<<" "<<blm<<endl;

        int arr[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 }; 
         
        int AA = arr[aam-1] + aad;
        int AL = arr[alm-1] + ald;
        
        int BA = arr[bam-1] + bad;
        int BL = arr[blm-1] + bld;
        int count = 0;
        if(AA<=BA){
            while(BA<=BL && BA<=AL){
                count++;
                BA++;
            }
        }else if(BA<=AA){
            while(AA<=AL && AA<=BL){
                AA++;
                count++;
            }
        }
        return count;      
    }
};
