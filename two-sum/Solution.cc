/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        unordered_map<int, int> hash;
        for (int i = 0; i < numbers.size(); ++i) {
            int sub = target - numbers[i];
            if (hash.find(sub) != hash.end()) {
				result.push_back(hash[sub] + 1);
                result.push_back(i + 1);
                return result;
            }
            hash[numbers[i]] = i;
        }
        return result;
    }
};
