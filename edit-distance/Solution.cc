/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int> > f(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i) f[i][0] = i;
        for (int j = 0; j <= n; ++j) f[0][j] = j;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] = 1 + min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]);
            }
        }
        return f[m][n];
    }
};

int main() {
    Solution solution;
    cout << "Min: " << solution.minDistance("sea", "ate") << endl;
    return 0;
}
