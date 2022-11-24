// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

 

// Example 1:

// Input: fruits = [1,2,1]
// Output: 3
// Explanation: We can pick from all 3 trees.
// Example 2:

// Input: fruits = [0,1,2,2]
// Output: 3
// Explanation: We can pick from trees [1,2,2].
// If we had started at the first tree, we would only pick from trees [0,1].
// Example 3:

// Input: fruits = [1,2,3,2,2]
// Output: 4
// Explanation: We can pick from trees [2,3,2,2].
// If we had started at the first tree, we would only pick from trees [1,2].
 

// Constraints:

// 1 <= fruits.length <= 105
// 0 <= fruits[i] < fruits.length



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Using unordered map as baskets
        unordered_map<int,int> basket;
        int i = 0, count = 0;
        for (int j = 0; j < fruits.size(); j++){
            // Putting new fruits in our basket or increasing the number of the fruit
            // if its already in the basket
            basket[fruits[j]]++;
            // If basket size exceeds 2 removing the extra fruits
            while (basket.size() > 2 && i < j){
                basket[fruits[i]]--;
                if (basket[fruits[i]] == 0){
                    basket.erase(fruits[i]);
                }
                i++;
            }
            // Updating count
            count = max(count, (j - i + 1));
        }
        return count;
    }
};
