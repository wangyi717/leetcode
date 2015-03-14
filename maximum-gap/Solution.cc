/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        int gap, minNum = num[0], maxNum = num[0];
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] < minNum) minNum = num[i];
            if (num[i] > maxNum) maxNum = num[i];
        }
        gap = ceil((double)(maxNum - minNum) / (num.size() - 1));
        vector<int> minBucket(num.size() - 1, INT_MAX);
        vector<int> maxBucket(num.size() - 1, INT_MIN);
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] == minNum || num[i] == maxNum) continue;
            int index = (num[i] - minNum) / gap;
            minBucket[index] = min(num[i], minBucket[index]);
            maxBucket[index] = max(num[i], maxBucket[index]);
        }
        int maxGap = INT_MIN;
        int last = minNum;
        for (int i = 0; i < num.size() - 1; ++i) {
            if (minBucket[i] == INT_MAX && maxBucket[i] == INT_MIN) continue;
            maxGap = max(maxGap, minBucket[i] - last);
            last = maxBucket[i];
        }
        maxGap = max(maxGap, maxNum - last);
        return maxGap;
    }
};

int main() {
    vector<int> num;
    for (int i = 0; i < 10000000; ++i) {
        num.push_back(rand());
    }
    Solution solution;
    cout << "Max gap: " << solution.maximumGap(num) << endl;
    return 0;
}
