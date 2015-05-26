/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> matrix(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i)
            matrix[prerequisites[i].second].insert(prerequisites[i].first);

        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
            for (auto it = matrix[i].begin(); it != matrix[i].end(); ++it)
                ++inDegree[*it];
        for (int j = 0; j < numCourses; ++j) {
            int i = 0;
            for (i = 0; i < numCourses && inDegree[i] != 0; ++i);
            if (i == numCourses) return false;
            inDegree[i] = -1;
            for (auto it = matrix[i].begin(); it != matrix[i].end(); ++it)
                --inDegree[*it];
        }
        return true;
    }
};
