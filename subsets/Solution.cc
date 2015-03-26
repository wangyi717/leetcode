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
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> empty;
        res.push_back(empty);
        sort(S.begin(), S.end());
        for (int i = S.size() - 1; i >= 0; --i) {
            for (int j = res.size() - 1; j >= 0; --j) {
                vector<int> vec;
                vec.push_back(S[i]);
                for (int k = 0; k < res[j].size(); ++k) {
                    vec.push_back(res[j][k]);
                }
                res.push_back(vec);
            }
        }
        return res;
    }
};

int main() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    Solution solution;
    vector<vector<int> > res = solution.subsets(vec);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
