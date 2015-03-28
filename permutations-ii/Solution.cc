/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void search(vector<vector<int> >& res, vector<int> num, int begin) {
        if (begin == num.size() - 1) {
            res.push_back(num);
            return;
        }
        for (int i = begin; i < num.size(); ++i) {
            if (begin != i && num[begin] == num[i])
                continue;
            swap(num[begin], num[i]);
            search(res, num, begin + 1);
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        if (num.size() == 0) return res;
        sort(num.begin(), num.end());
        search(res, num, 0);
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> num;
    num.push_back(-1);
    num.push_back(-1);
    num.push_back(3);
    num.push_back(-1);
    vector<vector<int> > res = solution.permute(num);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
