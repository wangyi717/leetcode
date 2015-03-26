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
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res = {{}};
        sort(S.begin(), S.end());
        int i = 0;
        while (i < S.size()) {
            int count = 0;
            while (count + i < S.size() && S[count + i] == S[i])
                ++count;
            int size = res.size();
            for (int j = 0; j < size; ++j) {
                vector<int> vec = res[j];
                for (int k = 0; k < count; ++k) {
                    vec.push_back(S[i]);
                    res.push_back(vec);
                }
            }
            i += count;
        }
        return res;
    }
};
