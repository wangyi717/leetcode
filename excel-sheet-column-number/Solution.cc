/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            int single = s[s.size() - i - 1] - 'A' + 1;
            result += single * pow(26, i); 
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.titleToNumber("A") << endl;
    cout << solution.titleToNumber("B") << endl;
    cout << solution.titleToNumber("C") << endl;
    cout << solution.titleToNumber("D") << endl;
    cout << solution.titleToNumber("E") << endl;
    cout << solution.titleToNumber("Y") << endl;
    cout << solution.titleToNumber("Z") << endl;
    cout << solution.titleToNumber("AA") << endl;
    cout << solution.titleToNumber("AB") << endl;
    cout << solution.titleToNumber("BA") << endl;
    return 0;
}
