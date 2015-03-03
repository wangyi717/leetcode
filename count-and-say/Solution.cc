/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; ++i) {
            string newStr;
            for (int j = 0; j < str.size(); ++j) {
                int count = 1;
                while (str[j] == str[j + 1]) {
                    ++j; ++count;
                }
                newStr += '0' + count;
                newStr += str[j];
            }
            str = newStr;
        }
        return str;
    }
};

int main() {
    Solution solution;
    for (int i = 1; i <= 10; ++i) {
        string ans = solution.countAndSay(i);
        cout << ans << endl;
    }
    return 0;
}
