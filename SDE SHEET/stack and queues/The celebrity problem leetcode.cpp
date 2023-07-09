// In a party of N people, only one person is known to everyone. Such a person may be present at the party, if yes, (s)he doesn’t know anyone at the party. We can only ask questions like “does A know B? “. Find the stranger (celebrity) in the minimum number of questions.
// We can describe the problem input as an array of numbers/characters representing persons in the party. We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, and false otherwise. How can we solve the problem? 

// Examples:  

// Input:
// MATRIX = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0} }
// Output: id = 2
// Explanation: The person with ID 2 does not know anyone but everyone knows him

// Input:
// MATRIX = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 1, 0} }
// Output: No celebrity
// Explanation: There is no celebrity.







#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	 stack<int> stk;
	 
	 for(int i=0; i<n; i++) stk.push(i);
	 
	 while(stk.size()>1)
	 {
		 int x = stk.top();
		 stk.pop();
		 int y = stk.top();
		 stk.pop();

		 if (knows(x,y)) stk.push(y);
		 else stk.push(x);
	 }

	 int per = stk.top();

	 for(int i=0; i<n; i++)
	 if ((per != i) && (knows(per, i) || !knows(i, per))) return -1;

	 return per;
	 
}
