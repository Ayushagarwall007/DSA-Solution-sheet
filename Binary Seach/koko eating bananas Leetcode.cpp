// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

 

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
 

// Constraints:

// 1 <= piles.length <= 104
// piles.length <= h <= 109
// 1 <= piles[i] <= 109

















// Steps:-
// The ok function checks if Koko can eat all the bananas within h hours at a given value of k. It takes in the vector piles, the integer mid which is the current value of k being tested, and returns a boolean value.

// General Observation
// here we use binary search and check if the assumed value (mid) is leading to answer otr not . if leading to answer then store that mid to answer and check futher mid .
// let us assume koko have ability of eating 100 banana per hour then she will eat whole banna in very less time . but we have to minimise that capacity .
// if koko eats at rate of 10 banana per hour and finish all banana before h time ,then she will be able to finish the same if she increase her capacity upto say 12, 13 or anything more than 10 . so she should minimise her capacity . Hence she should select left subarray (here in binary serach when uncertenty in finding any number we use number line as array and perform binary operation over it )
// lets take another case . lets koko eats 2 banana per hour and she does not finish whole banna within h hour.then she need to increase her speed and this is possible only when she moves in right direction of number line and hence we consider right subarry for further binary search operation .
// we have to also wait if koko have capacity more than banana . here ok function checks if finishing banana piles take interger or double time . if double then we have to wait . why so .. in question it is stated that koko have to wait if her speed of eating banana is more than the number of banana in pile . lets say her capacity is 5 banana per hour and the piles of banana contains 9 then time taken by koko to finish the banna is 9/5=1.8 . at this condition we have to add 2 hour in our anwer as per question koko need to wait for .8 hour and total 2 hour will be spent by her on that pile .
// if capacity is 5 and pile conatins 10 banana then simply it takes 10/5=2 hour . for checking whether koko have to wait(in case of double value after devision ) or not (in case of interger) . we use double of time > (int)time . example 2.3>2 as double is 2.3 and 2 is int part of the same .
// ok function do the same and calculate total time . if less than h hour we should decrese our speed .
// steps :-
// do binary seach and for each mid call ok function to check wether mid is possible answer or not .

// Define the ok function which takes in piles, mid and h as arguments.
// Initialize count to 0.
// Loop through the piles vector.
// Calculate the number of hours needed to eat the current pile of bananas using the formula temp = (double)piles[i] / (double)mid.
// If temp is not an integer, add (int)temp + 1 to the count variable. Otherwise, add temp to the count variable.
// If the count variable is greater than h, return false. Otherwise, return true.
class Solution {
public:
bool isPossible(vector<int>&piles,int mid,int h)
{
    int count=0;
    for(int i=0;i<piles.size();i++)
    {
        double temp=(double)piles[i]/(double)mid;
        if(temp>(int)temp)
        count+=(int)temp+1;
        else
        count+=temp;
    }
    if(count>h)return false;
    else return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int mid;
        int left=1;
        int right=1e9+5;
        int ans=0;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(isPossible(piles,mid,h))
            {
                ans=mid;
                right=mid;
            }
            else 
            left=mid+1;
        }
        return ans;
    }
};
