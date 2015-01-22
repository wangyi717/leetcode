#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > f;
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i].resize(m);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                f[i][j] = 0;
            }
        }
        f[0][0] = grid[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0)
                    continue;
                int a = 65535;
                int b = 65535;
                if (i != 0)
                    a = f[i - 1][j];
                if (j != 0)
                    b = f[i][j - 1];
                if (a < b) {
                    f[i][j] = grid[i][j] + a;
                } else {
                    f[i][j] = grid[i][j] + b;
                }
            }
        }
        return f[n-1][m-1];
    }
};


int main() {
    vector<vector<int> > grid;
    vector<int> row1;
    row1.push_back(5);
    row1.push_back(6);
    row1.push_back(18);
    vector<int> row2;
    row2.push_back(17);
    row2.push_back(10);
    row2.push_back(12);
    grid.push_back(row1);
    grid.push_back(row2);
    Solution s;
    int min = s.minPathSum(grid);
    cout << "The minimum path sum is: " << min << endl;
    return 0;
}
