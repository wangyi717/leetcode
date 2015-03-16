/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int f = 1, g = 1, t;
        for (int i = 2; i <= n; ++i) {
            t = f;
            f = f + g;
            g = t;
        }
        return f;
    }
};

int main() {
    Solution solution;
    cout << solution.climbStairs(3) << endl;
    return 0;
}
