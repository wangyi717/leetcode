/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int count = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i - 1] == A[i]) {
                ++count;
            } else {
                A[i - count] = A[i];
            }
        }
        return n - count;
    }
};
