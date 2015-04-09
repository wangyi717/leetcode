/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
private:
    bool isOneCharDiff(const string& s1, const string& s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i])
                ++diff;
            if (diff > 1)
                return false;
        }
        return diff == 1;
    }
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == "") return 1;
        unordered_set<string> set = dict;
        unordered_map<string, int> map;
        queue<string> q;
        q.push(start);
        map[start] = 1;
        set.erase(start);
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            auto iter = set.begin();
            while (iter != set.end()) {
                string word = *iter;
                if (isOneCharDiff(current, word)) {
                    map[word] = map[current] + 1;
                    if (word == end)
                        return map[word];
                    iter = set.erase(iter);
                    q.push(word);
                } else {
                    ++iter;
                }
            }
        }
        return 0;
    }
};
