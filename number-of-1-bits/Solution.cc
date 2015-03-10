/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com
 */

#include <iostream>
typedef unsigned int uint32_t;
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= n - 1;
            ++count;
        }
        return count;
    }
};
