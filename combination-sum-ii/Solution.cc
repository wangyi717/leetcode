/**
 * Soltuion.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void search(vector<vector<int> >& res, vector<int> vec, vector<int>& num, int begin, int target) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(vec);
            return;
        }
        for (int i = begin; i < num.size(); ++i) {
            while (i > begin && num[i] == num[i - 1])
                ++i;
            if (num[i] > target)
                return;
            vec.push_back(num[i]);
            search(res, vec, num, i + 1, target - num[i]);
            vec.pop_back();
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.size() == 0) return res;
		sort(num.begin(), num.end());
        vector<int> vec;
        search(res, vec, num, 0, target);
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(5);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);
    num.push_back(10);
    vector<vector<int> > res = solution.combinationSum2(num, 8);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
