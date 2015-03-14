/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return n;
        vector<int> f(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            f[i] = 0;
            for (int j = 0; j < i; ++j) {
                f[i] += f[j] * f[i - j - 1];
            }
        }
        return f[n];
    }
};

int main() {
    int n = 3;
    Solution solution;
    cout << "N=" << n << " TN=" << solution.numTrees(n) << endl;
    return 0;
}
