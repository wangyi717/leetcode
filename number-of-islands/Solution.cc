/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char> > &grid, int i, int j) {
        grid[i][j] = '0';
        if (i > 0 && grid[i - 1][j] == '1')
            dfs(grid, i - 1, j);
        if (i < grid.size() - 1 && grid[i + 1][j] == '1')
            dfs(grid, i + 1, j);
        if (j > 0 && grid[i][j - 1] == '1')
            dfs(grid, i, j - 1);
        if (j < grid[i].size() - 1 && grid[i][j + 1] == '1')
            dfs(grid, i, j + 1);
    }
public:
    int numIslands(vector<vector<char> > &grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
