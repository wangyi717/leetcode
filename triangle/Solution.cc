/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 * DP算法, 空间复杂度O(n2)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        vector<vector<int> > f(n, vector<int>(n, 0)); 
        int ans = 65535;
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    f[i][j] = f[i - 1][j] + triangle[i][j];
                } else if (i == j) {
                    f[i][j] = f[i - 1][j - 1] + triangle[i][j];
                } else {
                    f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + triangle[i][j];
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (f[n - 1][i] < ans) {
                ans = f[n - 1][i];
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int> > vec;
    vector<int> vec1, vec2, vec3, vec4;
    vec1.push_back(2);
    vec2.push_back(3);
    vec2.push_back(4);
    vec3.push_back(6);
    vec3.push_back(5);
    vec3.push_back(7);
    vec4.push_back(4);
    vec4.push_back(1);
    vec4.push_back(8);
    vec4.push_back(3);
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);
    vec.push_back(vec4);
    Solution solution;
    cout << "Min: " << solution.minimumTotal(vec) << endl;
    return 0;
}
