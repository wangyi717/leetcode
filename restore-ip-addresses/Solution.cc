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
    void dfs(vector<string>& ans, string s, string ip, int level) {
        if (s.size() > 3 * (4 - level)) return;
        if (level == 3) {
            if (s.size() > 1 && s[0] == '0') return;
            int n = stoi(s);
            if (n > 255) return;
            ip = ip + to_string(n);
            ans.push_back(ip);
        } else {
            int n;
            if (s.size() > 1) {
                n = s[0] - '0';
                string ip1 = ip + to_string(n) + ".";
                dfs(ans, s.substr(1, s.size() - 1), ip1, level + 1);
            }
            if (s.size() > 2 && s[0] != '0') {
                n = (s[0] - '0') * 10 + (s[1] - '0');
                string ip2 = ip + to_string(n) + ".";
                dfs(ans, s.substr(2, s.size() - 2), ip2, level + 1);
            }
            if (s.size() > 3 && s[0] != '0') {
                n = (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
                if (n <= 255) {
                    string ip3 = ip + to_string(n) + ".";
                    dfs(ans, s.substr(3, s.size() - 3), ip3, level + 1);
                }
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(ans, s, "", 0);
        return ans;
    }
};

int main() {
    Solution solution;
    //vector<string> vec = solution.restoreIpAddresses("25525511135");
    vector<string> vec = solution.restoreIpAddresses("010010");
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
    return 0;
}
