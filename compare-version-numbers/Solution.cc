/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    string nextNumber(string str) {
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '.')
                return str.substr(i + 1);
        }
        return "0";
    }
public:
    int compareVersion(string version1, string version2) {
        while (version1 != version2) {
            int gap = stoi(version1) - stoi(version2);
            if (gap != 0) {
                return gap > 0 ? 1 : -1;
            }
            version1 = nextNumber(version1);
            version2 = nextNumber(version2);
        }
        return 0;
    }
};

int main() {
    Solution solution;
    cout << solution.compareVersion("1.1", "1.00000000010") << endl;
    cout << solution.compareVersion("1", "0") << endl;
    return 0;
}
