#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int top = 0, base = 0;
    	unsigned int i = 0, j = s.size() - 1;
    	string stack[1000] = { };
    	while (s[i] == ' ') {
    		i++;
    	}
    	while (s[j] == ' ') {
    		j--;
    	}
    	s = s.substr(i, j - i + 1);
    	for (i = 0; i <= s.size(); i++) {
    		if (isspace(s[i]) || i == s.size()) {
    			stack[top++] = s.substr(base, i - base);
    			while (s[i + 1] == ' ') {
    				i++;
    			}
    			base = i + 1;
    		}
    	}
    	s = "";
    	while (top > 0) {
    		--top;
    		if (top == 0) {
    			s += stack[top];
    		} else {
    			s += stack[top] + " ";
    		}
    	}
    }
};

int main() {
    string s = "   the    sky is   blue     ";
    Solution solution;
    solution.reverseWords(s);
    cout << s << endl;
    return 0;
}
