/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > ans;
    int sn, sk;
    void search(int start, int level, vector<int>& vec) {
        if (level > sk) {
            ans.push_back(vec);
            return;
        }
        for (int i = start; i <= sn; ++i) {
            vec.push_back(i);
            search(i + 1, level + 1, vec);
            vec.erase(--vec.end());
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        if (k == 0) return ans;
        sn = n;
        sk = k;
        vector<int> vec;
        search(1, 1, vec);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > vec = solution.combine(4, 3);
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
