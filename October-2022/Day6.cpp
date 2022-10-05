/*

Problem Link : https://practice.geeksforgeeks.org/problems/mila-and-strings0435/1

Lexicographically smallest string

Given a string S consisting of only lowercase characters.
Find the lexicographically smallest string after removing
exactly k characters from the string. But you have to correct the value of k,
i.e., if the length of the string is a power of 2, reduce k by half, else multiply k by 2.
 You can remove any k character.

NOTE: If it is not possible to remove k (the value of k after correction) characters or
if the resulting string is empty return -1.

Input: S = "fooland", k = 2
Output: "and"
Explanation: As the size of the string = 7 which is not a power of 2, hence k = 4.
After removing 4 characters from the given string, the lexicographically smallest
string is "and".

Input: S = "code", k = 4
Output: "cd"
Explanation: As the length of the string = 4, which is 2 to the power 2, hence k = 2.
Hence, lexicographically smallest string after removal of 2 characters is "cd".


Constraints:
1<= |S| <=10^5
1<= k <= 10^5

*/

/*---------------------------------------------------------------------------------------------------------------------------*/

// Using stack :

class Solution
{
public:
    string lexicographicallySmallest(string S, int k)
    {
        int n = S.size();

        if ((n & (n - 1)) == 0)
            k /= 2;

        else
            k *= 2;

        if (k >= n)
            return "-1";

        string res = "";
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty() || st.top() <= S[i])
                st.push(S[i]);
            else
            {
                while (!st.empty() && st.top() > S[i] && k > 0)
                {
                    k--;
                    st.pop();
                }

                st.push(S[i]);
            }
        }

        while (k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }

        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

// Time : O(n);
// Space :  O(n)

/*---------------------------------------------------------------------------------------------------------------------------*/

/*
Topic Tags : Stack, String

// Approach :

First find the correct value of k.
Then find the Lexicographically smallest string by removing exacly k characters from the given sting using stack.
If it is not posible to remove exactly k characters from string return "-1".

*/