/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: 
    string convert(string s, int nRows) {
		if (nRows == 1) return s;
        int n = s.size();
        vector<string> m(nRows);
        int row = 0, step = 1;
        for (int i = 0; i < s.size(); ++i) {
            m[row].push_back(s[i]);
            if (row == nRows - 1) step = -1;
            if (row == 0) step = 1;
            row += step;
        }
        string ans;
        row = 0, step = 1;
        for (int i = 0; i < m.size(); ++i) {
            ans.append(m[i]);
        }
        return ans;
    }
};

int main() {
    string s = "PAYPALISHIRING";
    Solution solution;
    cout << solution.convert(s, 3) << endl;
    return 0;
}
