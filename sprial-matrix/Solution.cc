/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sprialOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        int top = 0, right = n - 1, bottom = m - 1, left = 0;
        while (top < bottom && left < right) {
            for (int i = left; i < right; ++i) {
                ans.push_back(matrix[top][i]);
            }
            for (int i = top; i < bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            for (int i = right; i > left; --i) {
                ans.push_back(matrix[bottom][i]);
            }
            for (int i = bottom; i > top; --i) {
                ans.push_back(matrix[i][left]);
            }
            ++top;
            --right;
            --bottom;
            ++left;
        }
        if (top == bottom && left == right) {
            ans.push_back(matrix[top][left]);
            return ans;
        }
        if (top == bottom) {
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }
        }
        if (left == right) {
            for (int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][left]);
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int> > m1(1, vector<int>(1));
    m1[0][0] = 1;
    vector<vector<int> > m2(1, vector<int>(2));
    m2[0][0] = 1;
    m2[0][1] = 2;
    vector<vector<int> > m3(2, vector<int>(1));
    m3[0][0] = 1;
    m3[1][0] = 2;
    vector<vector<int> > m4(3, vector<int>(3));
    int k = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m4[i][j] = ++k;
        }
    }
    Solution solution;
    vector<int> ans = solution.sprialOrder(m4);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
