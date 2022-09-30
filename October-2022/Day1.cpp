// Number of Distinct Islands
// Link : https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

/*

Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).



Input :
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}

Output : 1



Input
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}

Output : 3

*/

class Solution
{

private:
    void dfs(int i, int j, vector<pair<int, int>> &temp, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != 1)
            return;

        temp.push_back({i, j});
        grid[i][j] = 0;
        dfs(i + 1, j, temp, grid); // down
        dfs(i, j + 1, temp, grid); // right
        dfs(i - 1, j, temp, grid); // up
        dfs(i, j - 1, temp, grid); // left
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        set<vector<pair<int, int>>> res;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    vector<pair<int, int>> temp;
                    dfs(i, j, temp, grid);
                    auto start = temp[0];

                    for (auto &it : temp)
                    {
                        it.first -= start.first;
                        it.second -= start.second;
                    }

                    // for(auto &it : temp)
                    //     cout<< i.first << " " << i.second <<"\n";

                    if (res.find(temp) == res.end())
                        res.insert(temp);
                }
            }
        }

        return res.size();
    }
};

/*

Topic Tags : DFS, BFS, Graph

Approach :

Take one set to keep track of connected components in the grid. Perform any of the traversal and find the connected components with all value ones, if this connected component is not in the set then add it to the set. At last return the size of the set(as set only contains distinct connected components).

Here, I am using DFS traversal to find connected components in the grid.

*/