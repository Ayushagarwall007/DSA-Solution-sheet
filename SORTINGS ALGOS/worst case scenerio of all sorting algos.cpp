1 -> BUBBLE SORT WORST CASE SCENERIO
// Worst Case Analysis for Bubble Sort:
// The worst-case condition for bubble sort occurs when elements of the array are arranged in decreasing order.
// In the worst case, the total number of iterations or passes required to sort a given array is (n-1). where ‘n’ is a number of elements present in the array.

//   At pass 1 :  Number of comparisons = (n-1)
//                      Number of swaps = (n-1)

//   At pass 2 :  Number of comparisons = (n-2)
//                      Number of swaps = (n-2)

//   At pass 3 :  Number of comparisons = (n-3)
//                     Number of swaps = (n-3)
//                               .
//                              .
//                              .
//   At pass n-1 :  Number of comparisons = 1
//                         Number of swaps = 1

// Now , calculating total number of comparison required to sort the array
// = (n-1) + (n-2) +  (n-3) + . . . 2 + 1
// = (n-1)*(n-1+1)/2  { by using sum of N natural Number formula }
// = n (n-1)/2    

// For the Worst case:
// Total number of swaps = Total number of comparison
// Total number of comparison (Worst case) = n(n-1)/2
// Total number of swaps (Worst case) = n(n-1)/2

// Worst and Average Case Time Complexity: O(N2). The worst case occurs when an array is reverse sorted.
// Best Case Time Complexity: O(N). The best case occurs when an array is already sorted.
// Auxiliary Space: O(1)





2-> SELECTION SORT WORST CASE SCENRIO
