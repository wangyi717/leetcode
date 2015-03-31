/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int> &num) {
        if (num.size() == 0) return 0;
        if (num.size() == 1) return num[0];
        if (num.size() == 2) return max(num[0], num[1]);
        int g = num[0], f = max(num[0], num[1]);
        for (int i = 2; i < num.size(); ++i) {
            int t = f;
            f = max(f, g + num[i]);
            g = t;
        }
        return f;
    }
};

int main() {
    vector<int> num;
    num.push_back(2);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    Solution solution;
    cout << solution.rob(num) << endl;
    return 0;
}
