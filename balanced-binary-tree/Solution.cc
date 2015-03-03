/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int depth(TreeNode* node) {
        if (node == NULL) return 0;
        return max(depth(node->left), depth(node->right)) + 1;
    }
public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        int left = depth(root->left);
        int right = depth(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
