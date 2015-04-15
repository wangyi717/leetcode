/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool> > table(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        for (int i = 0; i <= s1.size(); ++i) {
            for (int j = 0; j <= s2.size(); ++j) {
                if(i == 0 && j == 0)
                    table[i][j] = true;
                else if(i == 0)
                    table[i][j] = (table[i][j-1] && s2[j-1] == s3[i+j-1]);
                else if(j == 0)
                    table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1]);
                else
                    table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1]) || (table[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return table[s1.size()][s2.size()];
    }
};

int main() {
    Solution solution;
    bool flag = solution.isInterleave("acaccabaabcbbacaacaaaacabbac", "accbccbccccabaaabcacabbaba", "acaccabccbcccaccababaaaababcaccbcbacababacbaaaaacabbac");
    if (flag) {
        cout << "TRUE!" << endl;
    } else {
        cout << "FALSE!" << endl;
    }
    return 0;
}
