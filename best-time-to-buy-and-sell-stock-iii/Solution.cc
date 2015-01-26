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
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> before(n, 0);
        vector<int> after(n, 0);
        int maxProfit = 0;
        int minPrice = prices[0], maxPrice = prices[n - 1];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            maxPrice = max(maxPrice, prices[n - 1 - i]);
            before[i] = max(before[i - 1], prices[i] - minPrice);
            after[n - i - 1] = max(after[n - i], maxPrice - prices[n - 1 - i]);
        }
        for (int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, before[i] + after[i]);
        }
        return maxProfit;
    }
};

int main() {
    int a[] = {5, 8, 3, 2, 4, 9, 9, 6, 2};
    vector<int> vec;
    for (int i = 0; i < 9; ++i) {
        vec.push_back(a[i]);
    }
    Solution solution;
    cout << "Max profit: " << solution.maxProfit(vec) << endl;
    return 0;
}
