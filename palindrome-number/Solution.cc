/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int t = x, digits = 1, sub = 1;
        while (t >= 10) {
            ++digits;
            t /= 10;
            sub *= 10;
        }
        t = x;
        for (int i = 0; i < digits / 2; ++i) {
            if (t % 10 != x / sub) return false;
            t /= 10;
            x %= sub;
            sub /= 10;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome(12321) << endl;
    cout << solution.isPalindrome(12345) << endl;
    cout << solution.isPalindrome(1) << endl;
    cout << solution.isPalindrome(-1) << endl;
    cout << solution.isPalindrome(1111) << endl;
    return 0;
}
