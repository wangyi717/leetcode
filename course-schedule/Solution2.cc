/**
 * Solution2.cc
 * Using DFS to detect if there is a cycle
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    bool dfs(vector<unordered_set<int>>& matrix, vector<int>& colors, int i) {
        colors[i] = 1;
        for (auto it = matrix[i].begin(); it != matrix[i].end(); ++it) {
            if (colors[*it] == 1 || dfs(matrix, colors, *it))
                return true;
        }
        colors[i] = -1;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> matrix(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i)
            matrix[prerequisites[i].second].insert(prerequisites[i].first);
        vector<int> colors(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            if (colors[i] == 0)
                if (dfs(matrix, colors, i))
                    return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<pair<int, int>> pres;
    pair<int, int> a(0, 1);
    pres.push_back(a);
    bool flag = solution.canFinish(2, pres);
    if (flag) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    return 0;
}
