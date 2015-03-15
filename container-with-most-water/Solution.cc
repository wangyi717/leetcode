/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int r = height.size() - 1;
        int l = 0;
        int m = INT_MIN;
        while (l < r) {
            m = max(min(height[l], height[r]) * (r - l), m);
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return m;
    }
};
