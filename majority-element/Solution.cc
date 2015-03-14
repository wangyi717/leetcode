/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num.size();
        if (n <= 2) return num[0];
        int result = num[0];
        int times = 1;
        for (int i = 1; i < n; ++i) {
            if (times == 0) {
                result = num[i];
                ++times;
            } else if (result == num[i])
                ++times;
            else
                --times;
        }
        return result;
    }
};

int main() {
    int A[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
	int B[] = {-2147483648,0,0};
    vector<int> num;
    for (int i = 0; i < 3; ++i) {
        num.push_back(B[i]);
    }
    Solution solution;
    cout << "Result: " << solution.majorityElement(num) << endl;
    return 0;
}
