// to find all the prime numbers less than   the given number n;
//**********************************************************************************************************************************************************

//using sieve of erotothenesis simple ..... time complexity O(nlog(logn))
// in this  theoram phle saare elemets n tkk ko ek array mai save kaarke unko true  kaar dene hai 2 se start kaarna hai or check kaarna hai ki 2 prime number hai ki nahi 
// agar vo number prime hai to uske saare multiples ko false kaar denaa hai uptill number abb next true number ko dekhnaa hai or ye process repeat kaarna hai...
// last mai jo number baacenge vo prime numbers honghe

class Solution
{
    public:
    int countPrimes(int n)
    {
        int count =0;
        vector<bool>prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i<n;i++)
        {
            if(prime[i]){
                count++;
            for(int j=i*2;j<n;j=j+i)
                prime[j]=false;
            }
        }
        return count;
    }  
};


//**********************************************************************************************************************************************************
// usinf sieve of erotothenesis with the time complexity of O(n);

// For every number i where i varies from 2 to N-1:   Check if the number is prime. If the number  is prime, store it in prime array.
// For every prime numbers j less than or equal to the smallest   prime factor p of i:
//     Mark all numbers i*p as non_prime.
//     Mark smallest prime factor of i*p as j
// C++ program to generate all prime numbers
// less than N in O(N)
#include<bits/stdc++.h>
using namespace std;
const long long MAX_SIZE = 1000001;

// isPrime[] : isPrime[i] is true if number is prime
// prime[] : stores all prime number less than N
// SPF[] that store smallest prime factor of number
// [for Exp : smallest prime factor of '8' and '16'
// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ]
vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);

// function generate all prime number less than N in O(n)
void manipulated_seive(int N)
{
	// 0 and 1 are not prime
	isprime[0] = isprime[1] = false ;

	// Fill rest of the entries
	for (long long int i=2; i<N ; i++)
	{
		// If isPrime[i] == True then i is
		// prime number
		if (isprime[i])
		{
			// put i into prime[] vector
			prime.push_back(i);

			// A prime number is its own smallest
			// prime factor
			SPF[i] = i;
		}

		// Remove all multiples of i*prime[j] which are
		// not prime by making isPrime[i*prime[j]] = false
		// and put smallest prime factor of i*Prime[j] as prime[j]
		// [ for exp :let i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
		// so smallest prime factor of '10' is '2' that is prime[j] ]
		// this loop run only one time for number which are not prime
		for (long long int j=0;
			j < (int)prime.size() &&
			i*prime[j] < N && prime[j] <= SPF[i];
			j++)
		{
			isprime[i*prime[j]]=false;

			// put smallest prime factor of i*prime[j]
			SPF[i*prime[j]] = prime[j] ;
		}
	}
}

// driver program to test above function
int main()
{
	int N = 13 ; // Must be less than MAX_SIZE

	manipulated_seive(N);

	// print all prime number less than N
	for (int i=0; i<prime.size() && prime[i] <= N ; i++)
		cout << prime[i] << " ";

	return 0;
}



//*****************************************************************************************************************************************

// SEGMENTED SIEVE
// Problems with Simple Sieve:
// The Sieve of Eratosthenes looks good, but consider the situation when n is large, the Simple Sieve faces the following issues.

// An array of size Θ(n) may not fit in memory
// The simple Sieve is not cached friendly even for slightly bigger n. The algorithm traverses the array without locality of reference
// Segmented Sieve
// The idea of a segmented sieve is to divide the range [0..n-1] in different segments and compute primes in all segments one by one. This algorithm first uses Simple 
// Sieve to find primes smaller than or equal to √(n). Below are steps used in Segmented Sieve.

// Use Simple Sieve to find all primes up to the square root of ‘n’ and store these primes in an array “prime[]”. Store the found primes in an array ‘prime[]’.
// We need all primes in the range [0..n-1]. We divide this range into different segments such that the size of every segment is at-most √n
// Do following for every segment [low..high] 
// Create an array mark[high-low+1]. Here we need only O(x) space where x is a number of elements in a given range.
// Iterate through all primes found in step 1. For every prime, mark its multiples in the given range [low..high].
// In Simple Sieve, we needed O(n) space which may not be feasible for large n. Here we need O(√n) space and we process smaller ranges at a time (locality of reference)


// C++ program to print all primes smaller than
// n using segmented sieve
#include <bits/stdc++.h>
using namespace std;

// This functions finds all primes smaller than 'limit'
// using simple sieve of eratosthenes. It also stores
// found primes in vector prime[]
void simpleSieve(int limit, vector<int> &prime)
{
	// Create a boolean array "mark[0..n-1]" and initialize
	// all entries of it as true. A value in mark[p] will
	// finally be false if 'p' is Not a prime, else true.
	vector<bool> mark(limit + 1, true);

	for (int p=2; p*p<limit; p++)
	{
		// If p is not changed, then it is a prime
		if (mark[p] == true)
		{
			// Update all multiples of p
			for (int i=p*p; i<limit; i+=p)
				mark[i] = false;
		}
	}

	// Print all prime numbers and store them in prime
	for (int p=2; p<limit; p++)
	{
		if (mark[p] == true)
		{
			prime.push_back(p);
			cout << p << " ";
		}
	}
}

// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n)
{
	// Compute all primes smaller than or equal
	// to square root of n using simple sieve
	int limit = floor(sqrt(n))+1;
	vector<int> prime;
	prime.reserve(limit);
	simpleSieve(limit, prime);

	// Divide the range [0..n-1] in different segments
	// We have chosen segment size as sqrt(n).
	int low = limit;
	int high = 2*limit;

	// While all segments of range [0..n-1] are not processed,
	// process one segment at a time
	while (low < n)
	{
		if (high >= n)
		high = n;
		
		// To mark primes in current range. A value in mark[i]
		// will finally be false if 'i-low' is Not a prime,
		// else true.
		bool mark[limit+1];
		memset(mark, true, sizeof(mark));

		// Use the found primes by simpleSieve() to find
		// primes in current range
		for (int i = 0; i < prime.size(); i++)
		{
			// Find the minimum number in [low..high] that is
			// a multiple of prime[i] (divisible by prime[i])
			// For example, if low is 31 and prime[i] is 3,
			// we start with 33.
			int loLim = floor(low/prime[i]) * prime[i];
			if (loLim < low)
				loLim += prime[i];

			/* Mark multiples of prime[i] in [low..high]:
				We are marking j - low for j, i.e. each number
				in range [low, high] is mapped to [0, high-low]
				so if range is [50, 100] marking 50 corresponds
				to marking 0, marking 51 corresponds to 1 and
				so on. In this way we need to allocate space only
				for range */
			for (int j=loLim; j<high; j+=prime[i])
				mark[j-low] = false;
		}

		// Numbers which are not marked as false are prime
		for (int i = low; i<high; i++)
			if (mark[i - low] == true)
				cout << i << " ";

		// Update low and high for next segment
		low = low + limit;
		high = high + limit;
	}
}

// Driver program to test above function
int main()
{
	int n = 100000;
	cout << "Primes smaller than " << n << ":n";
	segmentedSieve(n);
	return 0;
}







