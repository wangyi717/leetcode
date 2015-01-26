/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != elem) {
                A[j++] = A[i];
            }
        }
        return j;
    }
};

int main() {
    int A[] = {8, 7, 2, 5, 3, 6, 2, 4, 1};
    Solution solution;
    cout << "New length: " << solution.removeElement(A, 9, 2) << endl;
    return 0;
}
