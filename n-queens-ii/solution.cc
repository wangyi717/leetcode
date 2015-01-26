/**
 * n皇后问题
 * solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        count = 0;
        initBoard(n);
        cleanBoard();
        findSolution(0);
        return count;
    }
private:
    int count;
    vector<vector<int> > board;
    void initBoard(int n) {
        board.resize(n);
        for (int i = 0; i < n; ++i) {
            board[i].resize(n);
        }
    }
    void cleanBoard() {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                board[i][j] = 0;
            }
        }
    }
    void findSolution(int m) {
        for (int i = 0; i < board.size(); ++i) {
            board[m][i] = 1;
            if (check(m, i)) {
                if (m == board.size() - 1) {
                    ++count;
                } 
                if (m < board.size() - 1) {
                    findSolution(m + 1);
                }
            }
            board[m][i] = 0;
        }
    }
    bool check(int x, int y) {
        for (int i = 0; i < board.size(); ++i) {
            if (board[x][i] == 1 && y != i) {
                return false;
            }
            if (board[i][y] == 1 && x != i) {
                return false;
            }
            if (x - i >= 0 && y - i >= 0 && i != 0) {
                if (board[x - i][y - i] == 1) {
                    return false;
                }
            }
            if (x + i < board.size() && y + i < board.size() && i != 0) {
                if (board[x + i][y + i] == 1) {
                    return false;
                }
            }
            if (x - i >= 0 && y + i < board.size() && i != 0) {
                if (board[x - i][y + i] == 1) {
                    return false;
                }
            }
            if (x + i < board.size() && y - i >= 0 && i != 0) {
                if (board[x + i][y - i] == 1) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    for (int i = 1; i <= 8; ++i) {
        cout << i << " Queens: " << solution.totalNQueens(i) << endl;
    }
    return 0;
}
