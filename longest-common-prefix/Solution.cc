/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j].size() < i) return strs[0].substr(0, i + 1);
                if (strs[j][i] != c) return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

int main() {
    vector<string> strs;
    strs.push_back("abc");
    strs.push_back("ab");
    Solution solution;
    string ans = solution.longestCommonPrefix(strs);
    cout << ans << endl;
    return 0;
}
