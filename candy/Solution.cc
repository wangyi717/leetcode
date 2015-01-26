/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        cout << "N: " << n << endl;
        if (n == 0) return 0;
        int min = 0;
        int sum = 1;
        int dec = 0;
        int pre = 1;
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                sum += ++pre;
            }
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                pre = 1;
            }
            if (ratings[i] < ratings[i - 1]) {
                dec = 0;
                while (ratings[i] < ratings[i - 1] && i < n) {
                    ++dec;
                    ++i;
                }
                cout << "Dec: " << dec << endl;
                if (dec < pre) {
                    sum += (1 + dec) * dec / 2;
                } else {
                    sum += (1 + dec) * dec / 2 - pre + 1 + dec;
                }
                pre = 1;
                --i;
            }
            cout << "Pre: " << pre << ", Sum: " << sum << endl;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    cout << "Sum: " << solution.candy(vec) << endl;
    return 0;
}
