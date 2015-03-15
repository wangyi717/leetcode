/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            switch (s[i]) {
                case 'M':
                    num += 1000;
                    break;
                case 'D':
                    num += 500;
                    break;
                case 'C':
                    num += 100 * (num >= 500 ? -1 : 1);
                    break;
                case 'L':
                    num += 50;
                    break;
                case 'X':
                    num += 10 * (num >= 50 ? -1 : 1);
                    break;
                case 'V':
                    num += 5;
                    break;
                case 'I':
                    num += 1 * (num >= 5 ? -1 : 1);
                    break;
            }
        }
        return num;
    }
};
