/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        if (s.size() <= 1) return true;
        unordered_set<char> set;
        unordered_map<char, char> map;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i], d = t[i];
            if (map.find(c) != map.end()) {
                if (d != map[c])
                    return false;
            } else {
                if (set.find(d) != set.end())
                    return false;
                map[c] = d;
                set.insert(d);
            }
        }
        return true;
    }
};
