/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        string t1(s1);
        string t2(s2);
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if (t1 != t2) return false;
        for (int i = 1; i < s1.size(); ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                    isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i, i)) &&
                    isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i))) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    bool flag = solution.isScramble("abcdefghijklmnopq", "efghijklmnopqcadb");
    //bool flag = solution.isScramble("great", "rgtae");
    if (flag) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    return 0;
}
