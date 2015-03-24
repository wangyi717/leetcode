/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool check(vector<int>& vec) {
        int n = vec.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if(i - j == vec[i] - vec[j] || j - i == vec[i] - vec[j])
                    return false;
            }
        }
        return true;
    }
    void search(vector<vector<string> >& ans, vector<int>& vec, int begin, int n) {
        if (begin == n - 1) {
            if (check(vec)) {
                cout << "yes" << endl;
                vector<string> sv;
                for (int i = 0; i < n; ++i) {
                    string str(n, '.');
                    str[vec[i]] = 'Q';
                    sv.push_back(str);
                }
                ans.push_back(sv);
            }
            return;
        }
        for (int i = begin; i < n; ++i) {
            swap(vec[i], vec[begin]);
            search(ans, vec, begin + 1, n);
            swap(vec[i], vec[begin]);
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            vec.push_back(i);
        }
        search(ans, vec, 0, n);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<string> > ans = solution.solveNQueens(8);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
