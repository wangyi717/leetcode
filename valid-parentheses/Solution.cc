/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) return true;
        if (s.size() % 2 == 1) return false;
        stack<char> st;
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '{' || c == '[' || c == '(') {
                st.push(c);
                ++cnt;
                if (cnt > s.size() / 2) return false;
            } else {
                if (c == '}') {
                    if (st.empty()) return false;
                    if (st.top() != '{') return false;
                    else st.pop();
                }
                if (c == ']') {
                    if (st.empty()) return false;
                    if (st.top() != '[') return false;
                    else st.pop();
                }
                if (c == ')') {
                    if (st.empty()) return false;
                    if (st.top() != '(') return false;
                    else st.pop();
                }
            }
        }
        return true;
    }
};

int main() {
    string s1 = "{[()]}";
    string s2 = "{}[]()";
    string s3 = "{[]}()";
    string s4 = "{{}}}";
    string s5 = "{[()}]";
    string s6 = "[[";
    Solution solution;
    cout << "S1: " << solution.isValid(s1) << endl;
    cout << "S2: " << solution.isValid(s2) << endl;
    cout << "S3: " << solution.isValid(s3) << endl;
    cout << "S4: " << solution.isValid(s4) << endl;
    cout << "S5: " << solution.isValid(s5) << endl;
    cout << "S6: " << solution.isValid(s6) << endl;
    return 0;
}
