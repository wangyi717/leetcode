/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.size() == 0) { 
            vector<Interval> ans;
            ans.push_back(newInterval);
            return ans;
        }
        if (newInterval.start > intervals[intervals.size() - 1].end) {
            vector<Interval> ans(intervals);
            ans.push_back(newInterval);
            return ans;
        }
        if (newInterval.end < intervals[0].start) {
            vector<Interval> ans;
            ans.push_back(newInterval);
            for (int i = 0; i < intervals.size(); ++i) {
                ans.push_back(intervals[i]);
            }
            return ans;
        }
        vector<Interval> ans;
        int l = 0, r = intervals.size() - 1;
        for (int i = 0; i < intervals.size(); ++i, ++l) {
            if (newInterval.start < intervals[i].start) {
                break;
            }
            if (newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end) {
                l = i;
                break;
            }
        }
        for (int i = intervals.size() - 1; i >= 0; --i, --r) {
            if (newInterval.end > intervals[i].end) {
                break;
            }
            if (newInterval.end <= intervals[i].end && newInterval.end >= intervals[i].start) {
                r = i;
                break;
            }
        }
        for (int i = 0; i < l; ++i) {
            ans.push_back(intervals[i]);
        }
        int start = newInterval.start > intervals[l].start ? intervals[l].start : newInterval.start;
        int end  = newInterval.end > intervals[r].end ? newInterval.end : intervals[r].end;
        Interval range(start, end);
        ans.push_back(range);
        for (int i = r + 1; i < intervals.size(); ++i) {
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};

int main() {
    Interval it1_1(1, 3);
    Interval it1_2(6, 9);
    Interval it1_x(2, 5);
    vector<Interval> v1;
    v1.push_back(it1_1);
    v1.push_back(it1_2);
    Interval it2_1(1, 2);
    Interval it2_2(3, 5);
    Interval it2_3(6, 7);
    Interval it2_4(8, 10);
    Interval it2_5(12, 16);
    Interval it2_x(4, 9);
    vector<Interval> v2;
    v2.push_back(it2_1);
    v2.push_back(it2_2);
    v2.push_back(it2_3);
    v2.push_back(it2_4);
    v2.push_back(it2_5);
    Solution solution;
    vector<Interval> ans1 = solution.insert(v1, it1_x);
    vector<Interval> ans2 = solution.insert(v2, it2_x);
    for (int i = 0; i < ans1.size(); ++i) {
        cout << "[" << ans1[i].start << ", " << ans1[i].end << "]\t";
    }
    cout << endl;
    for (int i = 0; i < ans2.size(); ++i) {
        cout << "[" << ans2[i].start << ", " << ans2[i].end << "]\t";
    }
    cout << endl;
    return 0;
}
