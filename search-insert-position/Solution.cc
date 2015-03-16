/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] == target) return mid;
            if (low == high) {
                if (A[mid] < target) return mid + 1;
                else return mid;
            }
            if (A[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
};
