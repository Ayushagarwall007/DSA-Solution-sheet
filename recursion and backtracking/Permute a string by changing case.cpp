// Permute a string by changing case
// Difficulty Level : Hard
// Last Updated : 06 Sep, 2022
// Read
// Discuss

// Print all permutations of a string keeping the sequence but changing cases.

// Examples: 

// Input : ab
// Output : AB Ab ab aB

// Input : ABC
// Output : abc Abc aBc ABc abC AbC aBC ABC
// Recommended: Please try your approach on {IDE} first, before moving on to the solution.
// Method 1 (Naive) : Naive approach would be to traverse the whole string and for every character, consider two cases, (1) change case and recur (2) Do not change case and recur.



// CPP code to print all permutations
// with respect to cases
#include <bits/stdc++.h>
using namespace std;

// Function to generate permutations
void permute(string ip, string op)
{
	// base case
	if (ip.size() == 0) {
		cout << op << " ";
		return;
	}
	// pick lower and uppercase
	char ch = tolower(ip[0]);
	char ch2 = toupper(ip[0]);
	ip = ip.substr(1);

	permute(ip, op + ch);
	permute(ip, op + ch2);
}

// Driver code
int main()
{
	string ip = "aB";
	permute(ip, "");
	return 0;
}
