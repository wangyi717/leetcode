/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        vector<int> lastRow;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                row[j] = lastRow[j - 1] + lastRow[j];
            }
            ans.push_back(row);
            lastRow = row;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 10;
    vector<vector<int> > vec = solution.generate(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
