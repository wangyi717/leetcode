/**
 * Solution2.cc
 * @author 王毅 <wangyi717@gmail.com>
 * O(log(n))时间复杂度算法
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n <= 1) return 0;
        int m = (n - 1) / 2;
        while (m > 0 && m < n - 1) {
            if (num[m] > num[m - 1] && num[m] > num[m + 1]) {
                return m;
            } else if (num[m] < num[m - 1]) {
                n = m;
                m = m  / 2;
            } else {
                m = (m + n) / 2;
            }
        }
        if (n == 2) return (num[0] > num[1]) ? 0 : 1;
        return m;
    }
};

int main() {
    Solution solution;
    int A[] = {5, 4, 3, 2, 1};
    vector<int> num;
    for (int i = 0; i < 5; ++i)
        num.push_back(A[i]);
    int peak = solution.findPeakElement(num);
    cout << "PEAK: " << peak << endl;
    return 0;
}
