// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in
// the flowerbed without violating the no-adjacent-flowers rule.

 

// Example 1:

// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: true
// Example 2:

// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: false

// '''condition 1 : If current position is not planted (i.e 0) and it's immediate next position is also not planted(i.e 0) then we can plant 1 tree their. so decrement n by 1 since we planted 1 tree and move 2 position next.

// condition 2: If currenet position is planted i.e 1 we need to move forward by 2 position since we can not plant tree adjacent.

// condition 3: If current position is 0 and it's next is 1 then we need to move forward by 3 positions ,because we can't plant at current position since it's
//   immediate next is planted , it's next position is also planted , and planting after 2 position is also wrong so we move forward by 3 positions.

// Special case : let s be the size of the given array if we we are at n-2 position then above conditions may not run for last 2 positions so we need to check for 
//   it also, if n-2 is zero and n-1 also zero then we can plant one more tree.
// '''
class Solution {
public:
bool canPlaceFlowers(vector& flowerbed, int n) {
int s=flowerbed.size();
int i=0;
while(i<s-1)
{
if(!flowerbed[i]&& !flowerbed[i+1])
{
n--;
i+=2;
}
else if(flowerbed[i]==1)
{
i+=2;
}
else
{
i+=3;
}
}
if(i<s && flowerbed[i]==0)
{
n--;
}
if(n<=0)
return true;
return false;
}
};
