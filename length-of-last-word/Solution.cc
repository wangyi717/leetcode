/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        if (len == 0) return 0;
        int i, j;
        for (i = len - 1; s[i] == ' ' && i >= 0; --i);
        for (j = i; s[j] != ' ' && j >= 0; --j);
        return i - j;
    }
};

int main() {
    const char* s = "  ";
    Solution solution;
    cout << "Length: " << solution.lengthOfLastWord(s) << endl;
    return 0;
}
