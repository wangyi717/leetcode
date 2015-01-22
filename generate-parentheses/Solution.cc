/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> ans;
    int half;
    void search(string s, int lr, int rr) {
        if (lr > half || rr > half || rr > lr) return;
        if (lr == half && rr == half) {
            ans.push_back(s);
            return;
        }
        search(s + "(", lr + 1, rr);
        search(s + ")", lr, rr + 1);
    }
public:
    vector<string> generateParenthesis(int n) { 
        half = n;
        search("(", 1, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> vec = solution.generateParenthesis(3);
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
    return 0;
}
