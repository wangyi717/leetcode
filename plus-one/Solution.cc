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
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ans;
        int n = digits.size();
        if (n == 0) return ans;
        int carry = 1;
        for (int i = n - 1; i >= 0; --i) {
            int num = digits[i] + carry;
            if (num == 10) {
                num = 0;
                carry = 1;
            } else {
                carry = 0;
            }
            ans.push_back(num);
        }
        if (carry == 1) {
            ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());
    }
};

int main() {
    Solution solution;
    vector<int> digits;
    digits.push_back(9);
    digits.push_back(9);
    digits.push_back(9);
    vector<int> ans = solution.plusOne(digits);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
