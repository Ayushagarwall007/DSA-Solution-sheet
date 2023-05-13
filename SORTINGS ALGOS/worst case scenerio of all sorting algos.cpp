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





2-> QUICK SORT WORST CASE SCENRIO

// Worst Case:
// The worst case occurs when the partition process always picks the first or last element as the pivot. If we consider the above partition strategy where the last element is always picked as a pivot,
// the worst case would occur when the array is already sorted in increasing or decreasing order. Following is the recurrence for the worst case.

// T(N) = T(0) + T(N-1) + \theta    (N) which is equivalent to
// T(N) = T(N-1) + \theta    (N)

// The solution to the above recurrence is O(n2).
