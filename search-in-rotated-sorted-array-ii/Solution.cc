/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (A[m] == target) return true;
            if (A[l] < A[m]) {
                if (A[l] <= target && target < A[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else if (A[l] > A[m]) {
                if (A[m] < target && target <= A[r])
                    l = m + 1;
                else
                    r = m - 1;
            } else ++l;
        }
        return false;
    }
};

int main() {
    int A[] = {1, 1, 3, 1};
    Solution solution;
    bool flag = solution.search(A, 4, 4);
    if (flag)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    return 0;
}
