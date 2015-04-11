/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> vec;
        if (start > end) {
            vec.push_back(NULL);
            return vec;
        }
        if (start == end) {
            TreeNode* leaf = new TreeNode(start);
            vec.push_back(leaf);
            return vec;
        }
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generate(start, i - 1);
            vector<TreeNode*> right = generate(i + 1, end);
            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    vec.push_back(root);
                }
            }
        }
        return vec;
    }
public:
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
};

int main() {
    Solution solution;
    solution.generateTrees(2);
    return 0;
}
