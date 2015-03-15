/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string dict[4][9] = {
            {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"M", "MM", "MMM", "", "", "", "", "", ""}
        };
        int digit = 0;
        string ans;
        while (num) {
            int n = num % 10;
            num /= 10;
            if (n != 0) {
                ans = dict[digit][n - 1] + ans;
            }
            ++digit;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << "1899: " << solution.intToRoman(1899) << endl;
    cout << "1976: " << solution.intToRoman(1976) << endl;
    cout << "256: " << solution.intToRoman(256) << endl;
    cout << "78: " << solution.intToRoman(78) << endl;
    cout << "3999: " << solution.intToRoman(3999) << endl;
    return 0;
}
