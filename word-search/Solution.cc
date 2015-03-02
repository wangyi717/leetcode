/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<char> > dict;
    vector<vector<int> > visit;
    int m, n;
    bool search(int x, int y, string word, int n) {
        if (x < dict.size() && y < dict[x].size() && dict[x][y] == word[n]) {
            if (n == word.size() - 1) {
                return true;
            } else {
                bool up = false, down = false, left = false, right = false;
                if (x - 1 >= 0 && visit[x - 1][y] == 0) {
                    visit[x - 1][y] = 1;
                    up = search(x - 1, y, word, n + 1);
                    visit[x - 1][y] = 0;
                }
                if (up) return true;
                if (x + 1 < dict.size() && visit[x + 1][y] == 0) {
                    visit[x + 1][y] = 1;
                    down = search(x + 1, y, word, n + 1);
                    visit[x + 1][y] = 0;
                }
                if (down) return true;
                if (y - 1 >= 0 && visit[x][y - 1] == 0) {
                    visit[x][y - 1] = 1;
                    left = search(x, y - 1, word, n + 1);
                    visit[x][y - 1] = 0;
                }
                if (left) return true;
                if (y + 1 < dict[x].size() && visit[x][y + 1] == 0) {
                    visit[x][y + 1] = 1;
                    right = search(x, y + 1, word, n + 1);
                    visit[x][y + 1] = 0;
                }
                if (right) return true;
                return false;
            }
        } else {
            return false;
        }
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        dict = board;
        for (int i = 0; i < board.size(); ++i) {
            vector<int> subVisit(board[i].size(), 0);
            visit.push_back(subVisit);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                visit[i][j] = 1;
                bool flag = search(i, j, word, 0);
                visit[i][j] = 0;
                if (flag) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<char> > board;
    vector<char> v1;
    vector<char> v2;
    vector<char> v3;
    v1.push_back('A');
    v1.push_back('B');
    v1.push_back('C');
    v1.push_back('D');
    v2.push_back('E');
    v2.push_back('A');
    v2.push_back('D');
    v2.push_back('C');
    v3.push_back('F');
    v3.push_back('E');
    v3.push_back('B');
    v3.push_back('A');
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
    cout << "Result: " << solution.exist(board, "ABADC") << endl;
    return 0;
}
