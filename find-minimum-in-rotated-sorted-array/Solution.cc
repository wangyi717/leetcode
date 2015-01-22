/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0, high = num.size() - 1, mid;
        while (high > low) {
            mid = (high + low) / 2;
            if (num[mid] > num[high]) low = mid + 1;
            else high = mid;
        }
        return num[low];
    }
};
