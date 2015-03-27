/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <string>
#include <deque>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if (path == "") return "/";
        deque<string> dirs;
        int i = 0;
        while (i < path.size()) {
            int begin, end;
            while (i < path.size() && path[i] == '/') ++i;
            begin = i;
            while (i < path.size() && path[i] != '/') ++i;
            end = i;
            if (begin >= end) break;
            string dir = path.substr(begin, end - begin);
            if (dir == ".") continue;
            if (dir == "..") {
                if (!dirs.empty()) {
                    dirs.pop_back();
                }
            } else {
                dirs.push_back(dir);
            }
        }
        if (dirs.empty()) {
            return "/";
        } else {
            string sp;
            while (!dirs.empty()) {
                sp += "/" + dirs.front();
                dirs.pop_front();
            }
            return sp;
        }
    }
};

int main() {
    Solution solution;
    string path1 = "/home/";
    cout << "Simplified path is: " << solution.simplifyPath(path1) << endl;
    string path2 = "/a/./b/../../c/";
    cout << "Simplified path is: " << solution.simplifyPath(path2) << endl;
    string path3 = "/...";
    cout << "Simplified path is: " << solution.simplifyPath(path3) << endl;
    return 0;
}
