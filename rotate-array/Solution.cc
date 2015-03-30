/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        reverse(nums, nums + n);
        reverse(nums, nums + k % n);
        reverse(nums + k % n, nums + n);
    }
};
