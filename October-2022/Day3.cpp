/*
Problem Link : https://practice.geeksforgeeks.org/problems/modified-numbers-and-queries0904/1

Modified Numbers and Queries

Find the sum of all the numbers between the range l and r.
Here each number is represented by the sum of its prime factors.
Note : For example, 6 is represented by 5 because 6 has two prime factors
2 and 3 and 2 + 3 = 5.

Input: l = 1, r = 2
Output: 3
Explanation: 1->1, 2->2 and 1+2=3.

Input: l = 1, r = 6
Output: 18
Explanation: 1->1, 2->2, 3->3, 4->2
5->5, 6->2+3=5, 1+2+3+2+5+5 = 18.

Constraints:
1 <= l <= r <=10^4
*/

/*--------------------------------------------------------------------------------------------------------------*/

// Using Prime Factorization

class Solution
{
    int primeFactors(int num)
    {
        if (num == 1)
            return 1;

        unordered_set<int> s;
        for (int i = 2; i * i <= num; i++)
        {
            while (num % i == 0)
            {
                s.insert(i);
                num = num / i;
            }
        }

        if (num >= 2)
            s.insert(num);

        return accumulate(s.begin(), s.end(), 0);
    }

public:
    int sumOfAll(int l, int r)
    {

        int sum = 0;
        for (int i = l; i <= r; i++)
            sum += primeFactors(i);

        return sum;
    }
};

// Time : O(n * sqrt(n))
// Space : O(n)

/*---------------------------------------------------------------------------------------------------------------*/

// Using Sieve of Eratosthenes

class Solution
{

    static const int N = 10000;
    int smallestprimeFactor[N + 1];

    void createSieve()
    {
        for (int i = 0; i <= N; i++)
            smallestprimeFactor[i] = i;

        for (int i = 2; i * i <= N; i++)
        {
            if (smallestprimeFactor[i] == i)
            {
                for (int j = i * i; j <= N; j += i)
                {
                    if (smallestprimeFactor[j] == j)
                        smallestprimeFactor[j] = i;
                }
            }
        }
    }

    int primeFactorsSum(int num)
    {
        if (num == 1)
            return 1;

        int sum = 0;
        unordered_set<int> s;
        while (num != 1)
        {
            s.insert(smallestprimeFactor[num]);
            num = num / smallestprimeFactor[num];
        }

        return accumulate(s.begin(), s.end(), 0);
    }

public:
    int sumOfAll(int l, int r)
    {

        createSieve();
        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum += primeFactorsSum(i);
        }

        return sum;
    }
};

// Time : O(n * log(logn))
// Space : O(n)

/*-------------------------------------------------------------------------------------------------------------------*/

/*

Topic Tags : Mathematics, sieve

Approach :
For all number in range [l, r] find all unique prime factors and add it to sum.
At last return the sum.

*/