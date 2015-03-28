/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        double result = 1;
        double f = x;
        while (n > 0) {
            if (n & 1 == 1) {
                result *= f;
            }
            f = f * f;
            n = n >> 1;
        }
        return result;
    }
};
