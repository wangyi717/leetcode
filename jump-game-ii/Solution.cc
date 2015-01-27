/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int count = 0, theMax = 0;
        for (int i = 0, nextMax = 0; i <= theMax && i < n - 1; ++i) {
            nextMax = max(nextMax, i + A[i]);
            if (i == theMax) {
                theMax = nextMax;
                ++count;
            }
        }
        return theMax >= n - 1 ? count : -1;
    }
};

int main() {
    int a[] = {1, 2, 3};
    Solution solution;
    cout << "Steps: " << solution.jump(a, 3) << endl;
    return 0;
}
