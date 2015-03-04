/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res > INT_MAX || res < INT_MIN) return 0;
        else return res;
    }
};
