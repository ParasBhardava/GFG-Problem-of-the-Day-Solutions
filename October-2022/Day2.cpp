/*

Problem Link : https://practice.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1

Minimum characters to be added at front to make string palindrome

Given string str of length N. The task is to find the minimum characters to be added at the front to make
string palindrome.
Note: A palindrome is a word which reads the same backward as forward. Example: "madam".

Input:
S = "abc"
Output: 2
Explanation:
Add 'b' and 'c' at front of above string to make it
palindrome : "cbabc"

Input:
S = "aacecaaa"
Output: 1
Explanation: Add 'a' at front of above string
to make it palindrome : "aaacecaaa"

Constraints:
1 <= S.length <= 106

*/

/*-----------------------------------------------------------------------------------------------------------*/

private:
vector<int> LPS(string &s)
{
    int n = s.size();
    int i = 1, len = 0;

    vector<int> lps(n, 0);

    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            if (len != 0)
                len = lps[len - 1];

            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

public:
int minChar(string str)
{
    int n = str.size();
    string s = str;
    s.push_back('$');
    reverse(str.begin(), str.end());
    s += str;

    vector<int> lps = LPS(s);
    return n - lps.back();
}

// Time : O(n)
// Space : O(n)

/*---------------------------------------------------------------------------------------------------------------------*/

/*
Here intuition is to used LPS array to find Minimum characters to be added at front to make string palindrome.
LPS array ---> Generally Used in KMP algorithm for string pattern matchin algorithm.
*/