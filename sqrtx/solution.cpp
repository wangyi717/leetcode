#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int left = 0, right = x, mid;
        while (right - left > 1) {
            mid = left + (right - left) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid > x / mid) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};

int main() {
    Solution solution;
    cout << "sqrt(1) is: " << solution.sqrt(1) << endl;
    cout << "sqrt(30000) is: " << solution.sqrt(30000) << endl;
    return 0;
}
