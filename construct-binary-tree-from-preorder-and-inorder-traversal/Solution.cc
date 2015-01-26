/**
 * Solution.cc
 * @author 王毅 <wangyi717@gmail.com>
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int total;
    TreeNode* build(int prePos, int start, int end, vector<int> &preorder, vector<int> &inorder) {
        if (prePos > total - 1 || start > end) return NULL;
        TreeNode* node = new TreeNode(preorder[prePos]);
        int pos = 0;
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left = build(prePos + 1, start, pos - 1,  preorder, inorder);
        node->right = build(prePos + pos - start + 1, pos + 1, end, preorder, inorder);
        return node;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        total = preorder.size();
        if (total == 0) return NULL;
        return build(0, 0, total - 1, preorder, inorder);
    }
};

void traverse(TreeNode* node) {
    cout << node->val << endl;
    if (node->left != NULL) {
        traverse(node->left);
    }
    if (node->right != NULL) {
        traverse(node->right);
    }
}

int main() {
    vector<int> pre, in;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(5);
    pre.push_back(3);
    pre.push_back(6);
    in.push_back(4);
    in.push_back(2);
    in.push_back(5);
    in.push_back(1);
    in.push_back(3);
    in.push_back(6);
    Solution solution;
    TreeNode* root = solution.buildTree(pre, in);
    traverse(root);
    return 0;
}
