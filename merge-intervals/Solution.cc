/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    static bool compareInterval(Interval a, Interval b) {
        return a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), compareInterval);
        Interval last = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= last.end) {
                if (intervals[i].end > last.end) {
                    Interval item(last.start, intervals[i].end);
                    last = item;
                }
            } else {
                ans.push_back(last);
                last = intervals[i];
            }
        }
        ans.push_back(last);
        return ans;
    }
};

int main() {
    vector<Interval> vec, ans;
    Interval iv1(1, 3);
    Interval iv2(2, 6);
    Interval iv3(8, 10);
    Interval iv4(15, 18);
    vec.push_back(iv1);
    vec.push_back(iv2);
    vec.push_back(iv3);
    vec.push_back(iv4);
    Solution solution;
    ans = solution.merge(vec);
    for (int i = 0; i < ans.size(); ++i) {
        cout << "[" << ans[i].start << ", " << ans[i].end << "]" << endl;
    }
    return 0;
}
