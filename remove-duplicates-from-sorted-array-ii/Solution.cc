/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int left = 2;
        for (int i = 2; i < n; ++i) {
            if (A[i] != A[left - 2])
                A[left++] = A[i];
        }
        return left;
    }
};

int main() {
    int A[8] = {1, 1, 1, 2, 2, 2, 3, 3};
    int B[8] = {1, 1, 1, 2, 3, 3, 3, 4};
    Solution solution;
    int a = solution.removeDuplicates(A, 8);
    int b = solution.removeDuplicates(B, 8);
    cout << "A: ";
    for (int i = 0; i < a; ++i) {
        cout << A[i] << "  ";
    }
    cout << endl << "B: ";
    for (int i = 0; i < b; ++i) {
        cout << B[i] << "  ";
    }
    cout << endl;
    return 0;
}
