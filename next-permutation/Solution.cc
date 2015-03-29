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
    void nextPermutation(vector<int> &num) {
        int i;
        for (i = num.size() - 1; i > 0; --i) {
            if (num[i] > num[i - 1]) {
                int j = i;
                while (j < num.size() && num[j] > num[i - 1])
                    ++j;
                swap(num[j - 1], num[i - 1]);
                break;
            }
        }
        sort(num.begin() + i, num.end());
    }
};

int main() {
    Solution solution;
    vector<int> num;
    num.push_back(1);
    num.push_back(3);
    num.push_back(2);
    solution.nextPermutation(num);
    for (int i = 0; i < num.size(); ++i)
        cout << num[i] << " ";
    cout << endl;
    return 0;
}
