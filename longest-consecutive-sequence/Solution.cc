/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() < 2) return num.size();
        int res = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < num.size(); ++i) {
            if (map.find(num[i]) == map.end()) {
                int left = (map.find(num[i] - 1) != map.end()) ? map[num[i] - 1] : 0;
                int right = (map.find(num[i] + 1) != map.end()) ? map[num[i] + 1] : 0;
                int sum = left + right + 1;
                map[num[i]] = sum;
                res = max(res, sum);
                map[num[i] - left] = sum;
                map[num[i] + right] = sum;
            }
        }
        return res;
    }
};
