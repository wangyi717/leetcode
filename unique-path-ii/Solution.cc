/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m == 1) {
            for (int i = 0; i < n; ++i) {
                if (obstacleGrid[0][i] == 1) {
                    return 0;
                }
            }
            return 1;
        }
        if (n == 1) {
            for (int i = 0; i < n; ++i) {
                if (obstacleGrid[i][0] == 1) {
                    return 0;
                }
            }
            return 1;
        }
        if (obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int> > f(m, vector<int>(n));
        f[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != 0 && j != 0) {
                    f[i][j] = 0;
                }
                if (i != 0 && obstacleGrid[i - 1][j] != 1) {
                    f[i][j] += f[i - 1][j];
                }
                if (j != 0 && obstacleGrid[i][j - 1] != 1) {
                    f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int> > obstacleGrid(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            obstacleGrid[i][j] = 0;
        }
    }
    obstacleGrid[1][1] = 1;
    Solution solution;
    cout << "There are " << solution.uniquePathWithObstacles(obstacleGrid) << " unique paths in the example obstacleGrid." << endl;
    return 0;
}
