/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        if (n <= 2) return;
        int l = 0, r = n - 1;
        for (int i = 0; i < n; ++i) {
            while (A[i] == 2 && i < r) swap(A[i], A[r--]);
            while (A[i] == 0 && i > l) swap(A[i], A[l++]);
        }
    }
};

int main() {
    int A[] = {1, 0, 0, 2, 1, 2, 2, 0, 1};
    Solution solution;
    solution.sortColors(A, 9);
    for (int i = 0; i < 9; ++i) {
        cout << A[i] << "  ";
    }
    cout << endl;
    return 0;
}
