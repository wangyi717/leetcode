/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int low = 0, high = num.size() - 1, mid = low;
        while (high > low) {
            mid = (low + high) / 2;
            if (num[low] == num[mid] && num[mid] == num[low]) {
                int minNum = num[0];
                for (int i = 1; i < num.size(); ++i) {
                    if (num[i] < minNum) minNum = num[i];
                }
                return minNum;
            }
            if (num[mid] > num[low]) low = mid;
            else high = mid;
        }
        return num[mid];
    }
};

int main() {
    Solution solution;
    vector<int> num;
    num.push_back(6);
    num.push_back(5);
    num.push_back(6);
    num.push_back(6);
    num.push_back(6);
    num.push_back(6);
    num.push_back(6);
    int ans = solution.findMin(num);
    cout << "Find min: " << ans << endl;
    return 0;
}
