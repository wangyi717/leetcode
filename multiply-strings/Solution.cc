/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if (len1 == 0 || len2 == 0) return "0";
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> res(len1 + len2, 0);
        for (int i = 0; i < len1; ++i) {
            int carry = 0;
            int n1 = num1[len1 - i - 1] - '0';
            for (int j = 0; j < len2; ++j) {
                int n2 = num2[len2 - j - 1] - '0';
                int multi = n1 * n2 + res[i + j] + carry;
                carry = multi / 10;
                res[i + j] = multi % 10;
            }
            if (carry > 0)
                res[i + len2] += carry;
        }
        int start = len1 + len2 - 1;
        while (res[start] == 0) --start;
        if (start == -1) return "0";
        string ans;
        for (int i = start; i >= 0; --i) {
            ans += (char)(res[i] + '0');
        }
        return ans;
    }
};
