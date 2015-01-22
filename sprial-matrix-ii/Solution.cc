/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n));
        if (n == 0) return ans;
        int top = 0, right = n - 1, bottom = n - 1, left = 0;
        int k = 0;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i) {
                ans[top][i] = ++k;
            }
            ++top;
            for (int i = top; i <= bottom; ++i) {
                ans[i][right] = ++k;
            }
            --right;
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    ans[bottom][i] = ++k;
                }
            }
            --bottom;
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    ans[i][left] = ++k;
                }
            }
            ++left;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<vector<int> > ans = solution.generateMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
