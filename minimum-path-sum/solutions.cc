#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int vertexNum = n * m;
        if (n * m == 1) {
            return grid[0][0];
        }
        // matrix矩阵是grid的临接矩阵
        vector<vector<int> > matrix;
        // path矩阵用于存储最短路径
        // path应该是一个(n*m)*(n*m)的矩阵
        vector<vector<int> > path;
        // 首先初始化matrix和path矩阵，-1表示无法到达
        matrix.resize(vertexNum);
        path.resize(vertexNum);
        for (int i = 0; i < vertexNum; ++i) {
            matrix[i].resize(vertexNum);
            path[i].resize(vertexNum);
            for (int j = 0; j < vertexNum; ++j) {
                matrix[i][j] = 65535;
                path[i][j] = -1;
            }
        }
        int c = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == n - 1 && j == m - 1) {
                    break;
                }
                if (j == m - 1 && i != n -1) {
                    matrix[c][c + m] = grid[i + 1][j];
                } if (i == n - 1 && j != m - 1) {
                    matrix[c][c + 1] = grid[i][j + 1];
                } else {
                    matrix[c][c + 1] = grid[i][j + 1];
                    matrix[c][c + m] = grid[i + 1][j];
                }
                ++c;
            }
        }
        // Floyd实现
        for (int k = 0; k < vertexNum; ++k) {
            for (int i = 0; i < vertexNum; ++i) {
                for (int j = 0; j < vertexNum; ++j) {
                    if (matrix[i][k] != -1 && matrix[k][j] != -1 && matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                        path[i][j] = k;
                    }
                }
            }
        }
        return matrix[0][vertexNum - 1] + grid[0][0];
    }
};


int main() {
    vector<vector<int> > grid;
    vector<int> row1;
    row1.push_back(5);
    //row1.push_back(6);
    //vector<int> row2;
    //row2.push_back(17);
    //row2.push_back(10);
    grid.push_back(row1);
    //grid.push_back(row2);
    Solution s;
    int min = s.minPathSum(grid);
    cout << "The minimum path sum is: " << min << endl;
    return 0;
}
