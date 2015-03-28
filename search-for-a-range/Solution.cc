/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> nofound(2, -1);
        vector<int> res;
        if (n == 0) return nofound;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == target) {
                int begin = mid, end = mid;
                while (begin > 0 && A[begin - 1] == A[mid]) {
                    --begin;
                }
                while (end < n - 1 && A[end + 1] == A[mid]) {
                    ++end;
                }
                res.push_back(begin);
                res.push_back(end);
                return res;
            }
            if (A[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return nofound;
    }
};
