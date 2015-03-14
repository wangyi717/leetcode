/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool validate(TreeNode *node, TreeNode*& prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
};

int main() {
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(30);
    TreeNode* n3 = new TreeNode(10);
    TreeNode* n4 = new TreeNode(15);
    TreeNode* n5 = new TreeNode(45);
    n1->right = n2;
    n2->left = n3;
    n3->right = n4;
    n4->right = n5;
    Solution solution;
    bool flag = solution.isValidBST(n1);
    if (flag) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
