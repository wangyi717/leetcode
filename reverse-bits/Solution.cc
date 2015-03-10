/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
typedef unsigned int uint32_t;
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            int bit = 1 & n;
            result <<= 1;
            result += bit;
            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution solution;
    uint32_t ans = solution.reverseBits(2147483648);
    cout << ans << endl;
    return 0;
}
