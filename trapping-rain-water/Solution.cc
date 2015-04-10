/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 1) return 0;
        int leftMax = 0, rightMax = 0, left = 0, right = n - 1, res = 0;
        while (left < right) {
            leftMax = max(leftMax, A[left]);
            rightMax = max(rightMax, A[right]);
            if (leftMax < rightMax) {
                res += leftMax - A[left];
                ++left;
            } else {
                res += rightMax - A[right];
                --right;
            }
        }
        return res;
    }
};

int main() {
    int A[] = {0, 2, 0};
    Solution solution;
    cout << "Result: " << solution.trap(A, 3) << endl;
    return 0;
}
