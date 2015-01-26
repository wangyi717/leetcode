/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        int f = 1, g = 1;
        for (int i = 1; i < s.size(); ++i) {
			int t = f;
            if (s[i] == '0' && s[i - 1] == '0') continue;
            if (s[i] == '0') f = 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                f = f + g; 
            }
            g = t;
        }
        return f;
    }
};

int main() {
    Solution solution;
    cout << "ANS: " << solution.numDecodings("12") << endl;
    cout << "ANS: " << solution.numDecodings("362121") << endl;
    cout << "ANS: " << solution.numDecodings("10") << endl;
    cout << "ANS: " << solution.numDecodings("101") << endl;
    cout << "ANS: " << solution.numDecodings("110") << endl;
    return 0;
}
