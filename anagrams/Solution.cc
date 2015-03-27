/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        map<string, vector<string>> mp;
        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(s);
        }
        for (auto mItem : mp) {
            if (mItem.second.size() > 1)
                res.insert(res.end(), mItem.second.begin(), mItem.second.end());
        }
        return res;
    }
};
