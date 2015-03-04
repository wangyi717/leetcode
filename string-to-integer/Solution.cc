/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int atoi(string str) {
        long res = 0;
        int symbol = 1;
        int iter = 0;
        while (str[iter] == ' ') ++iter;
        if (str[iter] == '-' || str[iter] == '+') {
            if (str[iter] == '-') symbol = -1;
            ++iter;
        }
        while (str[iter] >= '0' && str[iter] <= '9') {
            res = res * 10 + (str[iter] - '0');
            if (symbol == 1 && res > INT_MAX) return INT_MAX;
            if (symbol == -1 && res * -1 < INT_MIN) return INT_MIN;
            ++iter;
        }
        return res * symbol;
    }
};

int main() {
    Solution solution;
    cout << solution.atoi("55868") << endl;
    cout << solution.atoi("-00035") << endl;
    cout << solution.atoi("   456") << endl;
    cout << solution.atoi("  -23456xx") << endl;
    cout << solution.atoi(" x -23456xx") << endl;
    cout << solution.atoi("-2147483648") << endl;
    return 0;
}
