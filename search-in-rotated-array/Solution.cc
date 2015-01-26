/**
 * Solution.cc
 * @author 王毅
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        if (n <= 0) return -1;
        int low = 0, high = n - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (mid == target) return;
            if (A[low] <= A[mid]) {
                if (A[low] <= target && target <= A[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (A[mid] <= target && target <= A[high]) {
                    start = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
