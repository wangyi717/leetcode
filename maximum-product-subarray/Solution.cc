/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 1) return A[0];
        int r = A[0], imax = A[0], imin = A[0];
        for (int i = 1; i < n; i++) {
            if (A[i] < 0) swap(imax, imin);
            imax = max(A[i], A[i] * imax);
            imin = min(A[i], A[i] * imin);
            r = max(imax, r);
        }
        return r;
    }
};

int main() {
    Solution solution;
    int A[5] = {2, 3, -2, 4, 1};
    int r = solution.maxProduct(A, 5);
    cout << "Max product is: " << r << endl;
    return 0;
}
