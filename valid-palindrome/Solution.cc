/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com.cn>
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0 && s.size() == 1) return true;
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            while (i < s.size() && (s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z')) ++i;
            while (j >= 0 && (s[j] < '0' || (s[i] > '9' && s[j] < 'A') || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')) --j;
            if (i >= j) break;
            if (s[i] != s[j] && s[i] != s[j] + 32 && s[i] != s[j] - 32) return false;
        }
        return true;
    }
};

int main() {
    string s1 = "";
    string s2 = "a";
    string s3 = "A man, a plan, a canal: Panama";
    string s4 = "race a car";
    string s5 = ".,";
    Solution solution;
    cout << "S1: " << solution.isPalindrome(s1) << endl;
    cout << "S2: " << solution.isPalindrome(s2) << endl;
    cout << "S3: " << solution.isPalindrome(s3) << endl;
    cout << "S4: " << solution.isPalindrome(s4) << endl;
    cout << "S5: " << solution.isPalindrome(s5) << endl;
    return 0;
}
