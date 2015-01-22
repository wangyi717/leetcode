/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        vector<vector<int> > f(m, vector<int>(n));
        f[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != 0 && j != 0) {
                    f[i][j] = 0;
                }
                if (i != 0) {
                    f[i][j] += f[i - 1][j];
                }
                if (j != 0) {
                    f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
};

int main() {
    Solution solution;
    cout << "There are " << solution.uniquePaths(3, 7) << " unique paths of 3x7 grid" << endl;
    return 0;
}
