/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n <= 1) return 0;
        for (int i = 0; i < n; ++i) {
            bool l = false, r = false;
            if (i != 0) {
                if (num[i] > num[i - 1])
                    l = true;
            } else {
                l = true;
            }
            if (i != n - 1) {
                if (num[i] > num[i + 1])
                    r = true;
            } else {
                r = true;
            }
            if (l && r) return i;
        }
    }
};

int main() {
    Solution solution;
    int A[] = {1, 2, 3, 1};
    vector<int> num;
    for (int i = 0; i < 4; ++i)
        num.push_back(A[i]);
    int peak = solution.findPeakElement(num);
    cout << "PEAK: " << peak << endl;
    return 0;
}
