/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0, tank = 0, g = 0, c = 0;
        for (int i = 0; i < gas.size(); ++i) {
            g += gas[i];
            c += cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return g >= c ? start : -1;
    }
};

int main() {
    vector<int> gas, cost;
    gas.push_back(6);
    gas.push_back(1);
    gas.push_back(4);
    gas.push_back(3);
    gas.push_back(5);
    cost.push_back(3);
    cost.push_back(8);
    cost.push_back(2);
    cost.push_back(4);
    cost.push_back(2);
    Solution solution;
    cout << solution.canCompleteCircuit(gas, cost);
    return 0;
}
