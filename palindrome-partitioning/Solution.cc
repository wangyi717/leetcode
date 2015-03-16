/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }
    void doPartition(vector<vector<string> >& ans, vector<string> vec, string s) {
        if (s.size() == 0) {
            ans.push_back(vec);
            return;
        }
        for (int i = 1; i <= s.size(); ++i) {
            string before = s.substr(0, i);
            bool flag = isPalindrome(before);
            if (flag) {
                vec.push_back(before);
            } else continue;
            doPartition(ans, vec, s.substr(i, s.size() - i));
            if (flag) vec.pop_back();
        }
    }
public:
    vector<vector<string> > partition(string s) {
        int n = s.size();
        vector<vector<string> > ans;
        if (n == 0) return ans;
        vector<string> vec;
        doPartition(ans, vec, s);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<string> > ans = solution.partition("efe");
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
