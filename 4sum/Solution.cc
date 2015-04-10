/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.size() < 4) return res;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 3; ++i) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            for (int j = num.size() - 1; j >= i + 3; --j) {
                if (j < num.size() - 1 && num[j] == num[j + 1]) continue;
                int ii = i + 1, jj = j - 1;
                while (ii < jj) {
                    if ( ii > i + 1 && num[ii] == num[ii - 1]) {
                        ++ii;
                        continue;
                    }
                    if (jj < j - 1 && num[jj] == num[jj + 1]) {
                        --jj;
                        continue;
                    }
                    int sum = num[i] + num[ii] + num[jj] + num[j];
                    if (sum == target) {
                        vector<int> vec;
                        vec.push_back(num[i]);
                        vec.push_back(num[ii]);
                        vec.push_back(num[jj]);
                        vec.push_back(num[j]);
                        res.push_back(vec);
                        ++ii;
                        --jj;
                    } else if (sum > target) {
                        --jj;
                    } else {
                        ++ii;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(-1);
    vec.push_back(0);
    vec.push_back(-2);
    vec.push_back(2);
    Solution solution;
    vector<vector<int> > res = solution.fourSum(vec, 0);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
