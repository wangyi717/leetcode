/**
 * 计算n个数从小到大排列中第k个排列
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int* fact = new int[n];
        string s(n, '0');
        string ans(n, '0');
        fact[0] = 1;
        s[0] += 1;
        for (int i = 1; i < n; ++i) {
            fact[i] = i * fact[i - 1];
            s[i] += i + 1;
        }
        --k;
        for (int i = n; i > 0; --i) {
            int ind = k / fact[i - 1];
            k = k % fact[i - 1];
            ans[n - i] = s[ind];
            for (int j = ind; j < n - 1; ++j) {
                s[j] = s[j + 1];
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << "ANSWER IS: " << solution.getPermutation(3, 4) << endl;
    return 0;
}
