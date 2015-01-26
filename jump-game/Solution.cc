/**
 * Solution.cc
 * @author 王毅
 */

#include <iostream>
#include <math>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n <= 1) return true;
        if (A[0] == 0) return false;
        for (int i = 1; i < n; ++i) {
            int maxJump = max(maxJump - 1, A[i]);
            if (maxJump == 0) return false;
        }
        return true;
    }
};
