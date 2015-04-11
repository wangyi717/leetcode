/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int n = S.size(), m = T.size();
        if (n < m) return 0;
        vector<vector<int> > f(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; ++i) f[0][i] = 1;
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                if (T[i - 1] == S[j - 1]) {
                    f[i][j] = f[i][j - 1] + f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i][j - 1];
                }
            }
        }
        return f[m][n];
    }
};
