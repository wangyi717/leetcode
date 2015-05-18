/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        unordered_set<int> set;
        while (set.find(n) == set.end()) {
            set.insert(n);
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (sum == 1) return true;
            n = sum;
        }
        return false;
    }
};
