/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            if (set.find(nums[i]) == set.end()) {
                set.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
