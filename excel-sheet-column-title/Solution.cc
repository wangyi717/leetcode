/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string str;
        while (n != 0) {
            n--;
            char c = 'A' + n % 26;
            str = c + str;
            n /= 26;
        }
        return str;
    }
};
