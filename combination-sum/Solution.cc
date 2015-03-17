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
    void search(vector<vector<int> >& ans, vector<int>& candidates, int begin, int end, int target, vector<int> vec) {
        if (begin >= end) return;
        if (candidates[begin] > target) return;
        if (candidates[begin] == target) {
            vec.push_back(candidates[begin]);
            ans.push_back(vec);
            return;
        }
        for (int i = begin; i < end; ++i) {
            int sum = 0;
            int count = 0;
            while (sum < target && candidates[i] <= target) {
                sum += candidates[i];
                ++count;
                vec.push_back(candidates[i]);
                if (sum == target) {
                    ans.push_back(vec);
                } else if (sum < target) {
                    search(ans, candidates, i + 1, end, target - sum, vec);
                }
            }
            while (count--) {
                vec.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ans;
        if (candidates.size() == 0) return ans;
        sort(candidates.begin(), candidates.end());
        int repeat = 0, len = candidates.size();
        for (int i = 1; i < candidates.size(); ++i) {
            if (candidates[i] == candidates[i - 1]) {
                ++repeat;
                --len;
            } else {
                candidates[i - repeat] = candidates[i];
            }
        }
        vector<int> vec;
        search(ans, candidates, 0, len, target, vec);
        return ans;
    }

};

int main() {
    Solution solution;
    vector<int> cans;
    int target = 8;
    cans.push_back(2);
    cans.push_back(2);
    cans.push_back(6);
    cans.push_back(7);
    vector<vector<int> > ans = solution.combinationSum(cans, target);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
