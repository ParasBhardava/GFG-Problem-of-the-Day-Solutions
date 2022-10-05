/*

Problem Link : https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right3011/1

Count all possible paths from top left to bottom right

The task is to count all the possible paths from top left to bottom right of a m X n matrix
with the constraints that from each cell you can either move only to right or down.

Input: m = 2, n = 2
Output: 2
Explanation: Two possible ways are
RD and DR.

Input: m = 3, R = 3
Output: 6
Explanation: Six possible ways are
RRDD, DDRR, RDDR, DRRD, RDRD, DRDR.

Constraints:
1 <= m <= 100
1 <= n <= 100

*/

/*---------------------------------------------------------------------------------------------------------------*/

// Using dynemic programming

class Solution
{

private:
    const int MOD = 1e9 + 7;

private:
    long long solve(int n, int m)
    {
        vector<long long> dp(m, 1LL);

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[j] = (dp[j] % MOD + dp[j - 1] % MOD) % MOD;
            }
        }

        return dp[m - 1];
    }

public:
    long long int numberOfPaths(int n, int m)
    {
        return solve(n, m);
    }
};

// Time :O (n * m);
// Space : O(m)

/*--------------------------------------------------------------------------------------------------------------------------*/

/*

Topic Tags : Dynamic Programming

This is a standard DP problem on grid.
The number of ways to reach a cell = (no. of ways to reach cell above it) + (no. of ways to reach cell on its left)
There is only 1 way to reach cells that are in first column or first row

*/
