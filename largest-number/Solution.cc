/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    static bool compareTo(string s1, string s2) {
        return s1 + s2 > s2 + s1;
    }
public:
    string largestNumber(vector<int> &num) {
        vector<string> numStr;
        for (int i = 0; i < num.size(); ++i) {
            numStr.push_back(to_string(num[i]));
        }
        sort(numStr.begin(), numStr.end(), compareTo);
        string res;
        for (int i = 0; i < numStr.size(); ++i) {
            res += numStr[i];
        }
        int begin = 0;
        while (begin + 1 < res.size() && res[begin] == '0') ++begin;
        return res.substr(begin);
    }
};
