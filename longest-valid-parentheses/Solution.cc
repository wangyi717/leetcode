/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int count = 0, last = -1;
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) last = i;
                else {
                    st.pop();
                    if (st.empty()) {
                        count = max(count, i - last);
                    } else {
                        count = max(count, i - st.top()); 
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    cout << "Result: " << solution.longestValidParentheses("(()") << endl;
    cout << "Result: " << solution.longestValidParentheses(")()())") << endl;
    cout << "Result: " << solution.longestValidParentheses(")(())()") << endl;
    cout << "Result: " << solution.longestValidParentheses("()(()") << endl;
    return 0;
}
