/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool traverse(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        else if (p == NULL && q != NULL) return false;
        else if (p != NULL && q == NULL) return false;
		else if (p->val != q->val) return false;
        return traverse(p->left, q->right) && traverse(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return traverse(root->left, root->right);
    }
};
