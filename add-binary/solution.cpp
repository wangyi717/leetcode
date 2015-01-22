#include <iostream>
#include "math.h"
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string temp, sum, result = "";
        int up = 0;
        if (b.size() > a.size()) {
            temp = a;
            a = b;
            b = temp;
        }
        for (int i = 0; i < b.size(); i++) {
            int m = a.size() - 1 - i;
            int n = b.size() - 1 - i;
            if (up == 0) {
                if (a[m] == '0' && b[n] == '0') {
                    sum = "0";
                    up = 0;
                } else if (a[m] == '1' && b[n] == '1') {
                    sum = "0";
                    up = 1;
                } else {
                    sum = "1";
                    up = 0;
                }
            } else {
                if (a[m] == '0' && b[n] == '0') {
                    sum = "1";
                    up = 0;
                } else if (a[m] == '1' && b[n] == '1') {
                    sum = "1";
                    up = 1;
                } else {
                    sum = "0";
                    up = 1;
                }
            }
            result = sum + result;
        }
        for (int i = a.size() - b.size() - 1; i >= 0; i--) {
            if (up == 0) {
                sum = a[i];
            } else {
                if (a[i] == '0') {
                    sum = "1";
                    up = 0;
                } else {
                    sum = "0";
                    up = 1;
                }
            }
            result = sum + result;
        }
        if (up == 1) {
            result = "1" + result;
        }
        return result;
    }
};

int main() {
    string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101", b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    Solution solution;
    string sum = solution.addBinary(a, b);
    cout << "The sum is: " << sum << endl;
    cout << "1 1 test: " << solution.addBinary("1", "1") << endl;
    return 0;
}
