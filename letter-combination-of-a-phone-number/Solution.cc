/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> list;
        list.push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> temp;
            string map = charmap[digits[i] - '0'];
            for (int j = 0; j < map.size(); ++j) {
                for (int k = 0; k < list.size(); ++k) {
                    temp.push_back(list[k] + map[j]);
                }
            }
			list = temp;
        }
        return list;
    }
};
