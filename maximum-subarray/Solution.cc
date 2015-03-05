/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 * 动态规划求解
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int last = A[0], maximum = A[0], cur;
        for (int i = 1; i < n; ++i) {
            cur = max(A[i], A[i] + last);
            last = cur;
            maximum = max(cur, maximum);
        }
        return maximum;
    }
};

int main() {
    Solution solution;
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max: " << solution.maxSubArray(A, 9) << endl;
    return 0;
}
