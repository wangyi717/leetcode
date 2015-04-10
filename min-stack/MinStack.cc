/**
 * MinStack.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> ms;
public:
    void push(int x) {
        if (ms.empty() || x < ms.top()) {
            ms.push(x);
        } else {
            ms.push(ms.top());
        }
        st.push(x);
    }

    void pop() {
        if (!st.empty() && !ms.empty()) {
            st.pop();
            ms.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return ms.top();
    }
};
