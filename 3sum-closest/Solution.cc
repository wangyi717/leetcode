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
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() <= 3) {
            return accumulate(num.begin(), num.end(), 0);
        }
        sort(num.begin(), num.end());
        int ans = num[0] + num[1] + num[2];
        for (int i = 0; i < num.size() - 2; ++i) {
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (abs(target - ans) > abs(target - sum)) {
                    ans = sum;
                    if (ans == target) return ans;
                }
                if (sum > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return ans;
    }
};
