#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        unordered_set<int> MySet;
        int n = grid.size();
        vector<int> result(2, 0);
        int sum = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (MySet.find(grid[i][j]) != MySet.end())
                    result[0] = grid[i][j];
                else{
                    MySet.insert(grid[i][j]);
                    sum += grid[i][j];
                }
            }
        }
        result[1] = n * n * (n * n + 1) / 2 - sum;
        return result;
    }
};