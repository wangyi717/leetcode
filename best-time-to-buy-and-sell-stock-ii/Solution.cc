/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                profit += prices[i + 1] - prices[i];
            }
        }
        return profit;
    }
};

int main() {
    int a[] = {5, 9, 3, 2, 4, 9, 9, 6, 2};
    vector<int> vec;
    for (int i = 0; i < 9; ++i) {
        vec.push_back(a[i]);
    }
    Solution solution;
    cout << "Max profit: " << solution.maxProfit(vec) << endl;
    return 0;
}
