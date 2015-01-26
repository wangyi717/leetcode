/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int t;
        for (int i = 0; i <= (n - 1) / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                t = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = t;
            }
        }
    }
};

int main() {
    vector<vector<int> > m;
    int n, k = 0;
    cout << "Input n: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> arr;
        for (int j = 0; j < n; ++j) {
            arr.push_back(++k);
        }
        m.push_back(arr);
    }
    Solution solution;
    solution.rotate(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
