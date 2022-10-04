/*
Problem Link : https://practice.geeksforgeeks.org/problems/geek-and-strings3030/1

Geek and Strings

Geek has a list Li containing (not necessarily distinct) N words and Q queries.
Each query consists of a string x. For each query,
find how many strings in the List Li has the string x as its prefix.

Input:
N = 5, Q = 5
li[] = {'abracadabra', 'geeksforgeeks', 'abracadabra', 'geeks', 'geeksthrill'}
query[] = {'abr', 'geeks', 'geeksforgeeks', 'ge', 'gar'}
Output: 2 3 1 3 0

Explaination:
Query 1: The string 'abr' is prefix of
two 'abracadabra'.
Query 2: The string 'geeks' is prefix of three
strings 'geeksforgeeks', 'geeks' and 'geeksthrill'.
Query 3: The string 'geeksforgeeks' is prefix
of itself present in li.
Query 4: The string 'ge' also is prefix of three
strings 'geeksforgeeeks', 'geeks', 'geeksthrill'.
Query 5: The string 'gar' is not a prefix of any
string in li.

Expected Time Complexity: O(Q*x)
Expected Auxiliary Space: O(N*li [i])


Constraints:
1 ≤ N ≤ 3 x 10^4
1 ≤ Q ≤ 10^4
1 ≤ |li[i]|, |x| ≤ 100

*/

/*------------------------------------------------------------------------------------------------------------------------*/

// Using Trie Data Structure

class Trie
{
    struct Trienode
    {
        bool endsHere;
        int count;
        Trienode *child[26];
    };

    Trienode *root;

    Trienode *getNode()
    {
        Trienode *newnode = new Trienode;
        newnode->endsHere = false;
        newnode->count = 0;

        for (int i = 0; i < 26; i++)
            newnode->child[i] = NULL;

        return newnode;
    }

public:
    Trie()
    {
        root = getNode();
    }

    void insert(string &word)
    {
        Trienode *curr = root;
        int index;

        for (char ch : word)
        {
            index = ch - 'a';
            if (curr->child[index] == NULL)
                curr->child[index] = getNode();

            curr->child[index]->count += 1;
            curr = curr->child[index];
        }

        curr->endsHere = true;
    }

    int countPrefix(string &word)
    {
        Trienode *curr = root;
        int index;
        int ans = 1e9;

        for (char ch : word)
        {
            index = ch - 'a';
            if (curr->child[index] == NULL)
                return 0;

            ans = min(ans, curr->child[index]->count);
            curr = curr->child[index];
        }

        return ans;
    }
};

class Solution
{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        vector<int> res(Q, 0);
        Trie *t = new Trie();

        for (int i = 0; i < N; i++)
            t->insert(li[i]);

        for (int i = 0; i < Q; i++)
            res[i] = (t->countPrefix(query[i]));

        return res;
    }
};

// Time :  O(Q * x)
// Space : O(N * li[i])

/*---------------------------------------------------------------------------------------------------------------------*/

/*

Topic Tags : Trie, String

Approach :
1) Created a Trie class with Trinode structure with count, endsHere and children.
2) Inserted each string into the trie tracking its occurance count.
3) Now checked whether the prefix is present or not, if present we just return the count we tracked else we return 0.
4) Store all the result inside the result list and return.

*/