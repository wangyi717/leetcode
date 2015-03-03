/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        vector<int> lastRow(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = 1; j < i; ++j) {
                row[j] = lastRow[j - 1] + lastRow[j];
            }
            lastRow = row;
        }
        return row;
    }
};

int main() {
    Solution solution;
    int n = 5;
    vector<int> row = solution.getRow(n);
    for (int i = 0; i < row.size(); ++i) {
        cout << row[i] << "\t";
    }
    cout << endl;
    return 0;
}
