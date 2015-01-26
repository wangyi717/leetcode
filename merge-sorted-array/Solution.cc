/**
 * Solutoin.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
        while (j >= 0) {
            A[k--] = B[j--];
        }
    }
};

int main() {
    int A[] = {1, 3, 8, 12};
    int B[] = {2, 5, 9};
    Solution solution;
    solution.merge(A, 4, B, 3);
    for (int i = 0; i < 7; ++i) {
        cout << A[i] << endl;
    }
    return 0;
}
