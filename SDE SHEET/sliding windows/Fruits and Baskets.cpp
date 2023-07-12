// There are 'n' fruit trees that are planted along a road. The

// trees are numbered from 0 to n-1. The type of fruit each tree bears is represented by an uppercase character of the English alphabet. A Ninja is walking along that road. He has two baskets and wants to put the maximum number of fruits in them. The restriction is that each basket can have only one type of fruit.

// Ninja can start with any tree and end at any tree, but once he has started he cannot skip a tree i.e if he picks fruit from the tree T, then he has to pick fruit from tree 'i+1' before going to the tree 'i+2. He will pick one fruit from each tree until he cannot, i.e, he will stop when he has to pick a fruit of the third type because both the baskets can be filled by only two different fruits.

// 13 14

// 15

// 16

// 17

// 18 19

// 20 21

// You are given a string 'str' consisting of the 'n' uppercase character of the English alphabet. The 'i'th character in this string represents the type of fruit tree 'i' bears. Return the maximum number of fruits ninja can put in both the baskets after satisfying all the given conditions.


#include <bits/stdc++.h> 

int findMaxFruits(string &str, int n) {

    // Write your code here

    int i = 0, j =0, maximum = 0;

    unordered_map<char, int> map;

    while(i < n){

        map[str[i]]++;

        if(map.size() <= 2){

             maximum = max(maximum, i - j + 1);

        }

        else if (map.size() > 2){

           while(map.size() != 2){

               map[str[j]]--;

               if(map[str[j]] == 0) map.erase(str[j]);

               j++;

           }

        }

        i++;

    }

    return maximum;

}
