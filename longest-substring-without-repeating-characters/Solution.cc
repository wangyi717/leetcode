/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int max = 0;
        int fast = 0, slow = 0;
        while (fast < s.size() && slow < s.size()) {
            if (set.find(s[fast]) == set.end()) {
                set.insert(s[fast]);
            } else {
                while (s[slow] != s[fast]) {
                    set.erase(s[slow]);
                    ++slow;
                }
                ++slow;
            }
            if (set.size() > max)
                max = set.size();
            ++fast;
        }
        return max;
    }
};

int main() {
    Solution solution;
    string s = "c";
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
