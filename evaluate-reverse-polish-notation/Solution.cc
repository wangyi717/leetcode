/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size() == 0) return 0;
        if (tokens.size() == 1) return stoi(tokens[0]);
        stack<int> st;
        int result = 0;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                if (tokens[i] == "+") {
                    result = left + right;
                } else if (tokens[i] == "-") {
                    result = left - right;
                } else if (tokens[i] == "*") {
                    result = left * right;
                } else if (tokens[i] == "/") {
                    result = left / right;
                }
                st.push(result);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> vec;
    vec.push_back("10");
    vec.push_back("6");
    vec.push_back("9");
    vec.push_back("3");
    vec.push_back("+");
    vec.push_back("-11");
    vec.push_back("*");
    vec.push_back("/");
    vec.push_back("*");
    vec.push_back("17");
    vec.push_back("+");
    vec.push_back("5");
    vec.push_back("+");
    cout << "result = " << solution.evalRPN(vec) << endl;
    return 0;
}
