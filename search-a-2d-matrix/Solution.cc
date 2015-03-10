/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        int rl = 0, rh = m - 1;
        int cl = 0, ch = n - 1;
        int rm, cm;
        while (rl <= rh) {
            rm = (rl + rh) / 2;
            if (target >= matrix[rm][0] && target <= matrix[rm][n - 1])
                break;
            if (target < matrix[rm][0]) rh = rm - 1;
            else if (target > matrix[rm][n - 1]) rl = rm + 1;
        }
        while (cl <= ch) {
            cm = (cl + ch) / 2;
            if (target == matrix[rm][cm]) return true;
            if (target < matrix[rm][cm]) ch = cm - 1;
            else if (target > matrix[rm][cm]) cl = cm + 1;
        }
        return false;
    }
};

int main() {
    vector<vector<int> > m;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    v2.push_back(10);
    v2.push_back(11);
    v2.push_back(16);
    v2.push_back(20);
    v3.push_back(23);
    v3.push_back(30);
    v3.push_back(34);
    v3.push_back(50);
    m.push_back(v1);
    m.push_back(v2);
    m.push_back(v3);
    Solution solution;
    int num = 0;
    cin >> num;
    bool flag = solution.searchMatrix(m, num);
    if (flag) {
        cout << "Number found!" << endl;
    } else {
        cout << "Number not found!" << endl;
    }
    return 0;
}
