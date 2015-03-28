/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    bool isValidLine(vector<vector<char> >& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> rowSet;
            unordered_set<char> colSet;
            for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
		            if (rowSet.find(board[i][j]) != rowSet.end()) {
		                return false;
		            } else {
		                rowSet.insert(board[i][j]);
		            }
				}
				if (board[j][i] != '.') {
		            if (colSet.find(board[j][i]) != colSet.end()) {
		                return false;
		            } else {
		                colSet.insert(board[j][i]);
		            }
				}
            }
        }
        return true;
    }
    bool isValidBlock(vector<vector<char> >& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> set;
            for (int j = i / 3 * 3; j < i / 3 * 3 + 3; ++j) {
                for (int k = i % 3 * 3; k < i % 3 * 3 + 3; ++k) {
					if (board[j][k] != '.') {
		                if (set.find(board[j][k]) != set.end()) {
		                    return false;
		                } else {
		                    set.insert(board[j][k]);
		                }
					}
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        return isValidLine(board) && isValidBlock(board);
    }
};

vector<char> stringToCharVector(string str) {
    vector<char> vec;
    for (int i = 0; i < str.size(); ++i) {
        vec.push_back(str[i]);
    }
    return vec;
}

int main() {
	vector<vector<char> > board;
	board.push_back(stringToCharVector("........."));
	board.push_back(stringToCharVector("......3.."));
	board.push_back(stringToCharVector("...18...."));
	board.push_back(stringToCharVector("...7....."));
	board.push_back(stringToCharVector("....1.97."));
	board.push_back(stringToCharVector("........."));
	board.push_back(stringToCharVector("...36.1.."));
	board.push_back(stringToCharVector("........."));
    board.push_back(stringToCharVector(".......2."));
    Solution solution;
    if (solution.isValidSudoku(board)) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
	return 0;
}
