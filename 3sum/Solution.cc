/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ans;
        if (num.size() < 3) return ans;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; ++i) {
            while (i > 0 && i < num.size() - 2 && num[i] == num[i - 1])
                ++i;
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    vector<int> vec;
                    vec.push_back(num[i]);
                    vec.push_back(num[j]);
                    vec.push_back(num[k]);
                    ans.push_back(vec);
		            while (num[k - 1] == num[k] && j < k)
		                --k;
		            --k;
		            while (num[j + 1] == num[j] && j < k)
		                ++j;
		            ++j;
                } else if (sum < 0)
                    ++j;
                else
                    --k;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(-1);
    vec.push_back(-4);
    Solution solution;
    vector<vector<int> > ans = solution.threeSum(vec);
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
